#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct Student{
	
	int GE,GI,sum;
	int id;
	int rank;//名次
	vector<int> k;//填写的志愿

}stu[40010];

struct School{
	
	int quota;//名额
	int lastRank;//上一个被录取的名次
	vector<int> admit;//录取
}sch[110];
int n , m ,k;

bool cmp(Student a , Student b){
	
	if(a.sum != b.sum) return a.sum > b.sum;
	else return a.GE > b.GE;
}

int main(){

	scanf("%d%d%d",&n,&m,&k);
	for(int i = 0 ; i < m ; i++)
		scanf("%d",&sch[i].quota);
	for(int i = 0 ; i < n ; i++){
		stu[i].id = i;
		scanf("%d%d",&stu[i].GE,&stu[i].GI);
		stu[i].sum = stu[i].GE + stu[i].GI;
		int t1;
		for(int j = 0 ; j < k ;j++){
			scanf("%d",&t1);
			stu[i].k.push_back(t1);
		}
	}

	sort(stu , stu+n , cmp);//排序
	//排好序后对rank进行赋值
	stu[0].rank = 1;//名次从1开始
	for(int i = 1 ; i < n ; i++){
		if(stu[i].sum == stu[i-1].sum && stu[i].GE == stu[i-1].GE)
			stu[i].rank = stu[i-1].rank;
		else
			stu[i].rank = i+1;
	}

	//学校的录取过程
	for(int i = 0 ; i < n ;i++){
		
		int j;
		for(j = 0 ; j < k ; j++){
			int t2 = stu[i].k[j];
			if(sch[t2].quota > 0 || sch[t2].quota < 1 && sch[t2].lastRank == stu[i].rank){//特别注意不是sch[t2].quota == 1，可能超额录取1个以上 
				sch[t2].quota--;
				sch[t2].admit.push_back(stu[i].id);//录取
				sch[t2].lastRank = stu[i].rank;
				break;
			}
		}
		//if(j == k);这名学生没人要
	}

	//打印各个学校录取情况
	for(int i = 0 ; i < m ; i++){
		
		sort(sch[i].admit.begin() , sch[i].admit.end());
		for(int j = 0 ; j < sch[i].admit.size(); j++){
			printf("%d",sch[i].admit[j]);
			if(j != sch[i].admit.size()-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
