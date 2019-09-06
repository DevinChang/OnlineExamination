//
// Created by devinchang on 2019/9/6.
//

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_V = 9999;
// 定点数
int V;
// d[u][v]表示边e=(u, v)的权值
int d[MAX_V][MAX_V];


void warshall_floyd(){
    for(int k = 0; k < V; ++k){
        for(int i = 0; i < V; ++i){
            for(int j = 0; j < V; ++j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}


