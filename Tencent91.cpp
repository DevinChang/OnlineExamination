//
// Created by devinchang on 2019/9/1.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


void question1(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> box;
    vector<int> key;
    int boxnum = 0, keynum = 0;
    int boxodd = 0, boxeven = 0;
    int keyodd = 0, keyeven = 0;
    for(int i = 0; i < n; ++i){
        int tmp;
        scanf("%d", &tmp);
        box.push_back(tmp);
        if(tmp % 2)
            boxodd++;
        else
            boxeven++;
    }
    for(int i = 0; i < m; ++i){
        int tmp;
        scanf("%d", &tmp);
        key.push_back(tmp);
        if(tmp % 2)
            keyodd++;
        else
            keyeven++;
    }
    boxnum = min(boxodd, boxeven);
    keynum = min(keyodd, keyeven);
    int count = boxnum + keynum;
    /*
     * 超时的代码
    map<int, int> used;
    for(int i = 0; i < box.size(); ++i){
        for(int j = 0; j < key.size(); ++j){
            if((key[j] + box[i])  % 2){
                used.insert(pair<int, int>{i, j});
            }
        }
    }
    count = used.size();
    */
    printf("%d\n", count);
}

int n, m;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first){
        return a.first > b.first;
    }
    else
        return a.second < b.second;
}

int main1(){
    /*

    */
    //scanf("%d", &n);
    //vector<pair<int, int>> vec;
    //for(int i = 0; i < n; ++i){
    //    int a, b;
    //    scanf("%d%d", &a, &b);
    //    vec.push_back(pair<int, int>{a, b});
    //}
    //// 让a大的排最前，b大的排最后
    //sort(vec.begin(), vec.end(), cmp);
    ////for(auto v : vec)
    ////    cout << v.first << " " << v.second << endl;
    //int count = 0;
    //int i = 0;
    //for(int j = 1; j <= n; ++j){
    //    count += vec[j-1].first * (j - 1) + vec[j-1].second * (n - j);
    //}
    //printf("%d\n", count);

    scanf("%d%d", &n, &m);
    vector<int> vec;
    for(int i = 0; i < n; ++i){
        int tmp;
        scanf("%d", &tmp);
        vec.push_back(tmp);
    }
    int ret = 1, worker = m;
    for(int i = 0; i < vec.size(); ++i){
        if(worker > vec[i]){
            worker -= vec[i];
            ++ret;
        }
        else if(worker < vec[i]){
            ret += vec[i] - worker;
        }
    }
    printf("%d", ret);
    return 0;
}

int main(){
    scanf("%d", &n);
    vector<int> score;
    for(int i = 0; i < n; ++i){
        int tmp;
        scanf("%d", &tmp);
        score.push_back(tmp);
    }
    vector<int> dp[n];
    int res = score[0];
    int i = 1;
    int imaxleft, imaxright;
    int minheight;
    int ret = 0;
    while(i < score.size()){
        if(i < score.size() - 1 && score[i + 1] >= score[i]){
            ++i;
            continue;
        }
        int pre = score[i];
        for(int j = i; j >= 0 && score[j] > 0; --j){
            if(score[j] < pre)
                pre = score[j];
            if(pre * (i - j + 1) > res){
                res = pre * (i - j + 1);
                imaxleft = j, imaxright = i;
                minheight = pre;
            }
        }
        ++i;
    }
    //printf("%d %d %d\n", imaxleft, imaxright, minheight);
    for(int i = imaxleft; i <= imaxright; ++i){
        ret += score[i];
    }
    ret *= minheight;
    printf("%d\n", ret);
    return 0;
}

