# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000009.jpg", 1);
    cv::imshow("src",src_img);
    cv::waitKey(0);
    cv::Mat erode_kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(15, 15), cv::Point(-1, -1));
    cv::Mat dst_img = cv::Mat::zeros(src_img.size(), src_img.type());
    cv::erode(src_img, dst_img, erode_kernel, cv::Point(-1, -1), 1, cv::BORDER_CONSTANT);
    // 运行次数， 边缘处理类型：常数填充。
    cv::imshow("dst_img", dst_img);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}