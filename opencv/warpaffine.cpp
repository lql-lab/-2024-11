# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img, mid_img, dst_img;
double g_angel;

void on_rotate(int, void *);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000520.jpg", 0);
    dst_img = cv::Mat::zeros(src_img.rows, src_img.cols, src_img.type());
    cv::imshow("src", src_img);

    cv::namedWindow("show", cv::WINDOW_NORMAL);
    cv::createTrackbar("angel", "show", nullptr, 360, on_rotate);

    cv::Point2f src_point[3];
    cv::Point2f dst_point[3];

    cv::Mat warp(2, 3, CV_32FC1);
    cv::Mat rotate(2, 3, CV_32FC1);

    src_point[0] = cv::Point(0, 0);
    src_point[1] = cv::Point(static_cast<float>(src_img.cols - 1), 0);
    src_point[2] = cv::Point(0, static_cast<float>(src_img.rows - 1));

    dst_point[0] = cv::Point(static_cast<float>(src_img.cols * 0.0), static_cast<float>(src_img.rows * 0.2));
    dst_point[1] = cv::Point(static_cast<float>(src_img.cols * 0.65), static_cast<float>(src_img.rows * 0.35));
    dst_point[2] = cv::Point(static_cast<float>(src_img.cols * 0.15), static_cast<float>(src_img.rows * 0.6));

    warp = cv::getAffineTransform(src_point, dst_point);
    cv::warpAffine(src_img, dst_img, warp, src_img.size());

    on_rotate(g_angel, nullptr);

    cv::waitKey();

    return 0;
}

void on_rotate(int, void *)
{
    g_angel = cv::getTrackbarPos("angel", "show");

    cv::Mat dst_copy = dst_img.clone();

    cv::Point center(dst_img.cols / 2, dst_img.rows / 2);
    
    cv::Mat rorate = cv::getRotationMatrix2D(center, g_angel, 1.0);

    cv::equalizeHist(dst_copy, dst_copy);

    cv::warpAffine(dst_copy, dst_copy, rorate, dst_img.size());

    cv::imshow("show", dst_copy);
}