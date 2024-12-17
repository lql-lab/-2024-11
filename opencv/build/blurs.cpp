# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img, dst_blur, dst_gauss, dst_median, dst_bilateralFilter;
int gauss_size, blur_size, median_realm, bilateralFilter_reaml;

void on_gauss(int , void *);
void on_blur(int , void *);
void on_median(int , void *);
void on_bilateralFilter(int , void *);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000074.jpg", 1);
    dst_blur = src_img.clone();
    dst_gauss = src_img.clone();
    dst_median = src_img.clone();
    dst_bilateralFilter = src_img.clone();

    cv::namedWindow("show_img", cv::WINDOW_NORMAL);

    cv::createTrackbar("blur", "show_img", nullptr, 50, on_blur);
    cv::createTrackbar("gauss", "show_img", nullptr, 25, on_gauss);
    cv::createTrackbar("median", "show_img", nullptr, 25, on_median);
    cv::createTrackbar("bilateralFilter", "show_img", nullptr, 100, on_bilateralFilter);
    
    on_gauss(gauss_size, nullptr);
    on_blur(blur_size, nullptr);
    on_median(median_realm, nullptr);
    on_bilateralFilter(bilateralFilter_reaml, nullptr);

    while (cv::waitKey(0) != 'q') {}
    return 0;
}

void on_blur(int , void *)
{
    int temp = cv::getTrackbarPos("blur", "show_img");
    blur_size = temp;

    cv::blur(src_img, dst_blur, cv::Size(blur_size + 1, blur_size + 1));
    cv::imshow("show_img", dst_blur);
}

void on_gauss(int, void *)
{
    int temp = cv::getTrackbarPos("gauss", "show_img");
    gauss_size = temp;

    cv::GaussianBlur(src_img, dst_gauss, cv::Size(2 * gauss_size + 1, 2 * gauss_size + 1), 0);
    cv::imshow("show_img", dst_gauss);
}

void on_median(int , void *)
{
    int temp = cv::getTrackbarPos("median", "show_img");
    median_realm = temp;

    cv::medianBlur(src_img, dst_median, 2 * median_realm + 1);
    cv::imshow("show_img", dst_median);
}

void on_bilateralFilter(int , void *)
{
    int temp = cv::getTrackbarPos("bilateralFilter", "show_img");
    bilateralFilter_reaml = temp;

    cv::bilateralFilter(src_img, dst_bilateralFilter, bilateralFilter_reaml, bilateralFilter_reaml, bilateralFilter_reaml);
    cv::imshow("show_img", dst_bilateralFilter);
}