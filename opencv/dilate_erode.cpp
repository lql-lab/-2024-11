# include <opencv2/opencv.hpp>

int g_iterations;
cv::Mat src_img, dst_erode, dst_dilate;

void on_erode(int , void *);
void on_dilate(int , void *);
cv::Mat erode = (cv::Mat_<u_char>(3, 3) << 0, 1, 0, 1, 1, 1, 0, 1, 0), 
        dilate = (cv::Mat_<u_char>(3, 3) << 0, 1, 0, 1, 1, 1, 0, 1, 0);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000359.jpg", 0);
    dst_dilate = src_img.clone();
    dst_erode = src_img.clone();



    cv::namedWindow("show_img", cv::WINDOW_NORMAL);
    cv::createTrackbar("erode", "show_img", nullptr, 10, on_erode);
    cv::createTrackbar("dilate", "show_img", nullptr, 10, on_dilate);

    on_erode(g_iterations, nullptr);
    on_dilate(g_iterations, nullptr);

    while(cv::waitKey(0) != 'q') {}
    return 0;
}

void on_erode(int , void *)
{
    int temp = cv::getTrackbarPos("erode", "show_img");
    g_iterations = temp;

    cv::erode(src_img, dst_erode, erode, cv::Point(-1, -1), g_iterations);
    cv::imshow("show_img", dst_erode);
}

void on_dilate(int, void *)
{
    int temp = cv::getTrackbarPos("dilate", "show_img");
    g_iterations = temp;
    
    cv::dilate(src_img, dst_dilate, dilate, cv::Point(-1, -1), g_iterations);
    cv::imshow("show_img", dst_dilate);
}