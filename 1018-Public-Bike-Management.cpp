#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 100000000;
const int MAXV = 510;
int cMax , n , sp ,m;
int G[MAXV][MAXV],weight[MAXV];
int d[MAXV];//1
bool vis[MAXV] = {false};//2
vector<int> pre[MAXV];//3路径
vector<int> path,tmpPath;
int minNeed = INF,minBack = INF;//要带来 要带回去

void Dijkstra(int s){
    fill(d , d + MAXV , INF);
    d[s] = 0;
    for(int i = 0 ; i <= n ;i++){//特别注意，实际有n+1个点
        int u = -1 , min = INF;
        for(int j = 0 ; j <= n ;j++){
            if(vis[j] == false && d[j] < min) {
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;

        vis[u] = true;

        for(int v = 0 ; v <= n ; v++){
            if(vis[v] == false && G[u][v] != INF) {//u能到V

                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v){

    if(v == 0){
        tmpPath.push_back(0);
        int need = 0 , back = 0 , total = 0;
        for(int i = tmpPath.size() - 2; i >= 0; i--) {
            int id = tmpPath[i];
            if(weight[id] > 0) {
                back += weight[id];
            } else {
                if(back > (0 - weight[id])) {
                    back += weight[id];
                } else {
                    need += ((0 - weight[id]) - back);
                    back = 0;
                }
            }
        }
        if(need < minNeed){
            minNeed = need;
            minBack = back;
            path = tmpPath;
        }else if(need = minNeed && back < minBack){
            minBack = back;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(v);
    for(int i = 0 ; i < pre[v].size() ; i++){
        DFS(pre[v][i]);
    }
    tmpPath.pop_back();

}
int main(){

    scanf("%d%d%d%d",&cMax,&n,&sp,&m);

    for(int i = 1 ; i <= n ; i++){
        scanf("%d" , &weight[i]);
        weight[i] = weight[i] - cMax/2;
    }
    fill(G[0] , G[0]+MAXV*MAXV , INF);
    for(int i = 0 ; i < m ;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        scanf("%d",&G[u][v]);
        G[v][u]=G[u][v];//无向边
    }

    Dijkstra(0);
    DFS(sp);

    printf("%d ",minNeed);
    for(int i = path.size()-1 ; i >= 1 ;i--){
        printf("%d->",path[i]);
    }
    printf("%d ",path[0]);
    printf("%d\n",minBack);
}
