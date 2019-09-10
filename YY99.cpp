//
// Created by devinchang on 2019/9/9.
//

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <string.h>

using namespace std;


const int MAXN = 100;

int m, n;
int p[MAXN], b[MAXN];
int ret;
//int dp[MAXN][MAXN];

//void solution(int b[], int p[], int len){
void solution(vector<int> &b, vector<int> &p, vector<vector<int>> &dp, int len){
    for(int i = 1; i < len; ++i){
        for(int j = 1; j <= m; ++j){
            if(b[i] > j)
                dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j-b[i]] + p[i], dp[i-1][j]);
                ret = max(ret, dp[i][j]);
            }
        }
    }
}


int main(){
    vector<int> bb;
    vector<int> pp;
    scanf("%d%d", &m, &n);
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        bb.push_back(tmp);
    }
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        pp.push_back(tmp);
    }
    //memset(dp, 0, sizeof(dp));
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    solution(bb, pp, dp, n);
    //printf("%d\n", dp[n][n]);
    printf("%d\n", ret);

    return 0;
}

int main2(){
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int d;
    while(cin >> d){

    }
    return 0;
}



