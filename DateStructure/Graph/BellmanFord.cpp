//
// Created by devinchang on 2019/9/1.
//
#include <iostream>
using namespace std;

const int MAX_E = 1000;
const int MAX_V = 1000;
const int INF = 100001;

struct edge{
    int from;
    int to;
    int cost;
};

edge es[MAX_E];

int d[MAX_V];
int V, E;

void shortest_path(int s){
    for(int i = 0; i < V; ++i)
        d[i] = INF;
    d[s] = 0;
    while(true){
        bool update = false;
        for(int i = 0; i < E; ++i){
            edge e = es[i];
            if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
        if(!update)
            break;
    }
}

int main(){

    return 0;
}

