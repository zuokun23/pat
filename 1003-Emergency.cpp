/////方法1：Dijkstra

#include<cstdio>
#include<queue>

using namespace std;

const int maxn = 510;
const int INF = 1 << 30;
int G[maxn][maxn];
bool vis[maxn] = {false};
int d[maxn];
int weight[maxn],w[maxn];//点权
int num[maxn];//路径数
int n ,m , c1 ,c2;

void Dijkstra(int s){
	
	fill(d , d+maxn , INF);
	d[s] = 0;
	fill(w , w+maxn , 0);
	w[s] = weight[s];
	fill(num , num+maxn , 0);
	num[s] = 1;

	for(int i = 0 ; i < n ; i++){
		int u = -1 , MIN = INF;
		for(int j = 0 ; j < n ; j++){
			if(vis[j] == false && d[j] < MIN){
				MIN = d[j];
				u = j;
			}
		}
		if(u == -1)
			return;

		vis[u] = true;

		for(int v = 0 ; v < n ; v++){
			if(vis[v] == false && G[u][v] != INF){
				if(d[u] + G[u][v] < d[v]){
					d[v] = d[u]+G[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}else if(d[u] + G[u][v] == d[v] ){
					if(w[v] < w[u] + weight[v]){
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}

int main(){
	
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&weight[i]);
	}
	fill(G[0] , G[0]+maxn*maxn , INF);
	for(int i = 0 ; i < m ; i++){
		int u , v , w;
		scanf("%d%d%d",&u,&v,&w);
		G[u][v] = G[v][u] = w;
	}

	Dijkstra(c1);

	printf("%d %d\n",num[c2],w[c2]);
	return 0;
}

//////方法2： Dijkstra + DFS
#include<iostream>
#include<vector>

using namespace std;
const int maxn = 510;
const int INF = 1000000000;
int G[maxn][maxn], w[maxn] = {0};
bool vis[maxn] = {false};
int d[maxn];
vector<int> pre[maxn];
int n,m,c1,c2;
vector<int> tmpPath , maxPath;
int maxWeight = -1 , tmpWeight , num = 0;

void Dijkstra(int s){

    fill(d , d+maxn , INF);
    d[s] = 0;
    for(int i = 0 ; i < n ;i++){
        int min = INF , u = -1;
        for(int j = 0 ; j < n ; j++){
            if(vis[j] == false && d[j] < min){
                u = j;
                min = d[j];
            }
        }
        if(u == -1) return;

        vis[u] = true;

        for(int v = 0 ; v < n ; v++){
            if(vis[v] == false && G[u][v] != INF) {
                if (d[u] + G[u][v] == d[v])
                    pre[v].push_back(u);
                else if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int s){

    tmpWeight += w[s];
    tmpPath.push_back(s);
    if(s == c1){
        if(tmpWeight > maxWeight){
            maxWeight = tmpWeight;
            maxPath = tmpPath;
        }
        num++;
        tmpWeight -= w[s];
        tmpPath.pop_back();
        return;
    }

    for(int i = 0 ; i < pre[s].size() ; i++){
        DFS(pre[s][i]);
    }
    tmpWeight -= w[s];
    tmpPath.pop_back();
    return;
}

int main(){

    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    
    for(int i = 0 ; i < n ; i++){
        int weight;
        scanf("%d",&weight);
        w[i] = weight;
    }
    fill(G[0] , G[0] + maxn*maxn , INF);
    for(int i = 0 ; i < m ; i++){
        int u,v ,weight;
        scanf("%d%d%d",&u,&v,&weight);
        G[u][v] = weight;
        G[v][u] = weight;
    }

    Dijkstra(c1);
    DFS(c2);
    printf("%d %d",num,maxWeight);

    return 0;
}
