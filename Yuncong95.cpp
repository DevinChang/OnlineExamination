//
// Created by devinchang on 2019/9/5.
//

#include <iostream>


#include<bits/stdc++.h>
using namespace std;


const int MAXINT = 999999;
const int N = 1005;
const int MAXBUF = 100000;

int n, k, ms, me;
long long S[N], E[N], W[N];
int SS, TT;
int h[N];
int cnt = 1;
int edge_id[N];

struct edge{
    int to, next;
    long long f, c;
}ed[N<<3];

//vector<edge> ed;
long long ret;
queue<int> que;
bool in[N];
long long dis[N];
int fr[N], e[N];

void add(int i, int j, int f, int c){
    edge tmp;
    tmp.to = j, tmp.next = h[i], tmp.f = f, tmp.c = c;
    ed[++cnt] = tmp;
    h[i] = cnt;
    tmp.to = i, tmp.next = h[j], tmp.f = 0, tmp.c = -c;
    ed[++cnt] = tmp;
    h[j] = cnt;
}

bool spfa(int S, int T){
    memset(dis, -0x3f, sizeof(dis));
    dis[S] = 0;
    que.push(S);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        in[v] = 0;
        for(int i = h[v]; i; i = ed[i].next){
            int to = ed[i].to;
            if(ed[i].f && dis[to] < dis[v] + ed[i].c){
                dis[to] = dis[v] + ed[i].c;
                fr[to] = v;
                e[to] = i;
                if(!in[to]){
                    in[to] = 1;
                    que.push(to);
                }
            }
        }
    }
    if(dis[T] < -1e9){
        return 0;
    }
    long long maxflow = 1e9;
    for(int i = T; i; i = fr[i]){
        maxflow = min(maxflow, ed[e[i]].f);
    }
    ret += maxflow * dis[T];
    for(int i = T; i; i = fr[i])
    {
        ed[e[i]].f -= maxflow;
        ed[e[i]^1].f += maxflow;
    }
    return 1;
}

int main(){
    //scanf("%d%d%d%d", n, k, ms, me);
    cin >> n >> k >> ms >> me;
    for(int i = 1; i <= n; ++i){
        //int tmp;
        scanf("%d", &S[i]);
    }
    for(int i = 1; i <= n; ++i){
        //int tmp;
        scanf("%d", &E[i]);
    }

    for(int i = 1; i <= n; ++i)
        ret += E[i];
    for(int i = 1; i<= n; ++i)
        W[i] = S[i] - E[i];

    TT = 2 *n + 2;
    add(1, TT, ms, 0);
    add(SS, 2, k-me, 0);
    for(int i = 1; i <= n - k + 1; ++i){
        add(i+2, TT, k-ms-me, 0);
    }
    for(int i = 1; i <= n - k; ++i){
        add(SS, i+n-k+3, k-ms-me, 0);
    }
    for(int i = 1; i <= k; ++i){
        edge_id[i] = cnt + 1;
        if(i >= n - k + 1)
            add(2, 1, 1, W[i]);
        else
            add(n - k + 3 + i, 1, 1, W[i]);
    }

    for(int i = 1; i <= n - k; ++i){
        edge_id[i + k] = cnt + 1;
        if(i + k >= n -k + 1)
            add(2, i+n-k+3, 1, W[i+k]);
        else
            add(i+n+3, i+n-k+3, 1, W[i+k]);
    }
    add(1, 3, 1e9, 0);
    for(int i = 1; i <= n -k; ++i){
        add(i+n-k+3, i+3, 1e9, 0);
    }
    for(int i = 1; i <= n -k; ++i){
        add(i+n-k+3, i+2, 1e9, 0);
    }
    while(spfa(SS, TT));
    printf("%d\n", ret);
    for(int i = 1; i <= n; ++i){
        if(ed[edge_id[i]].f)
            cout << "E";
        else
            cout << "S";
    }
    return 0;
}



