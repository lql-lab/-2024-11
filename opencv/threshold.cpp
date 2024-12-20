# include <opencv2/opencv.hpp>
# include <opencv2/imgproc/imgproc.hpp>

cv::Mat src_img, dst_img;
int threshold, threshold_type = 0;

void on_threshold(int , void *);
void on_type(int , void *);

int main()
{
    src_img = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000508.jpg", 0);

    cv::namedWindow("show", cv::WINDOW_NORMAL);

    cv::createTrackbar("threshold", "show", nullptr, 255, on_threshold);
    cv::createTrackbar("type", "show", nullptr, 1, on_type);

    on_type(threshold_type, nullptr);
    on_threshold(threshold, nullptr);

    while(1)
    {
        int key = 0;
        key = cv::waitKey(30);
        if (key == 'q')
        {
            break;
        }
    }
    return 0;
}

void on_threshold(int , void *)
{
    int temp = cv::getTrackbarPos("threshold", "show");
    threshold = temp;

    cv::threshold(src_img, dst_img, threshold, 255, threshold_type);
    cv::imshow("show", dst_img);
}

void on_type(int , void *)
{
    threshold_type = (threshold_type + 1) % 5;
    on_threshold(threshold, nullptr);
}