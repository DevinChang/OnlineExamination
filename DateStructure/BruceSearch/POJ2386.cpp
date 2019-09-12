//
// Created by devinchang on 2019/9/12.
//
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int N, M;
char filed[MAXN][MAXN];

void dfs(int row, int col){
    filed[row][col] = '.';
 	//int x, y, x1, y1;
 	for(int x = -1; x<=1; x++) {
        for (int y = -1; y <= 1; y++) {
            int x1 = row + x;
            int y1 = col + y;
            if (x1 >= 0 && x1 < N && y1 < M && 0 <= y1 && filed[x1][y1] == 'W')
                dfs(x1, y1);
        }
    }
}

int main(){
    freopen("/home/devinchang/Code/WritenExamination/TestCase/poj2386.txt",
            "r", stdin);
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++){
       scanf("%s", filed[i]);

    }
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(filed[i][j] == 'W'){
                dfs(i, j);
                ret++;
            }
        }
    }
    printf("%d\n", ret);
    return 0;
}


