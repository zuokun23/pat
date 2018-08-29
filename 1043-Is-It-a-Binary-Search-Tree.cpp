//方法1：创建二叉搜索树，然后进行比较，看起来此方法比方法2麻烦，但此方法很多函数代码是相似的，思路不复杂
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

//方法2
/*分析：假设它是二叉搜索树，一开始isMirror为FALSE，
根据二叉搜索树的性质将已知的前序转换为后序，转换过程中，
如果发现最后输出的后序数组长度不为n，那就设isMirror为true，
然后清空后序数组，重新再转换一次（根据镜面二叉搜索树的性质），
如果依旧转换后数组大小不等于n，就输出no否则输出yes*/
#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;
        while(j > root && pre[root] <= pre[j]) j--;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        while(j > root && pre[root] > pre[j]) j--;
    }
    if(i - j != 1) return ;
    getpost(root + 1, j);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}
