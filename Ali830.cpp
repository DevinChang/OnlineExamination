//
// Created by devinchang on 2019/8/30.
//
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int N = 3;

int pow(int a, int n){
    int t = 1;
    while(n--){
        t *= 2;
    }
    return t;
}

int main(){
    string line;
    vector<string> vec;
    for(int i = 0; i < N; ++i){
        getline(cin, line);
        vec.push_back(line);
    }
    for(int i = 0; i < N; ++i){
        int t = 0;
        for(int j = 0; j < vec[i].size(); ++j){
            if(vec[i][j] != '$' && vec[i][j] != '%' && vec[i][j] != '^' && vec[i][j] != '&' && vec[i][j] != '*')
                t++;
        }
        printf("%d %d\n", pow(2, t), 1);
    }
    return 0;
}
