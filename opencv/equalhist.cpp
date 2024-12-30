# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000260.jpg", 1);
    cv::cvtColor(src_img, src_img, cv::COLOR_BGR2GRAY);

    cv::imshow("src", src_img);
    
    cv::Mat dst_img;
    cv::equalizeHist(src_img, dst_img);

    cv::imshow("dst", dst_img);

    cv::waitKey();
    return 0;
}