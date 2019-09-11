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
add_executable(TestData testdata.cpp)
add_executable(POJ3225 POJ3225.cpp)
add_executable(POJ2559 POJ2559.cpp)
add_executable(Huawei Huaiwei94.cpp)
add_executable(Coin coin.cpp)
add_executable(Yun Yuncong95.cpp)
add_executable(POJ3169 POJ3169.cpp)
add_executable(Juren Juren96.cpp)
add_executable(Mihaoyou Mihaoyou97.cpp)
add_executable(Sougou Sougou98.cpp)
add_executable(Zijie Zijietiaodong98.cpp)
add_executable(POJ1064 POJ1064.cpp)
add_executable(POJ2456 POJ2456.cpp)
add_executable(YY YY99.cpp)
add_executable(Sanqi Sanqi910.cpp)
add_executable(Trick DateStructure/Trick/poj3061_subseq.cpp)


ADD_SUBDIRECTORY(DateStructure/DP)
ADD_SUBDIRECTORY(DateStructure/Graph)

