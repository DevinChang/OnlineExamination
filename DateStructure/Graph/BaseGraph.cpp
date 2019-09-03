//
// Created by devinchang on 2019/8/27.
//

#include <iostream>
using namespace std;


// 图的表示

/*请编写一个程序，将以邻接表形式给出的有向图G 以邻接矩阵形式输出。G 包含n(=|V|)个顶点,编号分别为1至n.
输入:
第1行输人G的顶点数n,接下来的n行,按照下述格式输人各顶点w的邻接表Adj[u].
u k v1 v2 ... vk
其中u为顶点编号, k为u的度,
输出:
按照输出示例中的格式输出G的邻接矩阵.aij之间用1个空格隔开.
限制1 < n < 100
 输入示例：
 4
 1 2 2 4
 2 1 4
 3 0
 4 1 3
 输出示例
 0 1 0 1
 0 0 0 1
 0 0 0 0
 0 0 1 0
 * */



const int N = 100;
// 邻接矩阵
int M[N][N];
int n, u, k, v;


int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; j++)
            M[i][j] = 0;
    }
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &u, &k);
        // 转换为0起点
        --u;
        for(int j = 0; j < k; ++j){
            scanf("%d", &v);
            // 转换为0起点
            --v;
            M[u][v] = 1;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; j++){
            // 控制输出空格
            //if(j) printf(" ");
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}
