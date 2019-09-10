//
// Created by devinchang on 2019/9/9.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
const int INF = 100000;

int N, K;
double L[MAXN];

bool cut(double x){
    int num = 0;
    for(int i = 0; i < N; i++){
        num += (int)(L[i] / x);
    }
    return num >= K;
}

int solution(){
    double lb = 0, ub = INF;
    for(int i = 0; i < 100; i++){
        double mid = (lb + ub) / 2;
        if(cut(mid))
            lb = mid;
        else
            ub = mid;
    }
    //printf("%.2f\n", floor(ub * 100) / 100);
    ub *= 100;
    int t = (int)ub;
    printf("%d.%02d\n", t/100, t % 100);
}


int main(){
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        scanf("%lf", &L[i]);
    }
    solution();
    return 0;
}
