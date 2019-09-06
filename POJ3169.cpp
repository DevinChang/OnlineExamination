//
// Created by devinchang on 2019/9/6.
//

#include <iostream>
#include <algorithm>
using namespace std;


const int INF = 0x7fffffff;
const int MAXN = 10010;
const int MAXML = 10010;
const int MAXMD = 10010;

int N, ML, MD;
int AL[MAXML], BL[MAXML], DL[MAXML];
int AD[MAXMD], BD[MAXMD], DD[MAXMD];

// 最短距离
int d[MAXN];
bool updated;

bool update(int &x, int y){
    if(x > y){
        x = y;
        updated = true;
    }
}

void bellmanford(){
    for(int k = 0; k <= N; ++k){
        updated = false;
        // 从i+1到i的权值为0
        for(int i = 0; i + 1 < N; ++i){
            if(d[i+1] < INF)
                update(d[i], d[i+1]);
        }
        // 从AL到BL的权值为DL
        for(int i = 0; i < ML; ++i){
            if(d[AL[i] - 1] < INF)
                update(d[BL[i]-1], d[AL[i]-1] + DL[i]);
        }
        // 从BD到AD的权值为-DD
        for(int i = 0; i < MD; ++i){
            if(d[BD[i]-1] < INF)
                update(d[AD[i]-1], d[BD[i]-1]-DD[i]);
        }
    }
}


void solve(){
    // 检查是否存在负圈
    fill(d, d+N, 0);
    bellmanford();
    if(updated){
        printf("-1\n");
        return;
    }
    fill(d, d+N, INF);
    d[0] = 0;
    bellmanford();
    int res = d[N-1];
    if(res == INF)
        res = -2;
    printf("%d\n", res);
}


int main(){
    while(~scanf("%d%d%d", &N, &ML, &MD)){
        for(int i = 0; i < ML; i++){
            scanf("%d%d%d", &AL[i], &BL[i], &DL[i]);
        }
        for(int i = 0; i < MD; i++){
            scanf("%d%d%d", &AD[i], &BD[i], &DD[i]);
        }
        solve();
    }
    return 0;
}
