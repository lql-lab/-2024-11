# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>

int main()
{
    cv::Mat src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000625.jpg", 1);
    cv::Mat up_img, down_img;

    cv::namedWindow("src", cv::WINDOW_NORMAL);
    cv::imshow("src", src_img);

    cv::pyrUp(src_img, up_img, cv::Size(src_img.cols * 2, src_img.rows * 2));
    cv::pyrDown(src_img, down_img, cv::Size(src_img.cols / 2, src_img.rows / 2));

    cv::imshow("up", up_img);
    cv::imshow("down", down_img);

    cv::waitKey();
    return 0;
}