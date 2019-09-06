//
// Created by devinchang on 2019/9/6.
//

#include <iostream>
#include <algorithm>
#include "../UnionSet.cpp"
using namespace std;


const int MAX_E = 10000;

struct edge{
    int u, v;
    int cost;
};

edge es[MAX_E];
int V, E;

bool comp(const edge &e1, const edge &e2){
    return e1.cost < e2.cost;
}

int krusal(){
    sort(es, es+E, comp);
    unionInit(V);
    int res = 0;
    for(int i = 0; i < E; ++i){
        edge e = es[i];
        if(!unionFind(e.u, e.v)){
            unionUnite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}
