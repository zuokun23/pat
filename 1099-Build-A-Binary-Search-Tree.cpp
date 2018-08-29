#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

const int maxn = 110;
struct node{//二叉树的静态表示
	int data;
	int lchild,rchild;
}Node[maxn];
int n , in[maxn] , pos = 0;//in为中序序列,pos为中序序列的一个访问索引

void inOrder(int root){
	if(root == -1)
		return;
	
	inOrder(Node[root].lchild);
	Node[root].data = in[pos++];//中序序列谁在前 谁先取值
	inOrder(Node[root].rchild);
}
void BFS(int root){//用queue
	//初始化
	queue<int> q;
	q.push(root);
	int cnt = 0 ;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		cnt++;
		printf("%d",Node[top].data);
		if(cnt != n)
			printf(" ");
		if(Node[top].lchild != -1)
			q.push(Node[top].lchild);
		if(Node[top].rchild != -1)
			q.push(Node[top].rchild);
	}
}
int main(){
	
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d%d",&Node[i].lchild,&Node[i].rchild);		
	
	for(int i = 0 ; i < n ;i++)
		scanf("%d",&in[i]);
	sort(in , in + n);//由小到大排序
	inOrder(0);//数结构+中序遍历->二叉树
	BFS(0);
	return 0;
}
