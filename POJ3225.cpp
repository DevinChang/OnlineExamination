//
// Created by devinchang on 2019/9/2.
//
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;



const int MAX_N = 5000;
const int INF = 999999;

struct edge{
    int to;
    int cost;
};

int N, R;
//vector<edge> G[MAX_N];
typedef pair<int, int> P;

// 最短距离
int dist[MAX_N];
// 次短距离
int dist2[MAX_N];

int main(){
    // input:
    scanf("%d%d", &N, &R);
    vector<edge> G[MAX_N];
    for(int u = 0, v = 0; v < R; ++v){
        int n, r, c;
        edge e;
        scanf("%d%d%d", &n, &r, &c);
        // 这样做是因为输入的时候下标从1开始
        --n, --r;
        e.to = r, e.cost = c;
        G[n].push_back(e);
        e.to = n, e.cost = c;
        G[r].push_back(e);
    }
    // main logic:
    priority_queue<P, vector<P>, greater<P>> que;
    fill(dist, dist+N, INF);
    fill(dist2, dist2+N, INF);
    dist[0] = 0;
    que.push(P(0, 0));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second, d = p.first;
        if(dist2[v] < d)
            continue;
        for(int i = 0; i  < G[v].size(); ++i){
            edge &e = G[v][i];
            int d2 = d + e.cost;
            // 更新距离并添加节点
            if(dist[e.to] > d2){
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to));
            }
            // 找次短距离
            if(dist2[e.to] > d2 && dist[e.to] < d2){
                dist2[e.to] = d2;
                que.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%d\n", dist2[N-1]);
}
