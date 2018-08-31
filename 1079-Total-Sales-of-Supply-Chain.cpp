#include<cstdio>
#include<vector>
#include<cmath>

using namespace std;

const int maxn = 100010;
struct node{//静态树
	double data;
	vector<int> child;
}Node[maxn];
int n , len = -1;//len表示DFS过程中的当前长度,据题意，从-1开始
double p , r , ans = 0;//ans就是答案

void DFS(int root){//自顶向下地求长度
	len++;
	if(Node[root].child.size() == 0){
		ans += p*pow(r/100+1 , len)*Node[root].data;
		len--;//注意，前往别忘了这句
		return;
	}

	for(int i = 0 ; i < Node[root].child.size() ; i++)
		DFS(Node[root].child[i]);
	len--;
}
int main(){
	
	scanf("%d%lf%lf",&n,&p,&r);
	for(int i = 0 ; i < n ; i++){
		int cnt;
		scanf("%d",&cnt);
		if(cnt != 0){
			for(int j = 0 ; j < cnt ; j++){
				int tmp;
				scanf("%d",&tmp);
				Node[i].child.push_back(tmp);
			}
		}else
			scanf("%lf",&Node[i].data);
	}

	DFS(0);

	printf("%.1f",ans);
	return 0;
}
