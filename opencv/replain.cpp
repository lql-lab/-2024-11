#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat image;  // 全局变量，用于存储图像
cv::Mat temp_image, mark;
std::vector<cv::Point> points;  // 全局变量，用于存储线条的点坐标
cv::Point previous_pt(-1, -1);
bool drawing = false;  // 新增变量，用于标记是否正在进行画线操作，初始化为false表示未开始画线

// 鼠标回调函数，用于记录鼠标操作时的点坐标
static void on_mouse(int event, int x, int y, int flags, void* userdata) 
{
    if (event == cv::EVENT_MOUSEMOVE && drawing)
    {
            cv::Point pt(x, y);
            if (previous_pt.x < 0)
            {
                previous_pt = pt;
            }
            cv::line(temp_image, previous_pt, pt, cv::Scalar(255, 255, 255), 3, 8, 0);
            cv::line(mark, previous_pt, pt, cv::Scalar(255, 255, 255), 3, 8, 0);
            previous_pt = pt;
            cv::imshow("Image for Drawing", temp_image);
    }
    else if (event == cv::EVENT_LBUTTONDOWN)
    {
        drawing = true;  // 鼠标左键按下时，标记开始画线
        previous_pt.x = x;
        previous_pt.y = y;
    }
    else if (event == cv::EVENT_LBUTTONUP)
    {
        drawing = false;  // 鼠标左键松开时，标记结束画线
    }
}

int main()
{
    // 1. 读取图片
    image = cv::imread("/home/lql/Desktop/C++/images/train2017/000000000620.jpg");  // 将"input.jpg"替换为你实际的图片路径
    if (image.empty())
    {
        std::cerr << "无法读取图片文件" << std::endl;
        return -1;
    }
    temp_image = image.clone();  // 初始化临时图像为原始图像副本
    mark = cv::Mat::zeros(image.size(), CV_8U);
    // mark = cv::Mat::ones(image.size(), CV_8U);
    // cv::rectangle(mark, cv::Rect(100, 100, 200, 200), cv::Scalar(255), -1);

    // 2. 创建窗口并设置鼠标回调函数
    cv::namedWindow("Image for Drawing", cv::WINDOW_NORMAL);
    cv::setMouseCallback("Image for Drawing", on_mouse);

    cv::Mat replain_img;

    while (1)
    {
        int key = cv::waitKey(30);
        if (key == 27)  // 按下ESC键退出程序
        {
            break;
        }
        else if (key == 'r')
        {
            cv::inpaint(temp_image, mark, replain_img, 3, cv::INPAINT_TELEA);
            cv::imshow("inplant", replain_img);
        }
        else if (key == 32)  // 按下空格键中断画线，32是空格键的ASCII码值
        {
            drawing = false;
            temp_image = image.clone();  // 恢复临时图像为原始图像副本，清除已画的线
            mark = cv::Mat::zeros(image.size(), CV_8U);
            cv::imshow("Image for Drawing", temp_image);
            cv::imshow("inplant", replain_img);
        }
    }

    return 0;
}
