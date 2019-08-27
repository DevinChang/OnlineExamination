//
// Created by devinchang on 2019/8/27.
//

#include "KuaiShou825.h"
#include <string.h>

const int MAXSIZE = 100010;
const int MOD = 1e9+7;


struct node{
    int to;
    int color;
    node(int t, int c) : to(t), color(c) {}
};

struct node2{
    int to;
    int color;
    int num;
    node2(int t, int c, int n) : to(t), color(c), num(n) {}
};

vector<node> g[MAXSIZE];
vector<node2> G[MAXSIZE];
bool visit[MAXSIZE];
int num[MAXSIZE];
int ans = 0;
int n, k, l, r, c;

void build(int root){
    if(visit[root] == 1)
        return;
    visit[root] = 1;
    for(int i = 0; i < g[root].size(); ++i){
        if(visit[g[root][i].to] == 0){
            G[root].push_back(node2(g[root][i].to, g[root][i].color, 0));
            build(g[root][i].to);
        }
    }
}

int fast(int a, int b){
    int ans = 1;
    while(b){
        if(b % 2 == 1){
            ans = 1LL * ans * a % MOD;
        }
        b /= 2;
        a = 1LL * a * a % MOD;
    }
    return ans;
}

void solve(int root){
    num[root] = 1;
    for(int i = 0; i < G[root].size(); ++i){
        solve(G[root][i].to);
        if(G[root][i].color == 0){
            num[root] += num[G[root][i].to];
            ans = (ans + MOD - fast(num[G[root][i].to], k)) % MOD;
        }
    }
    ans = (ans + fast(num[root], k)) % MOD;
}

int KuaiShou825::goodNumber() {
    memset(visit, 0, sizeof(visit));
    memset(num, 0, sizeof(num));
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n-1; ++i){
        scanf("%d%d%d", &l, &r, &c);
        g[l].push_back(node(r, c));
        g[r].push_back(node(l, c));
    }
    build(1);
    solve(1);
    int ret = (fast(n, k) + MOD - ans) % MOD;
    printf("%d\n", ret);
}