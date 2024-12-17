# include <opencv2/opencv.hpp>

# define xl 100
# define yl 100
# define alpha 0.5

int main()
{    
    double byte = 1 - alpha;
    cv::Mat srcimg = cv::imread("address");
    cv::Mat logo_img = cv::imread("address");
    // cv::Mat mask = cv::imread("address", 0);
    cv::Mat mask;    
    cv::Mat dst_img;

    cv::Mat ROI_img = srcimg(cv::Rect(xl, yl, srcimg.cols, srcimg.rows));
    cv::cvtColor(srcimg.clone(), mask, cv::COLOR_BGR2GRAY);
 
    // logo_img.copyTo(ROI_img, mask);

    cv::addWeighted(ROI_img, alpha, logo_img, byte, 0.0, dst_img);

    cv::namedWindow("window_name", cv::WINDOW_NORMAL);
    cv::imshow("window_name", dst_img);
    
    cv::waitKey();
    return 0;
}