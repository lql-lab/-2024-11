#include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img, mid_img, dst_img;
std::vector<cv::Vec4i> g_vhierarchy;
std::vector<std::vector<cv::Point>> g_counters;
int g_canny_threshold;

void on_thresh(int, void *);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000584.jpg", 1);
    cv::imshow("src", src_img);

    cv::cvtColor(src_img, mid_img, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(mid_img, mid_img, cv::Size(3, 3), 0, 0);

    cv::namedWindow("show", cv::WINDOW_NORMAL);
    cv::createTrackbar("thresh", "show", nullptr, 255, on_thresh);

    on_thresh(g_canny_threshold, nullptr);

    cv::waitKey();
    return 0;
}

void on_thresh(int, void *)
{
    g_canny_threshold = cv::getTrackbarPos("thresh", "show");

    cv::RNG rng(0);

    cv::Mat thrsh_img = mid_img.clone();

    thrsh_img = thrsh_img > g_canny_threshold;
    // cv::Canny(thrsh_img, thrsh_img, g_canny_threshold / 2, g_canny_threshold);

    cv::findContours(thrsh_img, g_counters, g_vhierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point(0, 0));
    cv::Mat show = src_img.clone();

    for (int i = 0; i < g_vhierarchy.size(); ++i)
    {
        std::cout << i << std::endl;
        cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        cv::drawContours(show, g_counters, i, color, 2, 8, g_vhierarchy, 0, cv::Point());
    }

    cv::imshow("show", show);
}