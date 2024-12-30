# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src_img, temp_img, dst_img;

    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000560.jpg", 1);

    src_img.copyTo(dst_img);
    
    cv::cvtColor(src_img, src_img, cv::COLOR_BGR2GRAY);
    cv::Canny(src_img, temp_img, 50, 200, 3);

    std::vector<cv::Vec4i> lines;

    cv::HoughLinesP(temp_img, lines, 1, CV_PI/180, 80, 50, 10);

    for (size_t i = 0; i < lines.size(); ++i)
    {
        cv::Vec4i l = lines[i];
        cv::line(dst_img, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(50, 50, 0), 1, cv::LINE_AA);
    }
    
    cv::imshow("src", src_img);
    cv::imshow("dst", dst_img);
    cv::waitKey();
    return 0;
}