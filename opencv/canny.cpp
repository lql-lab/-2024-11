# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000472.jpg", cv::IMREAD_GRAYSCALE);
    cv::imshow("src_img", src_img);
    cv::waitKey(0);
    cv::Mat dst_img;
    // cv::cvtColor(src_img, dst_img, cv::COLOR_YUV2BGR_NV12, 0); 
    cv::Canny(src_img, dst_img, 80, 160, 3);
    cv::imshow("edge", dst_img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}