#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int maxn = 1015;//因为n+m最多为1010
const int INF = 1000000000; 
int G[maxn][maxn];
bool vis[maxn];
int d[maxn];
int n , m , k , Ds;

void Dijkstra(int s){//起点
	//因为要diijkstra多次，所有要在算法内部赋初值
	fill(d , d+maxn , INF);
	d[s] = 0;
	fill(vis , vis+maxn , false);

	for(int i = 0 ; i < n+m ; i++){//循环n+m次
		//找u
		int minNum = INF , u = -1; 
		for(int j = 1 ; j <= n+m ; j++)
			if(vis[j] == false && d[j] < minNum){
				minNum = d[j];
				u = j;
			}
		if(u == -1)
			return;
		//u已经访问
		vis[u] = true;
		//更新d
		for(int v = 1 ; v <= n+m ; v++)
			if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] < d[v]){
				d[v] = d[u]+G[u][v];
			}
	}
}

int getInt(string str){
	if(str[0] != 'G')
		return stoi(str);//string->int
	else
		return n + stoi(str.substr(1 , str.size()-1));
}
int main(){
	//初始化
	fill(G[0] , G[0]+maxn*maxn , INF);//表示不可达
	cin >> n >> m >> k >> Ds;
	for(int i = 0 ; i < k ; i++){
		string a , b;
		int c;
		cin >> a >> b >> c;
		G[getInt(b)][getInt(a)] = G[getInt(a)][getInt(b)] = c;
	}
	
	double ansDis = -1 , ansAvg = INF;
	int ansID= -1;
	for(int i = n+1 ; i <= m+n ; i++){//枚举所有加油站
		
		Dijkstra(i);
		double minDis = INF , avg = 0;
		for(int j = 1 ; j <= n ; j++){//枚举所有房屋
			if(d[j] > Ds){
				minDis = -1;
				break;
			}
			minDis = min(minDis , 1.0*d[j]);
			avg += 1.0*d[j]/n;
		}
		if(minDis == -1) continue;//跳过该加油站
		if(minDis > ansDis){
			ansID = i;
			ansDis = minDis;
			ansAvg = avg;
		}else if(minDis == ansDis && avg < ansAvg ){
			ansID = i;
			ansAvg = avg;
		}//当条件一二相等时候，选取索引最小，不用更新
	}

	if(ansID == -1)//没找到
		printf("No Solution\n");
	else{
		printf("G%d\n",ansID-n);
		printf("%.1f %.1f\n",ansDis,ansAvg);
	}
	return 0;
}
