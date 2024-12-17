#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::VideoCapture cap(0);
    // 检查摄像头是否成功打开
    if (!cap.isOpened()) {
        std::cerr << "无法打开摄像头" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        // 从摄像头读取一帧图像
        // cap.read(frame); 
        cap >> frame;
        // 在窗口中显示当前帧图像
        cv::imshow("摄像头画面", frame); 

        // 等待1毫秒，用于更新显示画面，同时检查是否按下了键盘上的 'q' 键（ASCII码为113）
        if (cv::waitKey(30) == 'q') {
            break;
        }
    }

    // 释放摄像头资源
    cap.release(); 
    // 关闭所有OpenCV窗口
    cv::destroyAllWindows(); 

    return 0;
}
