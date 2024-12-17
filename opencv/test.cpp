# include <opencv2/opencv.hpp>

int main()
{
    cv::VideoCapture cap(0);
    cv::Mat frame;

    while (1)
    {
        cap.read(frame);
        cv::imshow("aaa",frame);
        if (cv::waitKey(30) == 'q')
        {
            break;
        }
    }
    
    cap.release();
    return 0;
}