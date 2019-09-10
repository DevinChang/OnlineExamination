//
// Created by devinchang on 2019/9/9.
//
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
int x[MAXN];
int N, M;

int C(int d){
    int last = 0;
    // 第一头牛肯定要放到x1位置上的,故从第二间房子开始判断
    for(int i = 1; i < M; i++){
        int crt = last + 1;
        while(crt < N && x[crt] - x[last] < d){
            crt++;
        }
        if(crt == N)
            return false;
        last = crt;
    }
    return true;
}


int main(){
    freopen("/home/devinchang/Code/WritenExamination/TestCase/poj2456.txt", "r",stdin);
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%d", &x[i]);
    }
    sort(x, x+N);

    int lb = 0, ub = MAXN;
    while(ub - lb > 1){
        int mid = (ub + lb) / 2;
        if(C(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%d\n", lb);
    return 0;
}

