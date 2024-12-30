# include <opencv2/opencv.hpp>
# include <opencv2/highgui/highgui.hpp>
# include <opencv2/imgproc/imgproc.hpp>

cv::Mat g_src_img, g_mid_img, g_dst_img;
int g_threshold;

void on_threshold(int, void *);

int main()
{
    g_src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000575.jpg", 1);
    cv::imshow("src", g_src_img);

    cv::namedWindow("show", cv::WINDOW_NORMAL);
    cv::createTrackbar("threshold", "show", nullptr, 200, on_threshold);

    cv::cvtColor(g_src_img, g_mid_img, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(g_mid_img, g_mid_img, cv::Size(5, 5), 2, 2);
    cv::Canny(g_mid_img, g_mid_img, 100, 200, 3);

    on_threshold(g_threshold, nullptr);

    cv::waitKey();
    return 0;
}

void on_threshold(int, void *)
{
    cv::Mat dst_img;
    dst_img = g_src_img.clone();
    g_threshold = cv::getTrackbarPos("threshold", "show");
    std::vector<cv::Vec4i> lines;
    cv::HoughLinesP(g_mid_img, lines, 1, CV_PI/180, g_threshold, 50, 10);

    for (size_t i = 0; i < lines.size(); ++i)
    {
        cv::Vec4i l = lines[i];
        cv::line(dst_img, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(50, 28, 100), 1, cv::LINE_AA);
    }
    cv::imshow("show", dst_img);
}
