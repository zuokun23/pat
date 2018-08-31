//广度优先遍历--本题使用邻接矩阵，也可采用邻接链表法
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

const int maxn = 1010;
const int INF = 1000000000;
bool G[maxn][maxn] = {false};//G[i][j]表示是否存在i->j的边
int level[maxn];//每次遍历的广度
bool vis[maxn] = {false};//已经访问过了
int n , l , ans;//ans答案

void BFS(int s){
	
	queue<int> q;
	q.push(s);
	level[s] = 0; 
	while(!q.empty()){
		
		int u = q.front();
		q.pop();
		if(level[u] > l)//是L不是1
			break;//由于先输出所有层i-1再层i，有一个层>l,则后面全部>l
		if(u != s)	ans++;

		for(int v = 1 ; v <= n ; v++)
			if(G[u][v] == true && vis[v] == false){
				q.push(v);
				vis[v] = true;
				level[v] = level[u] + 1;
			}
	}
}
int main(){
			
	scanf("%d%d",&n,&l);
	for(int i = 1 ; i <= n ; i++){
		int cnt;
		scanf("%d",&cnt);
		for(int j = 0 ; j < cnt ; j++){
			int tmp;
			scanf("%d",&tmp);
			G[tmp][i] = true;
		}
	}

	int k;
	scanf("%d",&k);
	for(int i = 0 ; i < k ; i++){
		int s;
		scanf("%d",&s);

		ans = 0;
		fill(level , level+maxn , INF);
		fill(vis , vis+maxn , false);
		BFS(s);
		printf("%d\n",ans);
	}
	return 0;
}
