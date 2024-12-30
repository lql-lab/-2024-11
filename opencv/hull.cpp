# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img, mid_img, dst_img;
std::vector<std::vector<cv::Point>> g_counters;
std::vector<cv::Vec4i> g_vhieratchy;
cv::RNG rng(1);
int g_thresh;

void on_thres(int, void *);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000109.jpg", 1);
    cv::namedWindow("src", cv::WINDOW_NORMAL);

    cv::imshow("src", src_img);

    cv::cvtColor(src_img, mid_img, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(mid_img, mid_img, cv::Size(3, 3), 0, 0);

    cv::namedWindow("show", cv::WINDOW_NORMAL);
    cv::createTrackbar("thresh", "show", nullptr, 255, on_thres);

    on_thres(0, nullptr);

    cv::waitKey();
    return 0;
}

void on_thres(int, void *)
{
    cv::Mat proc_img;

    g_thresh = cv::getTrackbarPos("thresh", "show");

    cv::threshold(mid_img, proc_img, g_thresh, 255, cv::THRESH_BINARY);
    cv::findContours(proc_img, g_counters, g_vhieratchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point());
    
    std::vector<std::vector<cv::Point>> hull(g_counters.size());
    for (int i = 0; i < g_counters.size(); ++i)
    {
        cv::convexHull(cv::Mat(g_counters[i]), hull[i], false);
    }

    cv::Mat show = src_img.clone();
    for(int i = 0; i < g_counters.size(); ++i)
    {
        cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        cv::drawContours(show, g_counters, i, color, 1, 8, g_vhieratchy, 0, cv::Point());
        cv::drawContours(show, hull, i, color, 2, 8, std::vector<cv::Vec4i>(), 0, cv::Point());
    }

    cv::imshow("show", show);
}