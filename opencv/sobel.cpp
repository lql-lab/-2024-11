# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat g_src_img, g_gray_src, g_dst_img;

cv::Mat g_canny_edge;
int g_canny_threshold;

cv::Mat g_sobel_x, g_sobel_y;
int g_sobel_size;

cv::Mat g_scharr_x, g_scharr_y;

void on_sobel(int, void *);
void on_canny(int, void *);
void scharr();

int main()
{
    g_src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000143.jpg", 1);
    cv::cvtColor(g_src_img, g_gray_src, cv::COLOR_BGR2GRAY);

    cv::imshow("src", g_src_img);
    g_dst_img.create(g_src_img.size(), g_src_img.type());

    cv::namedWindow("canny", cv::WINDOW_NORMAL);
    cv::namedWindow("sobel", cv::WINDOW_NORMAL);

    cv::createTrackbar("threshold", "canny", nullptr, 60, on_canny);
    cv::createTrackbar("size", "sobel", nullptr, 3, on_sobel);

    on_canny(g_canny_threshold, nullptr);
    on_sobel(g_sobel_size, nullptr);

    scharr();

    while(cv::waitKey(0) != 'q') {}

    return 0;
}

void on_canny(int, void *)
{
    g_canny_threshold = cv::getTrackbarPos("threshold", "canny");
    cv::GaussianBlur(g_gray_src, g_canny_edge, cv::Size(3, 3), 0);

    cv::Canny(g_canny_edge, g_canny_edge, g_canny_threshold, g_canny_threshold * 2, 3);

    g_dst_img = cv::Scalar::all(0);

    g_src_img.copyTo(g_dst_img, g_canny_edge);

    cv::imshow("canny", g_dst_img);
}

void on_sobel(int, void *)
{
    g_sobel_size = cv::getTrackbarPos("size", "sobel");

    cv::Sobel(g_gray_src, g_sobel_x, -1, 1, 0, g_sobel_size * 2 + 1, 1, 0);
    cv::convertScaleAbs(g_sobel_x, g_sobel_x);

    cv::Sobel(g_gray_src, g_sobel_y, -1, 0, 1, g_sobel_size * 2 + 1, 1, 0);
    cv::convertScaleAbs(g_sobel_y, g_sobel_y);

    cv::addWeighted(g_sobel_x, 0.5, g_sobel_y, 0.5, 0, g_dst_img);

    cv::imshow("sobel", g_dst_img);
}

void scharr()
{
    cv::Scharr(g_gray_src, g_scharr_x, -1, 1, 0, 1, 0);
    cv::convertScaleAbs(g_scharr_x, g_scharr_x);

    cv::Scharr(g_gray_src, g_scharr_y, -1, 0, 1, 1, 0);
    cv::convertScaleAbs(g_scharr_y, g_scharr_y);

    cv::addWeighted(g_scharr_x, 0.5, g_scharr_y, 0.5, 0, g_dst_img);

    cv::imshow("scharr", g_dst_img);
}