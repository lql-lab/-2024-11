# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src_img, temp_img, dst_img;

    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000531.jpg", 1);
    src_img.copyTo(dst_img);

    cv::cvtColor(src_img, src_img, cv::COLOR_BGR2GRAY);
    cv::Canny(src_img, temp_img, 100, 200, 3);

    std::vector<cv::Vec2f> lines;
    cv::HoughLines(temp_img, lines, 1, CV_PI/180, 150, 0, 0);

    for (size_t i = 0; i < lines.size() ; ++i)
    {
        float rho = lines[i][0], theta = lines[i][1];
        cv::Point p1, p2;
        double a = cos(theta), b = sin(theta);
        double x0 = a * rho, y0 = b * rho;
        p1.x = cvRound(x0 + 1000 * (-b));
        p1.y = cvRound(y0 + 1000 * a);
        p2.x = cvRound(x0 - 1000 * (-b));
        p2.y = cvRound(y0 - 1000 * a);
        cv::line(dst_img, p1, p2, cv::Scalar(55, 100, 195), 1, cv::LINE_AA);
    }
    cv::imshow("src", src_img);
    cv::imshow("dst", dst_img);
    
    cv::waitKey();
    return 0;
}