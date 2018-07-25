#include<cstdio>
#include<algorithm>
#include <cstring>

using namespace std;

const int MAXV = 510;
const int INF = 100000000;
int n,m,c1,c2,G[MAXV][MAXV],Weight[MAXV];//最后一个为点权，每个点物资重量
int num[MAXV], w[MAXV];//最短路径数目 最大物资数目
int d[MAXV];//s到Vi最短距离
bool vis[MAXV] = {false};//记录访问过的结点

void dijkstra(int s) {//单源最短路径

    fill(d , d+MAXV , INF);
    memset(num , 0 , sizeof(num));
    memset(w , 0 , sizeof(w));
    d[s] = 0;//为了让第一次选中s点
    w[s] = Weight[s];
    num[s] = 1;

    for(int i = 0 ; i < n ; i++){//占领n个城市

        int min = INF , u = -1;//=-1是为了下面的判断
        for(int j = 0 ; j < n ; j++){
            if(vis[j] == false && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;//找不到能到的点了
        vis[u] = true;

        for(int v = 0 ; v < n ; v++){//对其他黑暗中的点进行更新
            if(vis[v] == false && d[u] + G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];
                num[v] = num[u];
                w[v] = w[u] + Weight[v];
            }else if(vis[v] == false && d[u] + G[u][v] == d[v]){
                if(w[v] < w[u] + Weight[v]){
                    w[v] = w[u] + Weight[v];
                }
                num[v] += num[u];
            }
        }
    }
}
int main(){
    //输入
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    fill(Weight , Weight+MAXV , 0);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",Weight + i);
    }

    int u,v;
    fill(G[0] , G[0]+MAXV*MAXV , INF);//G初始化
    for(int i = 0; i < m ; i++){
        scanf("%d%d",&u,&v);
        scanf("%d",&G[u][v]);
        G[v][u] = G[u][v];
    }

    dijkstra(c1);
    //输出
    printf("%d %d\n",num[c2],w[c2]);
}
