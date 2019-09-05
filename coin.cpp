//
// Created by devinchang on 2019/9/4.
//
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;





int main(){
    int n, w;
    scanf("%d%d", &n, &w);
    vector<int> vec;
    while(n--){
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    vector<int> dp(w + 1, 9999);
    dp[0] = 0;
    for(int i = 1; i <= w; ++i){
        for(auto v : vec){
            if(v <= i)
                dp[i] = min(dp[i], dp[i-v] + 1);
        }
    }
    int ret = dp[w] == 9999 ? -1 : dp[w];
    if(ret){
        ret = pow(2, ret);
        printf("%d\n", ret);
    }
    return 0;
}


