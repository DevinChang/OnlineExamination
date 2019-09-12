//
// Created by devinchang on 2019/9/11.
//
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

const int MAXN = 10010;
const int INF = 1e8;
int c[MAXN], d[MAXN];




bool comp(pair<int, int> a, pair<int, int> b){
    return (a.first - a.second) > (b.first - b.second);
}


int solution1(){
    int n;
    scanf("%d", &n);
    int a, b;
    scanf("%d%d", &a, &b);
    vector<pair<int, int>> vec;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &c[i], &d[i]);
        vec.push_back(pair<int, int>(c[i], d[i]));
    }

    int ret = 0;
    sort(vec.begin(),vec.end(), comp);
    for(int i = 0; i < b; i++){
        ret += vec[i].second;
    }
    for(int i = b; i < n; i++){
        ret += vec[i].first;
    }
    printf("%d\n", ret);
}



vector<int> helpInput(string line){
    vector<int> vec;
    stringstream ss;
    ss.str(line);
    string item;
    while(getline(ss, item, ' '))
        vec.push_back(stoi(item));
    return vec;
}

int catrow, catcol;
int mourow, moucol;
int N, M;
int dis[MAXN][MAXN];
vector<vector<int>> vec;


typedef pair<int, int> P;

bool check(vector<vector<int>> &vec, int rows, int cols, int row, int col, bool *visited){
    if(row >= 0 && row < rows && col >= 0 && col < cols
       && vec[row][col] != 1 && vec[row][col] != 3)
        return true;
    return false;
}

int countcore(vector<vector<int>> &vec, int rows, int cols, int row, int col, bool *visited){
    int step = 0;
    if(check(vec, rows, cols, row, col, visited)){
        visited[row * cols + col] = true;
        step = 1 + countcore(vec, rows, cols, row-1, col, visited)
                 + countcore(vec, rows, cols, row, col-1, visited)
                 + countcore(vec, rows, cols, row+1, col, visited)
                 + countcore(vec, rows, cols, row, col+1, visited);
    }
    return step;
}

int bfs(){
    queue<P> que;
    que.push(P(catrow, catrow));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            dis[i][j] = INF;
    }
    dis[catrow][catcol] = 0;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    while(que.size()){
        P p = que.front();
        que.pop();
        if(p.first == mourow && p.second == moucol){
            break;
        }
        for(int i = 0; i < 4; i++){
            int x1 = p.first + dx[i];
            int y1 = p.second + dy[i];
            if(0 <= x1 && x1 < N && 0 <= y1 && y1 < M && vec[x1][y1] != 1 && dis[x1][y1] == INF){
                que.push(P(x1, y1));
                dis[x1][y1] = dis[p.first][p.second] + 1;
            }
        }
    }
    return dis[mourow][moucol];
}

void solution2(){
    string line;
    //while(getline(cin, line)){
    //    vec.push_back(helpinput(line));
    //}
    for(int i = 0; i < 4; i++){
        getline(cin, line);
        vec.push_back(helpInput(line));
    }

    int row = vec.size(), col = vec[0].size();
    N = row, M = col;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(vec[i][j] == 2){
                catrow = i, catcol = j;
                break;
            }
            else if(vec[i][j] == 3){
                mourow = i, moucol = j;
                break;
            }
        }
    }
    //bool visited[row * col];
    //for(int i = 0; i < row * col; i++)
    //    visited[i] = false;

    //int step = countcore(vec, row, col, catrow, catcol, visited);
    int step = bfs();
    printf("%d\n", step);
}





int main(){
    //solution1();
    solution2();
    return 0;
}

