# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000491.jpg", 1);
    cv::imshow("src_img", src_img);
    cv::waitKey(0);
    cv::Mat dst_img;
    cv::blur(src_img, dst_img, cv::Size(7, 7), cv::Point(-1, -1), cv::BORDER_REFLECT_101);
    cv::imshow("dst_img", dst_img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}