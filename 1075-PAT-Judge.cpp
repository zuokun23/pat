#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int rank, id, total = 0;
    vector<int> score;
    int passnum = 0;
    bool isshown = false;
};
bool cmp1(node a, node b) {
    if(a.total != b.total)
        return a.total > b.total;
    else if(a.passnum != b.passnum)
        return a.passnum > b.passnum;
    else
        return a.id < b.id;
}

int main() {
    int n, k, m, id, num, score;
    scanf("%d %d %d", &n, &k, &m);
    vector<node> v(n + 1);
    for(int i = 1; i <= n; i++)
        v[i].score.resize(k + 1, -1);
    vector<int> full(k + 1);
    for(int i = 1; i <= k; i++)
        scanf("%d", &full[i]);
    for(int i = 0; i < m; i++) {
        scanf("%d %d %d", &id, &num, &score);
        v[id].id = id;
        v[id].score[num] = max(v[id].score[num], score);
        if(score != -1)
            v[id].isshown = true;
        else if(v[id].score[num] == -1)
            v[id].score[num] = -2;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(v[i].score[j] != -1 && v[i].score[j] != -2)
                v[i].total += v[i].score[j];
            if(v[i].score[j] == full[j])
                v[i].passnum++;
        }
    }
    sort(v.begin() + 1, v.end(), cmp1);
    for(int i = 1; i <= n; i++) {
        v[i].rank = i;
        if(i != 1 && v[i].total == v[i - 1].total)
            v[i].rank = v[i - 1].rank;
    }
    for(int i = 1; i <= n; i++) {
        if(v[i].isshown == true) {
            printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
            for(int j = 1; j <= k; j++) {
                if(v[i].score[j] != -1 && v[i].score[j] != -2)
                    printf(" %d", v[i].score[j]);
                else if(v[i].score[j] == -1)
                    printf(" -");
                else
                    printf(" 0");
            }
            printf("\n");
        }
    }
    return 0;
}


//在牛客网上运行有部分测试用例没通过，在pat上全部跑过？
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10010;
struct User{
	int id , sum ,score[6],numFull ;
	//总分数sum , 每个问题的分数score,满分数量numFull
	bool flag;
}user[maxn];
int fullMark[6];
int n , k , m;

bool cmp(User a , User b){
	if(a.sum != b.sum)	return a.sum > b.sum;
	else if(a.numFull != b.numFull)	return a.numFull > b.numFull;
	return a.id < b.id;
}
int main(){
	
	scanf("%d%d%d",&n,&k,&m);
	//初始化
	for(int i = 1 ; i <= n ; i++){
		fill(user[i].score+1 , user[i].score+k+1 , -2);//初始化为未提交-2,编译未通过是-1
		user[i].id = i;
		user[i].sum = 0;
		user[i].numFull = 0;
		user[i].flag = false;//是否打印
	}
	for(int i = 1 ; i <= k ; i++)
		scanf("%d",&fullMark[i]);
	for(int i = 1 ; i <= m ; i++){
		int t1 , t2 ,mark;
		scanf("%d%d",&t1,&t2);
		scanf("%d",&mark);
		if(mark >= 0){
			if(mark == fullMark[t2] && user[t1].score[t2] != mark)//防止同用户通体提交多次满分
				user[t1].numFull++;
			if(user[t1].score[t2] < mark){
				user[t1].sum += user[t1].score[t2] >= 0 ? (0 - user[t1].score[t2] + mark):mark;				
				user[t1].score[t2] = mark;			
			}
			user[t1].flag = true;//要打印
		}else if(mark == -1 && user[t1].score[t2] == -2)
			user[t1].score[t2] = mark;
	}

	//排序
	sort(user+1 , user+n+1 , cmp);
	
	//打印：注意sum==0的中编译没通过一个或未提交的不打印
	int preSum = -1 , rank = 1;
	for(int i = 1 ; i <= n ; i++){
		if(user[i].flag == false)
			break;
		if(user[i].sum != preSum){
			printf("%d ",i);
			rank = i;
		}else
			printf("%d ",rank);//rank
		preSum = user[i].sum;
		printf("%05d %d",user[i].id,user[i].sum);//id
		for(int j = 1 ; j <= k ; j++){//score
			if(user[i].score[j] >= 0)//编译失败也要打印
				printf(" %d",user[i].score[j]);
			else if(user[i].score[j] == -1)
				printf(" 0");
			else	
				printf(" -");
		}
		printf("\n");
	}
	return 0;
}
