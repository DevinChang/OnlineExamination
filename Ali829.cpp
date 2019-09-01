//
// Created by devinchang on 2019/8/29.
//

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
using namespace std;


int X, Y;


vector<int> helpInput(string line){
    vector<int> vec;
    stringstream ss;
    ss.str(line);
    string item;
    while(getline(ss, item, ' '))
        vec.push_back(stoi(item));
    return vec;
}

/* 输入格式： 2 0
 *          0 1 1
 *          1 2 3
 * 输出格式： 4
 * */

int main(){
    string line;
    while(getline(cin, line)){
        vector<int> startInput = helpInput(line);
        X = startInput[0], Y = startInput[1];
        //X = stoi(line);
        //getline(cin, line);
        //Y = stoi(line);
        getline(cin, line);
        vector<int> M = helpInput(line);
        getline(cin, line);
        vector<int> N = helpInput(line);
        if(M.size() != N.size()){
            printf("-1\n");
            return -1;
        }
        else if(M.size() > 50000){
            printf("-2\n");
            return -1;
        }

        int ret = Y;
        priority_queue<int> low;
        multimap<int, int> pro;
        for(int i = 0; i < N.size(); ++i)
            pro.insert(pair<int, int>{M[i], N[i]});
        auto it = pro.begin();
        while(X--){
            //for(auto it = pro.begin(); it != pro.end() && it->first <= ret;++it)
            //    low.push(it->second);
            // 上一个循环有点问题,应该从下一个可获得最大的利润找
            for(; it != pro.end() && it->first <= ret;++it)
                low.push(it->second);
            if(low.empty()){
                break;
            }
            ret += low.top();
            low.pop();
        }
        printf("%d\n", ret);
        break;
    }
    return 0;
}
