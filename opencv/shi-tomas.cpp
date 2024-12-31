# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img, gray_img;
int g_max_coner;

void on_max(int, void *);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000049.jpg", 1);
    cv::cvtColor(src_img, gray_img, cv::COLOR_BGR2GRAY);

    cv::namedWindow("src", cv::WINDOW_NORMAL);
    cv::namedWindow("show", cv::WINDOW_NORMAL);

    cv::createTrackbar("max", "show", nullptr, 500, on_max);

    on_max(0, nullptr);

    cv::waitKey();
    return 0;
}

void on_max(int, void *)
{
    g_max_coner = MAX(cv::getTrackbarPos("max", "show"), 1);
    cv::RNG rng(g_max_coner);
    cv::Mat copy = src_img.clone();

    std::vector<cv::Point2f> coners;
    cv::goodFeaturesToTrack(gray_img, coners, g_max_coner, 0.10, 10, cv::Mat(), 3, false, 0.04);

    std::cout << coners.size() << std::endl;

    for (int i = 0; i < coners.size(); ++i)
    {
        cv::circle(copy, coners[i], 4, cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)), 1, 8, 0);
    }

    cv::TermCriteria c(cv::TermCriteria::EPS + cv::TermCriteria::MAX_ITER, 40, 0.01);

    cv::cornerSubPix(gray_img, coners, cv::Size(3, 3), cv::Size(-1, -1), c);

    for (int i = 0; i < coners.size(); ++i)
    {
        std::cout << coners[i].x << " " << coners[i].y << std::endl;
    }
    
    cv::imshow("show", copy);
    cv::imshow("src", src_img);
}