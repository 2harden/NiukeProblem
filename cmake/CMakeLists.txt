cmake_minimum_required(VERSION 3.10)

# set the project name
project(HelloWorld)

# 关联子文件夹
add_subdirectory(src bin)

# 安装文件
# install(FILES COPYRIGHT README DEFINITIONS share/doc/cmake)

# 安装脚本
# install(CMAKE_MAKE_PROGRAM run.sh DESTNATION bin)

# 安装目录
# INSTALL(DIRECTORY doc/ DESTINATION share/doc/cmake)

