//
#include<cstdio>
#include<unordered_set>
#include<vector>
using namespace std;
const int maxn = 10010;
struct edge{
	int v1 , v2;
};
int color[maxn];

int main(){
	
	//fill(G[0] , G[0]+maxn*maxn , 0);
	int n , m;
	scanf("%d%d",&n,&m);
	vector<edge> edg;
	for(int i = 0 ; i < m ; i++){
		int u , v;
		scanf("%d %d",&u,&v);
		edg.push_back({u,v});//edg[i].v1 = u;
	}	
	int k;
	scanf("%d",&k);
	for(int i = 0 ; i < k ; i++){
		bool flag = true;;
		unordered_set<int> se;
		for(int j = 0 ; j < n ; j++){
			scanf("%d",&color[j]);
			se.insert(color[j]);
		}
		for(int j = 0 ; j < edg.size() ; j++){
			if(color[edg[j].v1] == color[edg[j].v2]){
				flag = false;
				break;
			}
		}
		if(flag == false){
			printf("No\n");
		}else{
			printf("%d-coloring\n",se.size());
		}
	}
	return 0;
}

//此版本只能通过两个例子
#include<cstdio>
#include<unordered_set>
using namespace std;
const int maxn = 10010;
int G[maxn][maxn] = {0};
int color[maxn];

int main(){
	
	//fill(G[0] , G[0]+maxn*maxn , 0);
	int n , m;
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < m ; i++){
		int u , v;
		scanf("%d %d",&u,&v);
		G[u][v] = G[v][u] = 1;
	}	
	int k;
	scanf("%d",&k);
	for(int i = 0 ; i < k ; i++){
		bool flag = true;;
		unordered_set<int> se;
		for(int j = 0 ; j < n ; j++){
			scanf("%d",&color[j]);
			se.insert(color[j]);
		}
		for(int j = 0 ; j < n ; j++){
			for(int k = 0 ; k < n ; k++){
				if(G[j][k] == 1 && color[j] == color[k]){
					flag = false;
                    break;
				}
			}
		}
		if(flag == false){
			printf("No\n");
		}else{
			printf("%d-coloring\n",se.size());
		}
	}
	return 0;
}
