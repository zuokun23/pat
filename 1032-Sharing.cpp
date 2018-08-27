//方法1：比方法2更好，更简便，但是方法2思想很值得了解
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100010;
struct Node{
	char data;
	int next;
	bool flag;
}nodes[maxn];
int n , s1 , s2;

int main(){
	
	scanf("%d%d%d",&s1,&s2,&n);
	for(int i = 0 ; i < n ; i++){
		int addr , next;
		char c;
		scanf("%d %c %d",&addr,&c,&next);//注意%c可以接受空格、换行，注意格式
		nodes[addr].next = next;
		nodes[addr].data = c;
	}
	//遍历两次即可
	int p;
	for(p = s1 ; p != -1 ; p = nodes[p].next)
		nodes[p].flag = true;
	for(p = s2 ; p != -1 ; p = nodes[p].next)
		if(nodes[p].flag == true)
			break;
	if(p == -1)
		printf("-1");
	else
		printf("%05d",p);

	return 0;
}


//  方法2 ：以前做过王道数据结构链表中一题，思想就是一个Y字
#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100010;
struct Node{
	int addr;
	char data;
	int next;
}nodes[maxn];
int n , s1 , s2;

int main(){
	
	scanf("%d%d%d",&s1,&s2,&n);
	for(int i = 0 ; i < n ; i++){
		int addr , next;
		char c;
		scanf("%d %c %d",&addr,&c,&next);//注意%c可以接受空格、换行，注意格式
		nodes[addr].addr = addr;
		nodes[addr].next = next;
		nodes[addr].data = c;
	}
	//统计两链表长度
	int cur1 = s1 , cur2 = s2 , cnt1 = 0 , cnt2 = 0;
	while(cur1 != -1){
		cnt1++;
		cur1 = nodes[cur1].next;
	}
	while(cur2 != -1){
		cnt2++;
		cur2 = nodes[cur2].next;		
	}
	//
	cur1 = s1 , cur2 = s2;
	if(cnt1 > cnt2)
		for(int i = 0 ; i < cnt1 - cnt2 ; i++)
			cur1 = nodes[cur1].next;
	else if(cnt1 < cnt2)
		for(int i = 0 ; i < cnt2 - cnt1 ; i++)
			cur2 = nodes[cur2].next;
    
    int ret = -1;
	while(cur1 != -1){//和cur2 != -1一个意思
		if(nodes[cur1].addr == nodes[cur2].addr){//小心：是addr相同，不是数值
            printf("%05d\n",nodes[cur1].addr);
            return 0;
        }
		cur1 = nodes[cur1].next;
		cur2 = nodes[cur2].next;		
	}
	printf("-1\n");
	return 0;
}
