//更常见的作法
#include<cstdio>
#include<algorithm>

using namespace std;

struct Node{
	int key;
	int next;
	//Node(int _key , int _next):key(_key),next(_next){}
};
Node list[100010];
bool key[1000010] = {false};
int head , n;

void printList(int i){
	while(i != -1){
		printf("%05d %d ",i , list[i].key);
		if(list[i].next == -1)
			printf("-1\n");
		else
			printf("%05d\n",list[i].next);
		i = list[i].next;
	}
}
int main(){
	
	scanf("%d%d",&head,&n);
	list[100001].key = 0 , list[100001].next = head;//链表1虚拟头节点
	list[100002].key = 0 , list[100002].next = 0;//链表2

	for(int i = 0 ; i < n ; i++){
		int addr , key , next;
		scanf("%d%d%d",&addr,&key,&next);
		//list.insert(make_pair( addr,Node(key,next)));
		list[addr].key = key;
		list[addr].next = next;
	}
	int now = head , pre1 = 100001 , pre2 = 100002;//链表2长度
	while(now != -1){
		int t = list[now].key;
		if(key[abs(t)] == false){
			
			list[pre1].next = now;//连接
			//循环不变量
			pre1 = now;
			now = list[now].next;
			list[pre1].next = -1;//为了最后一个节点不用去手动赋值
			key[abs(t)] = true;
		}else{
			list[pre2].next = now;//连接
			//循环不变量
			pre2 = now;
			now = list[now].next;
			list[pre2].next = -1;
		}
	}

	//打印
	int i = list[100001].next , j = list[100002].next;  
	printList(i);
	printList(j);
	return 0;
}
//别人的代码https://www.liuchuo.net/archives/2118
#include <cstdio>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn = 100000;
struct NODE {
    int address, key, next, num = 2 * maxn;
}node[maxn];
bool exist[maxn];
int cmp1(NODE a, NODE b){
    return a.num < b.num;
}
int main() {
    int begin, n, cnt1 = 0, cnt2 = 0, a;
    scanf("%d%d", &begin, &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        scanf("%d%d", &node[a].key, &node[a].next);
        node[a].address = a;
    }
    for(int i = begin; i != -1; i = node[i].next) {
        if(exist[abs(node[i].key)] == false) {
            exist[abs(node[i].key)] = true;
            node[i].num = cnt1;
            cnt1++;
        }
        else {
            node[i].num = maxn + cnt2;
            cnt2++;
        }
    }
    sort(node, node + maxn, cmp1);
    int cnt = cnt1 + cnt2;
    for(int i = 0; i < cnt; i++) {
        if(i != cnt1 - 1 && i != cnt - 1) {
            printf("%05d %d %05d\n", node[i].address, node[i].key, node[i+1].address);
        } else {
            printf("%05d %d -1\n", node[i].address, node[i].key);
        }
    }
    return 0;
}
