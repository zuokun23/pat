//对于这种递归特别多的题 ， 注意小数据测试 来跟踪递归过程
/*如
1
1
或
3
1 2 3
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int val;
	node *left,*right;
};
int n;
vector<int> origin;//输入序列

int getHeight(node* root){//自底向上
	
	if(root == NULL)
		return 0;
	return max(getHeight(root->left) , getHeight(root->right)) + 1;
}

void L(node* &root){//左旋 请配合算法笔记中图食用 , 不要忘记加*&
	node* tmp = root->right;
	//1
	root->right = tmp->left;
	//2
	tmp->left = root;
	//3
	root = tmp;
}
void R(node* &root){//类似上函数
	node* tmp = root->left;
	//1
	root->left = tmp->right;
	//2
	tmp->right = root;
	//3
	root = tmp;
}
void insert(node *&root , int v){//递归
	
	if(root == NULL){
		root = new node();
		root->left = root->right = NULL;
		root->val = v;
		return;
	}

	if(v < root->val){
		insert(root->left , v);
		//根据高度获得平衡因子，来平衡二叉树
		if(getHeight(root->left) - getHeight(root->right)== 2){
			if(v < root->left->val){//getHeight(root->left->left) - getHeight(root->left->right) == 1){
				R(root);
			}else if(getHeight(root->left->left) - getHeight(root->left->right) == -1){//== -1
				L(root->left);
				R(root);
			}
		}
	}else{
		insert(root->right , v);
		if(getHeight(root->left) - getHeight(root->right)== -2){
			if(getHeight(root->right->left) - getHeight(root->right->right) == -1){
				L(root);
			}else if(getHeight(root->right->left) - getHeight(root->right->right) == 1){//== 1
				R(root->right);
				L(root);
			}
		}
	}
}

node* create(){

	node* root = NULL;
	for(int i = 0 ; i < n ; i++)
		insert(root , origin[i]);
	
	return root;
}
int main(){
	
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		int tmp;
		scanf("%d",&tmp);
		origin.push_back(tmp);
	}

	node* root = create();//创建平衡二叉搜索树

	printf("%d",root->val);
	return 0;
}
