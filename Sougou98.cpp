//
// Created by devinchang on 2019/9/8.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
using namespace std;

vector<pair<char, int>> vec;

class Mymap{
public:
    Mymap(int capacity) : cap(capacity), count(0){}

    void insert(pair<string, int> item){
        auto p = hash.find(item.first);
        if(p != hash.end()){
            lst.erase(p->second);
        }
        else if(count == cap){
            auto it = lst.back().first;
            poplist.push_back(lst.back());
            lst.pop_back();
            hash.erase(it);
        }
        else
            count++;
        lst.push_front(item);
        hash[item.first] = lst.begin();
    }

    void printDelitem(){
        for(auto v : poplist){
            cout << v.first << " " << v.second << endl;
        }
    }

private:
    int cap;
    int count;
    list<pair<string, int>> lst;
    unordered_map<string, list<pair<string, int>>::iterator> hash;
    vector<pair<string, int>> poplist;
};

vector<int> helpInput(string line){
    vector<int> vec;
    stringstream ss;
    ss.str(line);
    string item;
    while(getline(ss, item, ' '))
        vec.push_back(stoi(item));
    return vec;
}
string generate(string left, string right){
    return "";
}

int findMinstep(string str, string ss){
    if(str.size() == 0){
        //printf("0\n");
        return 0;
    }
    int res = ss.size() + 1;
    int i = 0;
    while (i < str.size()){
        int cur = 0, cnt = 0;
        char item = str[i];
        while(i < str.size() && str[i] == item){
            i++;
            cnt++;
        }
        if(count(ss.begin(), ss.end(), item) >= 3-cnt){
            cur += 3 - cnt;
            string newss = ss;
            string left = str.substr(0, i-cnt);
            string right = str.substr(i);
            string newstr = generate(left, right);
            for(int k = 0; k < 3 - cnt; k++){
                newstr.erase(newstr.find(item), 1);
                vec.push_back(pair<char,int>(item, 0));
            }
            int steps = findMinstep(newstr, newss);
            if(steps != -1)
                res = min(res, cur+steps);
        }
    }
    return res == ss.size()+1 ? -1 : res;
}


int main(){
    int n;
    cin >> n;
    //string key;
    Mymap imap(n);
    unsigned int value;
    char key[20];
    vector<pair<string, int>> vec;
    while(~scanf("%s%d", key, &value)){
        vec.push_back(pair<string,int>(key, value));
        imap.insert(pair<string, int>(key, value));
        imap.printDelitem();
    }

    //imap.printDelitem();

    return 0;
}

