# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000472.jpg", 1);
    cv::Mat gray;
    cv::cvtColor(src_img, gray, cv::COLOR_BGR2GRAY);
    cv::Mat dst_img = cv::Mat::zeros(cv::Size(src_img.cols, src_img.rows), CV_8UC3);
    cv::Mat edge;

    // cv::cvtColor(src_img, dst_img, cv::COLOR_YUV2BGR_NV12, 0); 
    cv::Canny(gray, edge, 80, 160, 3);

    src_img.copyTo(dst_img, edge);

    cv::imshow("edge", edge);
    cv::imshow("src_img", src_img);
    cv::imshow("dst_img", dst_img);    
    
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}