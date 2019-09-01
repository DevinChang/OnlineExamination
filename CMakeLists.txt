cmake_minimum_required(VERSION 3.14)
project(WritenExamination)

set(CMAKE_CXX_STANDARD 14)

#add_executable(WritenExamination "MeiTuan8_22.h" MeiTuan8_22.cpp main.cpp Yuan824.cpp "Yuan824.h" "KuaiShou825.h" KuaiShou825.cpp)
#add_executable(Ali Ali829.cpp)
#add_executable(Ali Ali830.cpp)

#add_executable(coin DateStructure/Greedy/coin.cpp)
#add_executable(LIS DateStructure/DP/LIS.cpp)
#add_executable(BG DateStructure/Graph/BinaryGraph.cpp)
add_executable(TC Tencent91.cpp)

ADD_SUBDIRECTORY(DateStructure/DP)
ADD_SUBDIRECTORY(DateStructure/Graph)

