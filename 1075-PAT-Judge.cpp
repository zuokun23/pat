//在牛客网上运行有部分测试用例没通过，在pat上全部跑过？
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

const int MAXS = 100000000;
int n , k , m;

struct User{
	int id;
	int pr[6];//每个问题得分-2为未做，-1表示编译未通过
	int sum , numOfPer;
	bool flag;//是否要打印=是否有通过编译的提交
}user[10010];

void init(){
	for(int i = 1 ;i <=n ; i++){//struct内pr初始化
		for(int j = 1 ; j <= k ;j++)
			user[i].pr[j] = -2;//表示未做
		user[i].sum = 0;
		user[i].numOfPer = 0;
		user[i].flag = false;
		user[i].id = i;
	}
}
bool cmp(User a , User b){

	if(a.sum != b.sum) return a.sum > b.sum;
	else if(a.numOfPer != b.numOfPer) return a.numOfPer > b.numOfPer;
	else return a.id < b.id;
}
int main(){
    
	
	int p[6];
	scanf("%d%d%d",&n,&k,&m);
	init();
	for(int i = 1 ; i <= k ; i++)
		scanf("%d",p+i);
	for(int i = 0 ; i < m ; i++){
		
		int u_id;
		int p_id,score;
		scanf("%d%d%d",&u_id,&p_id,&score);
		if(user[u_id].pr[p_id] <= score)
			user[u_id].pr[p_id] = score;
		if(score >= 0)
			user[u_id].flag = true;
	}
	for(int i = 1 ;i <=n ; i++){
		for(int j = 1 ; j <= k ;j++){
			if(user[i].pr[j] == -2 || user[i].pr[j] == -1)
				user[i].sum += 0;
			else if(user[i].pr[j] == p[j]){
				user[i].sum += user[i].pr[j];
				user[i].numOfPer +=1;
			}else
				user[i].sum += user[i].pr[j];
		}
	}

	sort(user+1 , user+n+1 ,cmp);

	int rank = 0 , tmpSum = MAXS;
	for(int i = 1 ; i <= n ;i++){
		if(user[i].flag == false)
			break;//后面的学生也全部为false
		if(user[i].sum < tmpSum){
			rank = i;
			tmpSum = user[i].sum;
		}
		printf("%d %05d %d",rank,user[i].id,user[i].sum);
		for(int j = 1 ; j <= k ; j++){
			if(user[i].pr[j] == -1)
				printf(" 0");
			else if(user[i].pr[j] == -2)
				printf(" -");
			else
				printf(" %d",user[i].pr[j]);
			if(j == k)
				printf("\n");
		}
	}
	return 0;
}
