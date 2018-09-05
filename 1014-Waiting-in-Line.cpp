#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

const int maxNode = 1111;
int n , m , k ,query , q;
struct Window{
	//窗口当前队伍的最后服务时间，队首客户的服务结束时间
	int endTime,popTime;
	queue<int> q;//队列
}window[20];
int ans[maxNode] , needTime[maxNode];//服务结束时间和服务需要时间

int convertToMinute(int h , int m){
	return h*60 + m;
}
//核心：某一客户结束时间 = 队伍所有人（包括自己）的服务时间之和
int main(){

	int inIndex = 0;//当前第一个未入队的客户编号
	//窗口数、窗口人数上限，客户数，查询数
	scanf("%d%d%d%d",&n,&m,&k,&query);
	for(int i = 0 ; i< k ;i++){
		scanf("%d",&needTime[i]);
	}
	for(int i = 0 ; i < n ; i++){//初始化为8点
		window[i].popTime = window[i].endTime = convertToMinute(8 , 0); 
	}

	//先直接入队，都直接进入黄线
	for(int i= 0 ; i < min(n*m , k) ; i++){//注意min
		window[inIndex % n].q.push(inIndex);//先插入每个窗口的位置0
		//更新
		window[inIndex % n].endTime += needTime[inIndex];
		ans[inIndex] = window[inIndex%n].endTime;
		if(inIndex < n)//每个窗口第0位插入时
			window[inIndex].popTime = ans[inIndex];
		inIndex++;
	}
	//处理剩下的客户的入队
	for(;inIndex < k ; inIndex++){
		//哪队先结束
		int idx = -1 , minPopTime = 1 << 30;//几乎是最大整数--二级制1后面30个0
		for(int i = 0 ; i < n ; i++){
			if(window[i].popTime < minPopTime){
				minPopTime = window[i].popTime;
				idx = i;
			}
		}
		//更新
		Window &W = window[idx];
		W.q.pop();
		W.q.push(inIndex);
		W.endTime += needTime[inIndex];
		ans[inIndex] = W.endTime;
		W.popTime += needTime[W.q.front()];
	}

	for(int i = 0 ; i < query ; i++){
		scanf("%d",&q);
		if(ans[q-1] - needTime[q-1] >= convertToMinute(17 , 0))
			printf("Sorry\n");
		else
			printf("%02d:%02d\n",ans[q-1]/60, ans[q-1]%60);
	}
	return 0 ;
}
