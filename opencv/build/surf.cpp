# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img0, src_img1, dst_img;
std::vector<cv::KeyPoint> k_pt1, k_pt2;

int main()
{
    src_img0 = cv::imread("", 1);
    src_img1 = cv::imread("", 1);

    cv::namedWindow("img0", cv::WINDOW_NORMAL);
    cv::namedWindow("img1", cv::WINDOW_NORMAL);

    
}