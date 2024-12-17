# include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src_img;
    src_img = cv::imread("/home/lql/Desktop/C++/test_images/传统视觉实验/images/MPX1041_synpic19289.png", 1);
    
    cv::Mat dst_img = src_img(cv::Rect(0, 0, src_img.cols / 2, src_img.rows / 2));

    cv::imshow("aaa", dst_img);
    cv::waitKey();
    return 0;
}