//
// Created by devinchang on 2019/8/22.
//

#include <set>
#include "MeiTuan8_22.h"


int MeiTuan8_22::latestKuaiDiWrap(std::string &str) {
    std::unordered_map<char, int> hash;
    for(int i = 0; i < str.size(); ++i){
        hash[str[i]] = i;
    }
    int left = 0, right = 0;
    int maxlen = 0;
    for(int i = 0; i < str.size(); ++i){
        int len = hash[str[i]] - left + 1;
        if(len > maxlen){
            right = hash[str[i]];
            maxlen = len;
        }
        if(i == right){
            printf("%d ", maxlen);
            maxlen = 0;
            left = right + 1;
        }
    }
    return maxlen;
}

void MeiTuan8_22::alienOrder(std::vector<std::string> &words) {
    if(words.size() == 0) {
        printf(" ");
        return;
    }
    std::unordered_map<char, int> indegree;
    std::unordered_map<char, std::multiset<char>> hash;
    for(auto word : words){
        for(auto ch : word)
            indegree[ch] = 0;
    }

    for(int i = 1; i < words.size(); ++i){
        int k = 0, len1 = words[i-1].size(), len2 = words[i].size();
        //while(words[i-1][k] == words[i][k])
        //    ++k;
        for(int k = 0; k < len1 && k < len2; ++k){
            if(words[i-1][k] == words[i][k])
                continue;
        }
        if(k >= std::min(len1, len2))
            continue;
        indegree[words[i][k]]++;
        hash[words[i-1][k]].insert(words[i][k]);
    }
    std::string ret;
    for(int i = 0; i< indegree.size(); ++i){
        char ch =  ' ';
        for(auto val : indegree){
            if(!val.second){
                ch = val.first;
                break;
            }
        }
        if(ch == ' '){
            printf(" ");
            return;
        }
        ret += ch;
        indegree[ch]--;
        for(auto val : hash[ch])
            indegree[val]--;
    }
    std::cout << ret << std::endl;
}
