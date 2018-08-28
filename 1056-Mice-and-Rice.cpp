#include<cstdio>
#include<queue>

using namespace std;
const int maxn = 1010;
struct Mouse{
	int w;//质量
	int r;//排名
}mouse[maxn];

int main(){
	
	int np , ng , order;
	scanf("%d%d",&np,&ng);
	for(int i = 0 ; i < np ; i++){
		scanf("%d",&mouse[i].w);
	}
	queue<int> q;//定义一个队列
	for(int i = 0 ; i < np ; i++){
		scanf("%d",&order);
		q.push(order);
	}

	int tmp = np , group;//tmp为当前轮比赛老鼠总数 group为组数
	while(q.size() != 1){//等于1时找到冠军
		
		group = (tmp%ng==0) ? (tmp/ng) : (tmp/ng+1);
		//枚举每一组选出质量最大的
		for(int i = 0 ; i < group ;i++){
			
			int pos = q.front();
			//下一行中，i*ng+j+1<=tmp,(i*ng为前面i行总人数)+(j+1本行总人数)<=tmp总人数
			for(int j = 0 ; j < ng && i*ng+j < tmp; j++){//由于当前的是第i组，第j个
				if(mouse[q.front()].w > mouse[pos].w)
					pos = q.front();
				mouse[q.front()].r = group+1;//排名
				q.pop();
			}
			q.push(pos);
		}
		tmp = group;//特别注意，不要忘记这个，循环不变量
	}
	//当只剩下一个老鼠时
	mouse[q.front()].r = 1;
	
	//输出
	for(int i = 0 ; i < np ; i++){
		printf("%d",mouse[i].r);
		if(i != np-1)
			printf(" ");
	}
	return 0;
}
