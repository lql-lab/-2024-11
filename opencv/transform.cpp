# include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src_img;
    src_img = cv::imread("/home/lql/Desktop/C++/test_images/传统视觉实验/images/kodim22.png", 1);

    cv::Mat dst_img;
    cv::resize(src_img, dst_img, cv::Size(src_img.cols / 2, src_img.rows / 2));
    cv::resize(src_img, dst_img, cv::Size(), 2, 2, cv::INTER_LINEAR);
    cv::imshow("aaa", dst_img);
    cv::waitKey();
    return 0;
}