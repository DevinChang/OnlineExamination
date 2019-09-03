//
// Created by devinchang on 2019/8/30.
//
#include <iostream>
#include <memory.h>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

const int N = 6;
int value[N] = {1, 5, 10, 50, 100, 500};
int A;
int coinNum[N];

vector<int> helpInput(string line){
    vector<int> ret;
    stringstream ss;
    ss.str(line);
    string item;
    while(getline(ss, item, ' ')){
        ret.push_back(stoi(item));
    }
    return ret;
}




int main(){
    // input
    memset(coinNum, 0, sizeof(coinNum));
    string line;
    getline(cin, line);
    vector<int> C = helpInput(line);
    for(int i = 0; i < N; ++i)
        coinNum[i] = C[i];
    A = C[C.size()-1];
    // main logic
    int ret = 0;
    for(int i = N - 1; i >= 0; --i){
        int n = min(A / value[i], coinNum[i]);
        A -= n * value[i];
        ret += n;
    }
    printf("%d\n", ret);
    return 0;
}

