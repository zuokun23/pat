#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
//用数组来存放完全二叉树，从1开始放
const int maxn = 1010;
int binTree[maxn];
vector<int> origin;//输入
int n , index = 0;//index是插入值的索引,origin从0开始

void inOrder(int root){
	if(root > n)
		return;

	inOrder(2*root);
	binTree[root] = origin[index++];
	inOrder(2*root + 1);
}
int main(){
	//根据树的结构+中序遍历
	int tmp;
	scanf("%d",&n);
	for(int i = 1 ; i <=n ; i++){
		scanf("%d",&tmp);
		origin.push_back(tmp);
	}
	sort(origin.begin() , origin.end());
	inOrder(1);//根结点

	for(int i = 1 ; i <= n ; i++){
		printf("%d",binTree[i]);
		if(i != n)
			printf(" ");
	}
	return 0;
}
