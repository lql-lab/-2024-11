# include <opencv2/opencv.hpp>

int main()
{
    cv::Mat src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000595.jpg", 1);
    // cv::Mat dst_img(src_img.cols, src_img.rows, src_img.type(), cv::Scalar(0, 0, 0));

    cv::floodFill(src_img, cv::Point(150, 350), cv::Scalar(0, 0, 0), 0, cv::Scalar(32, 30, 30), cv::Scalar(30, 30, 30));
    cv::imshow("win", src_img);

    cv::waitKey(0);
    return 0;
}