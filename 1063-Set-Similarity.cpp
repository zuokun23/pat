#include<cstdio>
#include<set>
#include<algorithm>

using namespace std;

const int maxn = 55;
set<int> record[maxn];
int n , m , k;

int main(){
	
	scanf("%d",&n);
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&m);
		int t;
		for(int j = 0 ; j < m ; j++){
			scanf("%d",&t);
			record[i].insert(t);
		}
	}

	scanf("%d",&k);
	for(int i = 0 ; i < k ; i++){
		int t1 , t2 , cnt = 0;
		scanf("%d%d",&t1,&t2);
		int len1 = record[t1].size(), len2 = record[t2].size();
		int select = len1 > len2 ? t2 : t1;//选择最短的一个进行遍历
		int noSelect = len1 > len2 ? t1 : t2;
		for(auto it = record[select].begin() ; it != record[select].end() ; it++){
			if(record[noSelect].find(*it) != record[noSelect].end())
				cnt++;
		}
		float ans = (1.0*cnt)/(len1+len2-cnt)*100;
		printf("%.1f%\n",ans);
	}
}
