//
// Created by devinchang on 2019/9/7.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




int main(){
    //
    int a = 9999;
    int cnt = 0;
    while(a){
        // 每做这样的一步操作,就是将最右边的1消除,也就是说数a的二进制有多少个1就会执行几步
        a = a & (a-1);
        cnt++;
    }
    cout << cnt << endl;
    //vector<int> vec{12, 17, 20, 22, 23, 30, 33, 40};
    //cout << *lower_bound(vec.begin(), vec.end(), 21) << endl;
    //cout << *upper_bound(vec.begin(), vec.end(), 21) << endl;
    //cout << *lower_bound(vec.begin(), vec.end(), 22) << endl;
    //cout << *upper_bound(vec.begin(), vec.end(), 22) << endl;

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    //vector<char> vec('a', n);
    char str[n+m];
    for(int i = 0; i < n; i++){
        str[i] = 'a';
    }
    for(int i = n; i < n+m; i++)
        str[i] = 'z';
    while(k-- && next_permutation(str, str+n+m));
    if(k == 0){
        prev_permutation(str, str+n+m);
        for(auto c : str)
            cout << c;
    }
    else
        cout << -1;
    return 0;
}

