# 设置最低CMake版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目名称
project(opencv)

# 查找OpenCV库，REQUIRED表示如果没找到则停止配置并报错
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# 设置C++标准为C++11（你可以根据实际需求修改版本）
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加可执行文件目标，此处假设源文件为main.cpp，你可以根据实际添加更多源文件
add_executable(try_cap try.cpp)
add_executable(erode_make erode.cpp)
add_executable(blur blur.cpp)
add_executable(canny canny.cpp)
add_executable(test test.cpp)
add_executable(transform transform.cpp)
add_executable(rotate rotate.cpp)
add_executable(roi roi_image.cpp)
add_executable(gauss gauss.cpp)
add_executable(constract_bright constract_bright.cpp)
add_executable(blurs blurs.cpp)
add_executable(morph dilate_erode.cpp)
add_executable(fooldfill fooldfill.cpp)
add_executable(pyr pyrup_down.cpp)

# 所有需要链接的文件。
set(EXECUTABLE_NAMES try_cap erode_make blur canny test transform rotate roi gauss constract_bright blurs morph
    fooldfill pyr)

# 将OpenCV库链接到可执行文件目标上
foreach(executable_name ${EXECUTABLE_NAMES})
    target_link_libraries(${executable_name} ${OpenCV_LIBS})
endforeach(executable_name ${EXECUTABLE_NAMES})

# target_link_libraries(try_cap ${OpenCV_LIBS})
# target_link_libraries(erode_make ${OpenCV_LIBS})
# target_link_libraries(blur ${OpenCV_LIBS})

# （可选）添加自定义头文件包含路径，如果你的项目有自定义头文件目录
# include_directories(include)
# 这里的"include"是相对CMakeLists.txt文件所在目录的路径，你可以替换为实际的头文件目录路径，
# 例如：include_directories(/home/user/your_project/include)
