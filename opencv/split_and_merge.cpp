# include <opencv2/opencv.hpp>
# include <vector>

# define alpha 0.5
# define byte 1.0
# define x 100
# define y 100
# define w 50
# define h 50

int main()
{
    std::vector<cv::Mat> channels;
    cv::Mat src_img = cv::imread("address", 1);
    cv::Mat src_b, src_g, src_r;
    cv::Mat dst_img;
    
    cv::split(src_img, channels);
    src_b = channels[0];
    src_g = channels[1];
    src_r = channels[2];
    
    cv::addWeighted(src_b(cv::Rect(x, y, w, h)), alpha, src_img(cv::Rect(x, y, w, h)), byte, 0.0, src_b);
    
    cv::merge(channels, dst_img);

    cv::namedWindow("window_name", cv::WINDOW_NORMAL);
    cv::imshow("window_name", dst_img);
    
    cv::waitKey();
    return 0;
}