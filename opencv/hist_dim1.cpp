# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>
# include <opencv2/highgui/highgui.hpp>

cv::Mat src_img, dst_img, src;
cv::MatND hist, hist1;

const int size = 256;
float range[] = {0, 255};
const float* ranges[] = {range};
int channels = 0;

void on_channel(int, void *);

int main()
{
    src = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000136.jpg", 1);
    cv::cvtColor(src, src_img, cv::COLOR_BGR2HSV);

    cv::namedWindow("src", cv::WINDOW_NORMAL);
    cv::namedWindow("dst", cv::WINDOW_NORMAL);

    cv::createTrackbar("channel", "dst", nullptr, 2, on_channel);

    on_channel(0, nullptr);

    cv::imshow("src", src);

    while (1)
    {
        int key = cv::waitKey(30);

        if (key == 'q')
        {
            break;
        }

        if (key == ' ')
        {
            std::cout << channels << std::endl;
            hist1 = hist;
        }

        if (key == 'r')
        {
            std::cout << cv::compareHist(hist, hist1, cv::HISTCMP_BHATTACHARYYA) << std::endl;
        }
    }
    return 0;
}

void on_channel(int, void *)
{
    channels = cv::getTrackbarPos("channel", "dst");
    cv::calcHist(&src_img, 1, &channels, cv::Mat(), hist, 1, &size, ranges);

    dst_img = cv::Mat(size, size, CV_8U, cv::Scalar(0));

    double min, max;
    cv::minMaxLoc(hist, &min, &max, 0, 0);

    int hpt = static_cast<int>(0.9 * size);
    for (int i = 0; i < size; ++i)
    {
        float bin_value = hist.at<float>(i);
        int real_val = static_cast<int>(bin_value * hpt / max);
        cv::rectangle(dst_img, cv::Point(i, size - 1), cv::Point(i, size - real_val), cv::Scalar(255));
    }

    cv::imshow("dst", dst_img);
}