# include <opencv2/opencv.hpp>
# include <opencv2/highgui/highgui.hpp>
# include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000450.jpg", 1);

    cv::Mat mid_img;

    cv::cvtColor(src_img, mid_img, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(mid_img, mid_img, cv::Size(3, 3), 2, 2);

    std::vector<cv::Vec3f> circles;
    cv::HoughCircles(mid_img, circles, cv::HOUGH_GRADIENT, 1, 100, 100, 100, 0, 0);
    
    for (size_t i = 0; i < circles.size(); ++i)
    {
        cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);

        cv::circle(src_img, center, 3, cv::Scalar(0, 255, 0), -1, 8, 0);
        cv::circle(src_img, center, radius, cv::Scalar(50, 0, 255), 2, 8, 0);
    }

    cv::imshow("show", src_img);
    
    cv::waitKey();
    return 0;
}