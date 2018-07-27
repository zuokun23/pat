//方法一：Dijkstra
#include <cstdio>
#include <algorithm>

using namespace std;

const int INF = 100000000;
const int MAXV = 510;
int n,m,st,ed;//start end
int G[MAXV][MAXV],cost[MAXV][MAXV];
int d[MAXV];//1（距离）
bool vis[MAXV] = {false};//2（光明与黑暗）最重要的两个数组
int c[MAXV],pre[MAXV];//本题特色，最小cost与前一个城市

void Dijkstra(int s){

    fill(d, d+MAXV, INF);
    fill(c , c + MAXV , INF);
    for(int i = 0 ; i < n ;i++) pre[i] = i;
    d[s] = 0;
    c[s] = 0;

    for(int i = 0 ; i < n ;i++){

        int u = -1, min = INF;
        for(int j = 0 ; j < n ; j++){
            if(vis[j] == false && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;//找不到

        vis[u] = true;//标记为光明

        //更新
        for(int v = 0; v < n ;v++){

            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] +cost[u][v];
                    pre[v] = u;
                }else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
                    c[v] = c[u] + cost[u][v];
                    pre[v] = u;
                }
            }
        }
    }
}

void DFS(int v){//从终点开始递归

    if(v == st){
        printf("%d ",st);
        return;
    }

    DFS(pre[v]);
    printf("%d ",v);
    //类似后序遍历
}
int main(){

    scanf("%d%d%d%d",&n,&m,&st,&ed);
    fill(G[0] , G[0]+MAXV*MAXV , INF);
    //cost不用初始化，当某边为INF无法到达，不会去用第二标尺。
    fill(cost[0] , cost[0] + MAXV*MAXV , INF);
    for(int i = 0 ; i < m ; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        scanf("%d%d",&G[u][v],&cost[u][v]);
        G[v][u] = G[u][v];//无向图
        cost[v][u] = cost[u][v];
    }

    Dijkstra(st);

    //打印路径
    DFS(ed);
    printf("%d %d\n",d[ed],c[ed]);
    return 0;
}

//方法二：Dijkstra + DFS
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 100000000;
const int MAXV = 510;
int n,m,st,ed;//start end
int G[MAXV][MAXV],cost[MAXV][MAXV];
int minCost = INF;
int d[MAXV];//1（距离）
bool vis[MAXV] = {false};//2（光明与黑暗）最重要的两个数组
vector<int> pre[MAXV];
vector<int> path,tmpPath;

void Dijkstra(int s){

    fill(d, d+MAXV, INF);
    d[s] = 0;

    for(int i = 0 ; i < n ;i++){

        int u = -1, min = INF;
        for(int j = 0 ; j < n ; j++){
            if(vis[j] == false && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;//找不到

        vis[u] = true;//标记为光明

        //更新
        for(int v = 0; v < n ;v++){

            if(vis[v] == false && G[u][v] != INF){
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

void DFS(int v){//从终点开始递归

    if(v == st){
        tmpPath.push_back(v);
        //拿到一条完整的路径，对其进行分析
        int tmpCost = 0;
        for(int i = tmpPath.size()-1 ; i > 0 ; i--){
            tmpCost += cost[tmpPath[i]][tmpPath[i-1]];
        }
        if(tmpCost < minCost){
            minCost = tmpCost;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }

    tmpPath.push_back(v);//vector可以当栈用,前序的位置就要保存信息
    for(int i = 0 ; i < pre[v].size() ; i++){
        DFS(pre[v][i]);
    }
    tmpPath.pop_back();
}
int main(){

    scanf("%d%d%d%d",&n,&m,&st,&ed);
    fill(G[0] , G[0]+MAXV*MAXV , INF);
    //cost不用初始化，当某边为INF无法到达，不会去用第二标尺。
    fill(cost[0] , cost[0] + MAXV*MAXV , INF);
    for(int i = 0 ; i < m ; i++){
        int u,v;
        scanf("%d%d",&u,&v);
        scanf("%d%d",&G[u][v],&cost[u][v]);
        G[v][u] = G[u][v];//无向图
        cost[v][u] = cost[u][v];
    }

    Dijkstra(st);
    DFS(ed);

    //打印路径
    for(int i = path.size() - 1 ; i >= 0 ;i --)
        printf("%d ",path[i]);
    printf("%d %d\n",d[ed],minCost);
    return 0;
}
