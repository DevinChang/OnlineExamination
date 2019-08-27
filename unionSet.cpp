//
// Created by devinchang on 2019/8/26.
//

//并查集的实现

const int MAXSIZE = 500;

int uset[MAXSIZE];
// rank表示每个节点的权,通过权重的大小合并集合
int rank[MAXSIZE];

void makeSet(int size){
    for(int i = 0; i < size; ++i)
        uset[i] = 0;
    for(int i = 0; i < size; ++i)
        rank[i] = 0;
}

int find_recur(int x){
    // 路径压缩
    if(x != uset[x])
        uset[x] = find(uset[x]);
    return uset[x];
}

int find_norecur(int x){
    int p = x;
    int t;
    while(uset[p] != p)
        // 返回根节点
        p = uset[p];
    // 路径压缩
    while(x != p){
        t = uset[x];
        uset[x] = p;
        x = t;
    }
    return x;
}

void unionSet(int x, int y){
    // 在同一个集合中
    if((x = find(x)) == (y = find(y)))
        return ;
    // 将权重小的合并到权重大的
    if(rank[x] > rank[y])
        uset[y] = x;
    else{
        uset[x] = y;
        if(rank[x] == rank[y])
            rand[y]++;
    }
}

