//
// Created by devinchang on 2019/9/2.
//
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


const int MAX_V = 10000;
const int MAX_E = 10000;
const int INF = 9999999;

int const[MAX_V][MAX_V];
int d[MAX_V];
bool used[MAX_V];
int V;

void dijkstra(int s){
    fill(d, d + V, INF);
    fill(used, used+V, false);
    d[s] = 0;

    while(true){
        int v = -1;
        // 从尚未使用的定点选择一个距离最小的定点
        for(int u = 0; u < V; u++){
            if(!used[u] && (v == -1 || d[u] < d[v]))
                v = u;
        }
        // 全部选用过
        if(v == -1)
            break;
        used[v] = true;
        // 更新每条边的权重
        for(int u = 0; u < V; ++u){
            d[u] = min(d[u], d[v] + cost[v][u]);
        }
    }
}

