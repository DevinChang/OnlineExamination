//
// Created by devinchang on 2019/9/2.
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;


const int MAX_V = 10000;
const int MAX_E = 10000;
const int INF = 9999999;


struct edge{
    int to, cost;
};

// first是最短距离, second是编号
typedef pair<int, int> P;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P>> que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;
        for(int i = 0; i < G[v].size(); ++i){
            edge e = G[v][i];
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}


