# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img, dst_img, gray_img;
cv::RNG rng;
int g_thresh;

void on_thresh(int, void *);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000247.jpg", 1);
    cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);

    cv::namedWindow("src_img", cv::WINDOW_NORMAL);
    cv::namedWindow("show", cv::WINDOW_NORMAL);

    cv::createTrackbar("thresh", "show", nullptr, 150, on_thresh);

    on_thresh(0, nullptr);

    cv::imshow("src", src_img);
    cv::waitKey();
    return 0;
}

void on_thresh(int, void *)
{
    cv::Mat result, normal, scale_img, copy;

    dst_img = cv::Mat::zeros(src_img.size(), CV_32FC1);
    copy = src_img.clone();

    cv::cornerHarris(gray_img, dst_img, 2, 3, 0.04);

    cv::normalize(dst_img, normal, 0, 255, cv::NORM_MINMAX, -1, cv::Mat());
    cv::convertScaleAbs(normal, scale_img);
    // cv::normalize(dst_img, scale_img, 0, 255, cv::NORM_MINMAX, -1, cv::Mat());

    for (int j = 0; j < scale_img.rows; ++j)
    {
        for (int i = 0; i < scale_img.cols; ++i)
        {
            if ((int)normal.at<float>(j, i) > g_thresh + 80)
            {
                cv::circle(copy, cv::Point(i, j), 5, cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), 2, 8, 0);
                cv::circle(scale_img, cv::Point(i, j), 5, cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), 2, 8, 0);
            }
        }
    }
    cv::imshow ("show", copy);
    cv::imshow ("dst", scale_img);
}