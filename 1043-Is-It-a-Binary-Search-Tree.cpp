//方法1：创建二叉搜索树，然后进行比较
#include<cstdio>
#include<vector>

using namespace std;

struct node{
	int data;//数据域
	node *left , *right;//指针域
};
vector<int> origin , pre , post , preM , postM;

void insert(node* &root , int data){
	if(root == NULL){
		root = new node;
		root->data = data;
		root->left = root->right = NULL;
		return;
	}

	if(data < root->data)
		insert(root->left , data);
	else
		insert(root->right , data);

}

void preOrder(node* root , vector<int> &vi){//先序遍历，结果都存在vi
	
	if(root == NULL)
		return;
	vi.push_back(root->data);
	preOrder(root->left , vi);
	preOrder(root->right , vi);
}
void postOrder(node* root , vector<int> &vi){
	if(root == NULL)
		return;
	postOrder(root->left , vi);
	postOrder(root->right , vi);
	vi.push_back(root->data);
}
void preOrderMirror(node* root , vector<int> &vi){//先序遍历，结果都存在vi
	
	if(root == NULL)
		return;
	vi.push_back(root->data);
	preOrderMirror(root->right , vi);
	preOrderMirror(root->left , vi);

}
void postOrderMirror(node* root , vector<int> &vi){
	if(root == NULL)
		return;
	postOrderMirror(root->right , vi);
	postOrderMirror(root->left , vi);
	vi.push_back(root->data);
}
int main(){
	
	int n , data;
	node* root = NULL;//定义头结点
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&data);
		origin.push_back(data);
		insert(root,data);
	}
	preOrder(root , pre);
	preOrderMirror(root , preM);
	postOrder(root , post);
	postOrderMirror(root , postM);
	if(origin == pre){//初始序列 == 先序序列
		printf("YES\n");
		for(int i = 0 ; i < post.size() ; i++){
			printf("%d",post[i]);
			if(i != post.size() - 1)
				printf(" ");
		}
	}else if(origin == preM){//初始序列 == 先序序列的镜像
		printf("YES\n");
		for(int i = 0 ; i < postM.size() ; i++){
			printf("%d",postM[i]);
			if(i != postM.size() - 1)
				printf(" ");
		}
	}else
		printf("NO\n");
	return 0;
}
