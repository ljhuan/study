1、常用命令：
cmake_minimum_required  // 指定cmake最低版本
project  // 指定工程名
aux_source_directory  // 自动添加目录下的源文件
include_directories  // 指定头文件的搜索路径，相当于gcc的“-I”
link_directories  // 动态或者静态链接库的搜索路径，相当于gcc的“-L”
add_subdirectory  // 包含子目录，当工程包含多个子目录的时候，此命令有用
add_executable  // 编译可执行程序
add_library  // 编译库
target_link_libraries  // 相当于gcc的“-l”

2、常用的几个内置变量
CMAKE_CXX_COMPILER // 指定C++编译器
CMAKE_CXX_FLAGS  // 指定编译选项
EXECUTABLE_OUTPUT_PATH  // 指定可执行程序的存放路径
LIBRARY_OUTPUT_PATH  // 指定库文件放置路径
