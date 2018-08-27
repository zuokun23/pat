//利用sort来解决链表问题
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100010;
struct Node{
	int addr;//因为要用sort，addr会与索引不同，因此要记录地址
	int data;
	int next;
	int noIn;//组内编号,sort要用
	int noOut;//组外编号
	bool flag;//是否在链表中
}nodes[maxn];
int s , n , k;

bool cmp1(Node a , Node b){
	if(a.flag == false || b.flag == false) 
		return a.flag > b.flag;
	else if(a.noOut != b.noOut)
		return a.noOut < b.noOut;
	else
		return a.noIn > b.noIn;
}
bool cmp2(Node a , Node b){
	return a.noIn < b.noIn;
}
int main(){
	//1一系列赋值\初始化
	for(int i = 0 ; i < maxn ; i++)
		nodes[i].flag = false;
	scanf("%d%d%d",&s,&n,&k);
	for(int i = 0 ; i < n ; i++){
		int addr , data , next;
		scanf("%d%d%d",&addr,&data,&next);//注意%c可以接受空格、换行，注意格式
		nodes[addr].addr = addr;
		nodes[addr].next = next;
		nodes[addr].data = data;
	}

	int p = s , cnt = 0;
	while(p != -1){
		nodes[p].flag = true;
		nodes[p].noOut = cnt / k;
		nodes[p].noIn = cnt % k;
		cnt++;
		p = nodes[p].next;
	}
	//2
	sort(nodes , nodes + maxn , cmp1);
	if(cnt != (cnt/k)*k)
		sort(nodes + (cnt/k)*k , nodes + cnt , cmp2);
	//3打印
	for(int i = 0 ; i < cnt ; i++){
		printf("%05d %d ",nodes[i].addr,nodes[i].data);
		if(i != cnt - 1)
			printf("%05d\n",nodes[i+1].addr);
		else
			printf("-1\n");
	}

	return 0;
}



//此解答有错误
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100010;
struct Node{
	int addr;//因为要用sort，addr会与索引不同，因此要记录地址
	int data;
	int next;
	int noIn;//组内编号,sort要用
	int noOut;//组外编号
	bool flag;//是否在链表中
}nodes[maxn];
int s , n , k;

bool cmp(Node a , Node b){
	if(a.flag == false || b.flag == false) 
		return a.flag > b.flag;
	else if(a.noOut != b.noOut)
		return a.noOut < b.noOut;
	else
		return a.noIn > b.noIn;
}
int main(){
	//1一系列赋值\初始化
	for(int i = 0 ; i < maxn ; i++)
		nodes[i].flag = false;
	scanf("%d%d%d",&s,&n,&k);
	for(int i = 0 ; i < n ; i++){
		int addr , data , next;
		scanf("%d%d%d",&addr,&data,&next);//注意%c可以接受空格、换行，注意格式
		nodes[addr].addr = addr;
		nodes[addr].next = next;
		nodes[addr].data = data;
	}

	int p = s , cnt = 0;
	while(p != -1){
		nodes[p].flag = true;
		nodes[p].noOut = cnt / k;
		nodes[p].noIn = cnt % k;
		cnt++;
		p = nodes[p].next;
	}
	//2
	sort(nodes , nodes + maxn , cmp);

	//3打印
	int t = (cnt/k)*k; 
	for(int i = 0 ; i < t ; i++){
		printf("%05d %d ",nodes[i].addr,nodes[i].data);
		if(i != cnt - 1)
			printf("%05d\n",nodes[i+1].addr);//这步出错了，反转的最后一个结点的下一个结点的打印出错
		else
			printf("-1\n");
	}
	for(int i = cnt - 1 ; i >= t ; i--){
		printf("%05d %d ",nodes[i].addr,nodes[i].data);
		if(i != t)
			printf("%05d\n",nodes[i-1].addr);
		else
			printf("-1\n");
	}
	return 0;
}
