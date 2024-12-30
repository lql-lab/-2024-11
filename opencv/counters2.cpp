# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img, mid_img, dst_img;
std::vector<std::vector<cv::Point>> counters;
std::vector<cv::Vec4i> vhierartchy;
cv::RNG rng(123);
int thresh;

void on_thresh(int, void *);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000349.jpg", 1);
    cv::namedWindow("src", cv::WINDOW_NORMAL);
    cv::namedWindow("show", cv::WINDOW_NORMAL);

    cv::imshow("src", src_img);

    cv::cvtColor(src_img, mid_img, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(mid_img, mid_img, cv::Size(3, 3), 0, 0);

    cv::createTrackbar("thresh", "show", nullptr, 255, on_thresh);

    on_thresh(0, nullptr);

    cv::waitKey();
    return 0;
}

void on_thresh(int, void *)
{
    cv::Mat proc_img, show = src_img.clone();
    thresh = cv::getTrackbarPos("thresh", "show");

    cv::threshold(mid_img, proc_img, thresh, 255, cv::THRESH_BINARY);
    cv::findContours(proc_img, counters, vhierartchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE, cv::Point());

    std::vector<cv::Moments> mu(counters.size());
    for (int i = 0; i < counters.size(); ++i)
    {
        mu[i] = cv::moments(counters[i], false);
    }
    std::vector<cv::Point2f> mc(counters.size());
    for (int i = 0; i < counters.size(); ++i)
    {
        mc[i] = cv::Point2f(static_cast<float>(mu[i].m10/mu[i].m00), static_cast<float>(mu[i].m01/mu[i].m00));
    }
    for (int i = 0; i < counters.size(); ++i)
    {
        std::cout << "area mu: " << mu[i].m00 << std::endl;
        std::cout << "area cv: " << cv::contourArea(counters[i], false) << std::endl;
        std::cout << "length : " << cv::arcLength(counters[i], true) << std::endl;

        cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        cv::drawContours(show, counters, i, color, 1, 8, vhierartchy, 0, cv::Point());
        cv::circle(show, mc[i], 4, color, -1, 8, 0);
    }

    cv::imshow("show", show);
}