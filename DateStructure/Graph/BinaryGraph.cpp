//
// Created by devinchang on 2019/9/1.
//

#include <iostream>
#include <vector>
using namespace std;

const int MAX_V = 1000;
vector<int> G[MAX_V];
int V, E;
int n;
int color[MAX_V];

bool dfs(int v, int c){
    color[v] = c;
    for(int i = 0; i < G[v].size(); ++i){
        if(color[G[v][i]] == c)
            return false;
        if(color[G[v][i]] == 0 && !dfs(G[v][i], -c))
            return false;
    }
    return true;
}

int main(){
    // input
    scanf("%d%d", &V, &E);
    for(int i = 0; i < E; ++i){
        int s,t;
        scanf("%d%d", &s,&t);
        G[s].push_back(t);
        G[t].push_back(s);
    }
    // main logic
    for(int i = 0; i < V; ++i){
        if(color[i] == 0){
            if(!dfs(i, 1)){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    return 0;
}

