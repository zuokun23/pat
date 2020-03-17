#include<cstdio>
#include<vector>

using namespace std;

const int maxn = 110;
vector<int> G[maxn];
int n , m , res[maxn] = {0};//res储存每层无孩子的成员数 
int high = 0 , maxhigh = 0; 

void dfs(int s){
	if(G[s].size() == 0){
		high++;
		if(high > maxhigh)
			maxhigh = high;
		res[high]++;
		
		high--;
		return;
	}
	high++;
	for(int i = 0 ; i < G[s].size() ; i++){
		dfs(G[s][i]);
	}
	high--;
}

int main(){
	
	scanf("%d%d",&n,&m);
	int father,num,son;
	for(int i = 0 ; i < m ; i++){
		
		scanf("%d%d",&father,&num);
		for(int j = 0 ; j < num ; j++){
			scanf("%d",&son);
			G[father].push_back(son);
		}
	}
	
	dfs(1);
	
	for(int i = 1 ; i <= maxhigh ; i++){
		if(i == 1)
			printf("%d",res[1]);
		else
			printf(" %d",res[i]);
	}	
	return 0;
}
