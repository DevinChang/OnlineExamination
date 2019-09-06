//
// Created by devinchang on 2019/9/6.
//

#include <iostream>
#include <algorithm>

const int INF = 0x7FFFFFFF;
const int MAX_V = 10000;

int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;


int prim(){
    for(int i = 0; i < V; ++i){
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;

    while(true){
        int v = -1;
        // 从不属于X的顶点中选取从X到其权值最小的定点
        for(int u = 0; u < V; ++u){
            if(!uesed[u] && (v == -1 || mincost[u] < mincost[v]))
                v = u;
        }
        if(v == -1)
            break;
        // 将顶点v加入到X
        used[v] = true;
        // 把边的长度加到结果里
        res += mincost[v];
        for(int u = 0; u < V; ++u){
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}


int main(){

    return 0;
}

