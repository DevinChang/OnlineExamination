//
// Created by devinchang on 2019/9/12.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 10010;
int n, k;
int a[MAXN];

bool dfs(int index, int sum){
    if(index == n)
        return sum == k;
    // 不加a[index]
    if(dfs(index + 1, sum))
        return true;
    // 加a[index]
    if(dfs(index+1, sum+a[index]))
        return true;
    // 遍历完都不等于k时
    return false;
}

void solve(){
    if(dfs(0, 0))
        printf("Yes\n");
    else
        printf("No\n");
}


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &k);
    solve();
    return 0;
}

