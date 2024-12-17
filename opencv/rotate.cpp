# include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src_img;
    src_img = cv::imread("/home/lql/Desktop/C++/test_images/传统视觉实验/images/kodim23.png", 1);

    cv::rotate(src_img, src_img, cv::ROTATE_180);
    cv::imshow("aaa", src_img);
    cv::waitKey();
}