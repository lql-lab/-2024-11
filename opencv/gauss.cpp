# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src_img;
    src_img = cv::imread("/home/lql/Desktop/C++/test_images/传统视觉实验/images/LenaRGB.bmp", 1);
    cv::GaussianBlur(src_img, src_img, cv::Size(31, 31), 0.1);

    cv::imshow("aaa", src_img);
    cv::waitKey();
    return 0;
}