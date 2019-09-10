//
// Created by devinchang on 2019/9/6.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAXN = 200010;


int main(){
    ios::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    vector<int> vec;
    //long long vec[MAXN];
    //memset(vec, 0, sizeof(vec));
    for(int i = 0; i < n; i++){
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    //while(n--){
    //    int tmp;
    //    cin >> tmp;
    //    vec.push_back(tmp);
    //    //scanf("%d", &vec[]);
    //}
    int left = 0, right = n - 1;
    long long res = 0;
    long long l = vec[left], r = vec[right];
    while(left < right){
        if(l < r){
            l += vec[++left];
        }
        else if(l > r) {
            r += vec[--right];
            //--right;
        }
        else{
            res = l;
            l += vec[++left];
            r += vec[--right];
        }
    }
    printf("%lld\n", res);
    return 0;
}

