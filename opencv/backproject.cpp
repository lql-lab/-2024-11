# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img, hsv_img, h_img;
int g_bins;

void on_bins(int, void *);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000081.jpg", 1);
    cv::cvtColor(src_img, hsv_img, cv::COLOR_BGR2HSV);

    cv::namedWindow("src", cv::WINDOW_NORMAL);
    cv::namedWindow("back", cv::WINDOW_NORMAL);
    cv::namedWindow("hist", cv::WINDOW_NORMAL);

    cv::imshow("src", src_img);

    h_img.create(hsv_img.size(), hsv_img.depth());
    cv::mixChannels(hsv_img, h_img, {0, 0});

    cv::createTrackbar("bins", "back", nullptr, 80, on_bins);
    on_bins(0, nullptr);

    cv::waitKey();

    return 0;
}

void on_bins(int, void *)
{
    g_bins = cv::getTrackbarPos("bins", "back");

    cv::MatND hist;
    const int size[] = {MAX(g_bins, 2)};
    float range[] = {0, 255};
    const float* ranges[] = {range};

    cv::calcHist(&h_img, 1, 0, cv::Mat(), hist, 1, size, ranges);
    cv::normalize(hist, hist, 0, 255, cv::NORM_MINMAX, -1, cv::Mat());

    cv::MatND back_project;
    cv::calcBackProject(&h_img, 1, 0, hist, back_project, ranges, 1, true);

    cv::imshow("back", back_project);

    int w = 400, h = 400;
    int bin_w = cvRound(double(w) / size[0]);
    
    cv::Mat dst_img = cv::Mat::zeros(w, h, CV_8UC3);

    for (int i = 0; i < g_bins; ++i)
    {
        cv::rectangle(dst_img, cv::Point(i * bin_w, h), cv::Point((i + 1) * bin_w, h - cvRound(hist.at<float>(i) * h / 255)), cv::Scalar(100, 125, 255), -1);
    }

    cv::imshow("hist", dst_img);
}