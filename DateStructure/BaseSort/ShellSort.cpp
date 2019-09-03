//
// Created by devinchang on 2019/8/29.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;


long long cnt;
int l;
int A[1000000];
int n;
vector<int> G;

// g是希尔排序的间隔
void insertionSort(int A[], int n, int g){
    for(int i = g; i < n; ++i){
        int v = A[i];
        int j = j - g;
        while(j >= 0 && A[j] > v){
            A[j + g] = A[j];
            j -= g;
            //
            ++cnt;
        }
        // 交换,这里用j+g的原因是因为while循环退出时执行了j-=g 故需加g才能找到所需的位置
        A[j + g] = v;
    }
}

void shellSort(int A[], int n){
    // 生成间隔数列 G={1,4,13,40,121,364....}
    for(int h = 1;;){
        if(h > n)
            break;
        G.push_back(h);
        // 希尔排序的复杂度与所选择的间隔有很大关系,当间隔数列为1,4,13...即gn+1 = 3gn + 1时,
        // 希尔排序的复杂度为O(N^1.25),但如果g是2的幂指数时希尔排序的效率会大打折扣
        h = 3 * h + 1;
    }
    for(int i = G.size() - 1; i >= 0; --i){
        insertionSort(A, n, G[i]);
    }
}
