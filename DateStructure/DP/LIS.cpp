//
// Created by devinchang on 2019/8/31.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000001;
const int MAX_N = 1000;

int dp[MAX_N];
int n;
vector<int> a;


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        int tmp;
        scanf("%d", &tmp);
        a.push_back(tmp);
    }
    fill(dp, dp+n, INF);
    for(int i = 0; i < n; ++i){
        *lower_bound(dp, dp+n, a[i]) = a[i];
    }
    printf("%d\n", lower_bound(dp, dp+n, INF) - dp);
    return 0;
}

