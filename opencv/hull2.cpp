# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img, mid_img, dst_img;
std::vector<std::vector<cv::Point>> counters;
std::vector<cv::Vec4i> vhierarchy;
cv::RNG rng(222);
int thresh;

void on_thresh(int, void *);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000431.jpg", 1);
    cv::namedWindow("src", cv::WINDOW_NORMAL);
    cv::namedWindow("show", cv::WINDOW_NORMAL);

    cv::imshow("src", src_img);

    cv::cvtColor(src_img, mid_img, cv::COLOR_BGR2GRAY);
    cv::blur(mid_img, mid_img, cv::Size(3, 3));

    cv::createTrackbar("thresh", "show", nullptr, 255, on_thresh);

    on_thresh(0, nullptr);

    cv::waitKey();
    return 0;
}

void on_thresh(int, void *)
{
    cv::Mat proc_img, show;
    thresh = cv::getTrackbarPos("thresh", "show");
    cv::threshold(mid_img, proc_img, thresh, 255, cv::THRESH_BINARY);

    cv::findContours(proc_img, counters, vhierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_SIMPLE);

    std::vector<std::vector<cv::Point>> poly(counters.size());
    std::vector<cv::Rect> bound_rect(counters.size());
    std::vector<cv::Point2f> center(counters.size());
    std::vector<float> radius(counters.size());

    for (int i = 0; i < counters.size(); ++i)
    {
        cv::approxPolyDP(cv::Mat(counters[i]), poly[i], 3, true);
        bound_rect[i] = cv::boundingRect(cv::Mat(poly[i]));
        cv::minEnclosingCircle(cv::Mat(poly[i]), center[i], radius[i]);
    }

    show = src_img.clone();

    for (int i = 0; i < counters.size(); ++i)
    {
        cv::Scalar color = cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
        cv::drawContours(show, poly, i, color, 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point());
        cv::rectangle(show, bound_rect[i].tl(), bound_rect[i].br(), color, 2, 8, 0);
        cv::circle(show, center[i], cvRound(radius[i]), color, 2, 8, 0);
    }

    cv::imshow("show", show);
}