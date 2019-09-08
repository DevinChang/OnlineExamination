//
// Created by devinchang on 2019/9/8.
//
#include<iostream>
#include <string>
#include <vector>
#include <stack>
#include <string.h>
#include <memory.h>
#include <queue>

using namespace std;



const int MAXN = 10010;


typedef struct node{
    int v[3];
    int fa;
    int lastflag;
    int deepth;
};

int capacity[3];
int water_to_get;
node q[MAXN];

int vis[MAXN][MAXN];

//void print_path();

void bfs(){
    q[0].v[0] = capacity[0];
    q[0].v[1] = q[0].v[2] = 0;
    q[0].fa = 0;
    q[0].deepth = 0;
    q[0].lastflag = 0;
    vis[q[0].v[1]][q[0].v[2]] = 1;
    int front = 0, rear = 1;
    while(front < rear){
        node N = q[front];
        if(N.v[0] == water_to_get || N.v[1] == water_to_get || N.v[2] == water_to_get)
        {
            printf("%d\n", N.deepth);
            return;
        }
        for(int i = 0; i < 3; i++){
            for(int j = 0;j < 3; j++){
                node &in = q[rear];
                if(i == j)
                    continue;
                int amount = min(N.v[i], capacity[j]-N.v[j]);
                for(int k = 0; k < 3; k++){
                    in.v[k] = N.v[k];
                }
                in.v[i] = N.v[i] - amount;
                in.v[j] = N.v[j] + amount;
                if(!vis[in.v[1]][in.v[2]]){
                    vis[in.v[i]][in.v[2]] = 1;
                    in.fa = front;
                    in.deepth = N.deepth + 1;
                    in.lastflag = 10 * i + j;
                    rear++;
                }
            }
        }
        front++;
    }
}

//int vis[MAXN][MAXN][MAXN];
//int S, M, N;
//int V[4];
//
//typedef struct node{
//    int v[4];
//    int step;
//}node;
//
//node tmp;
//
//void pour(int i, int j){
//    int sum = tmp.v[i] + tmp.v[j];
//    if(sum > V[j]){
//        tmp.v[i] = tmp.v[i] - (V[j] - tmp.v[j]);
//        tmp.v[j] = V[j];
//    }
//    else{
//        tmp.v[j] += tmp.v[i];
//        tmp.v[i] = 0;
//    }
//}
//
//void bfs(){
//    queue<node> q;
//    while(!q.empty())
//        q.pop();
//    node t;
//    t.step = 0;
//    t.v[1] = S;
//    t.v[2] = 0;
//    t.v[3] = 0;
//    q.push(t);
//    vis[t.v[1]][t.v[2]][t.v[3]] = 1;
//    while(!q.empty()){
//        node cur = q.front();
//        q.pop();
//        if(cur.v[1] == cur.v[2] && cur.v[3] == 0){
//            printf("%d\n", cur.step);
//            return;
//        }
//        for(int i = 1; i <= 3; i++){
//            for(int j = 1; j <= 3; j++){
//                if(i != j){
//                    tmp = cur;
//                    tmp.step++;
//                    pour(i, j);
//                    if(!vis[tmp.v[1]][tmp.v[2]][tmp.v[3]]){
//                        q.push(tmp);
//                        vis[tmp.v[1]][tmp.v[2]][tmp.v[3]] = 1;
//                    }
//                }
//            }
//        }
//    }
//    printf("No\n");
//    return;
//}

int main(){
    //while(~scanf("%d%d%d", &S, &M, &N)){
    //    memset(vis, 0, sizeof(vis));
    //    if(M < N)
    //        swap(M, N);
    //    bfs();
    //}
    scanf("%d%d%d%d", &capacity[0], &capacity[1], &capacity[2], &water_to_get);

    memset(vis, 0, sizeof(vis));
    bfs();

    return 0;
}

//int res = 0;
//
//int gcd(int m, int n){
//    int r = m % n;
//    if(0 == r){
//        //res++;
//        return n;
//    }
//    else {
//        res++;
//        return gcd(n, r);
//    }
//}
//
//int solution2(){
//    vector<int> num{3, 5, 8};
//    int n = num[0];
//    for(int i = 1; i < 3; i++){
//        n = gcd(n, num[i]);
//    }
//    cout << n << endl;
//    cout << "res = " << res << endl;
//    return 0;
//}
//
//
//int main2(){
//    int n;
//    scanf("%d", &n);
//    vector<int> vec;
//    for(int i = 0; i < n; ++i){
//        int tmp;
//        scanf("%d", &tmp);
//        vec.push_back(tmp);
//    }
//    stack<int> s;
//    int count = 0;
//    int ret = 0;
//    s.push(vec[vec.size()-1]);
//    for(int i = n - 2; i >= 0; --i){
//        if(vec[i] < s.top()){
//            s.push(vec[i]);
//        }
//        else{
//            if(s.size() > count){
//                ret = vec[i];
//                count = s.size();
//            }
//            while(!s.empty() && vec[i] > s.top()){
//                s.pop();
//            }
//            s.push(vec[i]);
//        }
//    }
//    printf("%d\n", ret);
//    printf("%d\n", gcd(3, 5));
//    //cout << "ret = " << ret << endl;
//    solution2();
//    return 0;
//}
//
//int main1(){
//
//    return 0;
//}
//
