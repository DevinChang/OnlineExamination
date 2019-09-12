//
// Created by devinchang on 2019/9/12.
//
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e8;
const int MAXN = 110;

typedef pair<int, int> P;

int N, M;
char maze[MAXN][MAXN];
int sx, sy;
int gx, gy;

int d[MAXN][MAXN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(){
    queue<P>que;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            d[i][j] = INF;
    }
    que.push(P(sx, sy));
    d[sx][sy] = 0;
    while(que.size()){
        P p = que.front();
        que.pop();
        if(p.first == gx && p.second == gy)
            break;
        for(int i = 0; i < 4; i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF){
                que.push(P(nx, ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    return d[gx][gy];
}

int main(){
    freopen("/home/devinchang/Code/WritenExamination/TestCase/shorpath.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++){
        scanf("%s", maze[i]);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(maze[i][j] == 'S'){
                sx = i, sy = j;
            }
            else if(maze[i][j] == 'G'){
                gx = i, gy = j;
            }
        }
    }
    int res = bfs();
    printf("%d\n", res);
    return 0;
}

