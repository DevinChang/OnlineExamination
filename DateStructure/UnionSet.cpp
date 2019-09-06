//
// Created by devinchang on 2019/9/6.
//

#include <iostream>
#include <algorithm>
using namespace std;


const int MAX_N = 10000;

// 父亲
int par[MAX_N];
// 树的高度
int rank[MAX_N];

void unionInit(int n){
    for(int i = 0; i < n; ++i){
        par[i] = i;
        rank[i] = 0;
    }
}


// 查询树的根
int unionFind(int x){
    if(par[x] == x)
        return x;
    else{
        return pax[x] = find(par[x]);
    }
}

// 合并x和y所属的集合
void unionUnite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)
        return;
    if(rank[x] < rank[y]){
        par[x] = y;
    }
    else{
        par[y] = x;
        if(rank[x] == rank[y])
            rank[x]++;
    }
}

bool unionSame(int x, int y){
    return unionFind(x) == unionFind(y);
}
