//
// Created by devinchang on 2019/9/10.
//
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;



vector<pair<string, string>> ihash;

vector<string> splitString(string &str, string pattern){
    vector<string> vec;
    size_t pos = str.find(pattern);
    while(pos != str.npos){
        string tmp = str.substr(0, pos);
        vec.push_back(tmp);
        str = str.substr(pos + 1, str.size());
        pos = str.find(pattern);
        if(pos == str.npos){
            if(str.size() > 0)
                vec.push_back(str);
        }
    }

    return vec;
}

void splitString2(string &str, string pattern){
    size_t pos = str.find(pattern);
    while(pos != str.npos){
        string key = str.substr(0, pos);
        string value = str.substr(pos + 1, str.size());
        ihash.push_back(pair<string, string>(key, value));
        str = str.substr(pos + 1, str.size());
        pos = str.find(pattern);
    }
}

void solution(string line){
    vector<pair<string, string>> res;
    stringstream ss(line);
    string item;
    string pre, cur;
    vector<string> vec;
    while(getline(ss, item, ' ')){
        vec.push_back(item);
    }
    vector<string> vec2 = splitString(vec.back(), vec[0]);
    for(int i = 0; i < vec2.size(); i++){
        splitString2(vec2[i], vec[1]);
    }
}




int main(){
    ios::sync_with_stdio(false);
    string line;
    getline(cin, line);
    //splitString(line);
    solution(line);
    //printf("%d\n", ihash.size());
    cout << ihash.size() << endl;
    for(auto it = ihash.begin(); it != ihash.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}

