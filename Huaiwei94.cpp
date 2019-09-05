//
// Created by devinchang on 2019/9/4.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;


//#include<bits/stdc++.h>
//using namespace std;



int main1(){
    int n;
    scanf("%d", &n);
    vector<int> pack{4, 9};
    int ret = 0;
    if(n <= 4){
        printf("%d\n", ret);
        return 0;
    }
    vector<int> dp(n + 1, n+ 1);
    dp[0] = 0;
    for(int i = 1; i <= n; ++i){
        for(auto p : pack){
            if(p <= i){
                dp[i] = min(dp[i], dp[i-p]+1);
            }
        }
    }
    ret = dp[n] > n ? -1 : dp[n];
    printf("%d\n", ret);
    return 0;
}

string &clearAllSapce(string &str){
    int index = 0;
    if(!str.empty()){
        while((index = str.find(' ', index)) != string::npos)
            str.erase(index, 1);
    }
    return str;
}


unordered_map<string, string> hash1;

bool isNum(string str){
    stringstream sin(str);
    double d;
    char c;
    if(!(sin >> d)){
        return false;
    }
    if(sin >> c){
        return false;
    }
    return true;
}


vector<string> helpInput(string line){
    vector<string> vec;
    //int i = 0;
    //while(line[i] == ' ') i++;
    //while()
    stringstream ss;
    ss.str(line);
    string item;
    while(getline(ss, item, '=')){
        vec.push_back(item);
    }
    hash1[vec[0]] = vec[1];
    return vec;
}

void handleline(string line){
    int bl = 0, br = 0;
    for(int i = 0; i < line.size(); ++i){
        if(line[i] == ' ')
            continue;
    }
}

int main(){
    int n;
    //scanf("%d", &n);
    string line;
    getline(cin, line);
    n = stoi(line);
    vector<string> vec[n];
    for(int i = 0; i < n; ++i){
        getline(cin, line);
        line = clearAllSapce(line);
        vec[i] = helpInput(line);
    }

    auto it = hash1.begin();
    stringstream ss;
    ss.str(it->second);
    string item;
    vector<string> vec2;
    while(getline(ss, item, '+')){
        vec2.push_back(item);
    }
    unordered_map<string, int> hash2;
    for(it++; it != hash1.end(); ++it){
        if(isNum(it->second))
            hash2[it->first] = stoi(it->second);
        else{
            if(isNum(hash1[it->second]))
                hash2[it->first] = stoi(hash1[it->second]);
        }
    }
    int ret = 0;
    for(int i = 0; i < vec2.size(); ++i){
         ret += hash2[vec2[i]];
    }
    printf("%d\n", ret);


    return 0;
}
