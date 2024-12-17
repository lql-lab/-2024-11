#include <iostream>
#include <opencv2/opencv.hpp>

// 全局变量用于存储图像以及处理后的图像，初始化处理后的图像尺寸和类型与原图像一致
cv::Mat g_src_img, g_dst_img;
// 分别用于存储对比度和亮度滑动条的当前值（初始化为合理值，比如50表示中等对比度和亮度）
int g_nConstract = 50;
int g_nBright = 50;

// 对比度滑动条的回调函数
static void on_Constract(int, void *);
// 亮度滑动条的回调函数
static void on_Bright(int, void *);

int main()
{
    g_src_img = cv::imread("/home/lql/Desktop/C++/test_images/传统视觉实验/images/Barbara.bmp", 1);
    if (g_src_img.empty()) {
        std::cerr << "无法读取图像文件" << std::endl;
        return -1;
    }
    // 初始化g_dst_img，使其尺寸和类型与g_src_img相同
    g_dst_img = cv::Mat(g_src_img.rows, g_src_img.cols, g_src_img.type());

    cv::namedWindow("win_name", cv::WINDOW_NORMAL);

    // 创建对比度滑动条，范围设置为0 - 100，设置对应的回调函数
    cv::createTrackbar("contrast_track", "win_name", nullptr, 100, on_Constract);
    // 创建亮度滑动条，范围设置为0 - 100，设置对应的回调函数
    cv::createTrackbar("bright_track", "win_name", nullptr, 100, on_Bright);

    // 初始化显示图像，先调用一次回调函数来设置初始的对比度和亮度效果
    on_Constract(g_nConstract, nullptr);
    on_Bright(g_nBright, nullptr);

    // 正确的等待按键退出的循环写法，每隔一定时间检查是否按下 'q' 键
    while (cv::waitKey(30)!= 'q') {}

    return 0;
}

// 对比度滑动条的回调函数
static void on_Constract(int, void *)
{
    // 获取对比度滑动条的当前值
    int current_contrast = cv::getTrackbarPos("contrast_track", "win_name");
    // 更新全局变量，用于后续在亮度回调函数以及图像更新中使用
    g_nConstract = current_contrast;
    // 遍历图像每个像素，更新像素值来改变对比度
    for (int x = 0; x < g_src_img.rows; ++x) {
        for (int y = 0; y < g_src_img.cols; ++y) {
            for (int channels = 0; channels < 3; ++channels) {
                g_dst_img.at<cv::Vec3b>(x, y)[channels] = cv::saturate_cast<uchar>((current_contrast * 0.01) * g_src_img.at<cv::Vec3b>(x, y)[channels]);
            }
        }
    }
    cv::imshow("win_name", g_dst_img);
}

// 亮度滑动条的回调函数
static void on_Bright(int, void *)
{
    // 获取亮度滑动条的当前值
    int current_bright = cv::getTrackbarPos("bright_track", "win_name");
    // 更新全局变量
    g_nBright = current_bright;
    // 遍历图像每个像素，在已经调整对比度的基础上更新像素值来改变亮度
    for (int x = 0; x < g_src_img.rows; ++x) {
        for (int y = 0; y < g_src_img.cols; ++y) {
            for (int channels = 0; channels < 3; ++channels) {
                g_dst_img.at<cv::Vec3b>(x, y)[channels] += cv::saturate_cast<uchar>(current_bright);
            }
        }
    }
    cv::imshow("win_name", g_dst_img);
}


