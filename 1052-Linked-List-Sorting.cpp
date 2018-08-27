//我发现很多链表题都可以用此模板 ，此模板下更像排序题 ，用链表思想去解题会很麻烦。 
本题有几个需要改进的，我用maxn作为区分是否在链表中，用 bool flag(注意cmp函数的改变)更简单方便，详情见算法笔记实战p274
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100010;
struct Node{
	int addr;
	int key;
	int next;
	//Node(int _addr , int _key , int _next):addr(_addr),key(_key),next(_next){}
}list[maxn];
int n , start;

bool cmp(Node a , Node b){
	return a.key < b.key;
}
//核心思想对key赋值来利用sort排序
int main(){

	//1.1主要是让不在链表上点无效
	for(int i = 0 ; i <maxn ; i++){
		list[i].key = maxn*2;//刚开始均为无效结点
	}
	scanf("%d%d",&n,&start);
	//1.2
	for(int i = 0 ; i < n ; i++){
		int addr,key,next;
		scanf("%d%d%d",&addr,&key,&next);
		list[addr].addr = addr;
		list[addr].key = key + 2*maxn;//为了区分无效结点
		list[addr].next = next;
	}
	//1.3
	int cur = start , cnt = 0;
	while(cur != -1){
		list[cur].key -= 2*maxn;
		cur = list[cur].next;
		cnt += 1;
	}

	//2
	sort(list , list + maxn , cmp);
	
	//3
	if(cnt == 0){
		printf("0 -1");
		return 0;
	}
	printf("%d %05d\n",cnt,list[0].addr);
	for(int i = 0 ; i < cnt ; i++){
		printf("%05d %d ",list[i].addr,list[i].key);
		if(i == cnt-1)
			printf("-1\n");
		else
			printf("%05d\n",list[i+1].addr);
	}
	return 0;
}
