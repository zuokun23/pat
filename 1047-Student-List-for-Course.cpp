#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
const int maxk = 2505;
const int maxn = 40010;
vector<int> course[maxk];
char stu[maxn][5];//由索引->姓名二位字符数组,当由姓名->索引时hash
int n , k;

bool cmp(int a , int b){
	return strcmp(stu[a] , stu[b]) < 0;
}
//二位字符数组 + vector
int main(){
	
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i++){//i..n为学生对应的索引
		int cnt;
		scanf("%s %d",&stu[i],&cnt);
		for(int j = 0 ; j < cnt ; j++){
			int id;
			scanf("%d",&id);
			course[id].push_back(i);
		}
	}

	for(int i = 1 ; i <= k ; i++){
		
		printf("%d %d\n",i,course[i].size());
		sort(course[i].begin() , course[i].end() , cmp);
		for(int j = 0 ; j < course[i].size() ; j++){
			printf("%s\n",stu[course[i][j]]);
		}
	}
	return 0;
}
