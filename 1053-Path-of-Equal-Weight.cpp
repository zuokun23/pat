//常规写法--不要看，直接看方法2
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 110;
struct node{
    int weight;
    vector<int> child;
} nodes[MAXN];
int n ,m ,s;
vector<vector<int>> path;
vector<int> tmpPath;
int weights = 0;

bool cmp(int a , int b){
    return nodes[a].weight > nodes[b].weight;
}

void DFS(int u){
    tmpPath.push_back(u);
    weights += nodes[u].weight;
    if(nodes[u].child.size() == 0){

        if(weights == s){
            path.push_back(tmpPath);
        }
        tmpPath.pop_back();
        weights -= nodes[u].weight;
        return;
    }

    for(int i = 0 ; i < nodes[u].child.size() ; i++){
        DFS(nodes[u].child[i]);
    }
    weights -= nodes[u].weight;
    tmpPath.pop_back();
}
int main(){

    scanf("%d%d%d",&n,&m,&s);
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &nodes[i].weight);
    }
    int id,num,child;
    for(int i = 0 ;i < m ; i++){
        scanf("%d%d",&id,&num);
        for(int j = 0 ;j < num ; j++){
            scanf("%d" , &child);
            nodes[id].child.push_back(child);
        }
        sort(nodes[id].child.begin() , nodes[id].child.end() , cmp);
    }

    DFS(0);

    for(int i = 0 ; i < path.size() ; i++){
        for(int j = 0 ; j < path[i].size() ; j++)
            printf("%d ",nodes[path[i][j]].weight);
        printf("\n");
    }
}
//方法2--DFS中使用sum来提前终止递归，又叫剪枝，见算法笔记p305
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXN = 110;
struct node{
	int weight;
	vector<int> child;
}nodes[MAXN];
int n , m ,s;
vector<int> path;//用来存储路径
int sum = 0;//路径和

bool cmp(int a , int b){
	return nodes[a].weight > nodes[b].weight;
}
void DFS(int u){
	path.push_back(u);
	sum += nodes[u].weight;
	if(sum == s){
		if(nodes[u].child.size() == 0){
			for(int i = 0 ; i < path.size() ; i++){
				printf("%d",nodes[path[i]].weight);
				if(i != path.size() -1)
					printf(" ");
				else
					printf("\n");
			}
		}//不等于0时直接返回	
	}else if(sum < s){
		for(int i = 0 ; i < nodes[u].child.size() ; i++){
			DFS(nodes[u].child[i]);
		}
	}//sum < s时直接返回

	path.pop_back();
	sum -= nodes[u].weight;
	return;
}
int main(){

	scanf("%d%d%d",&n,&m,&s);
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &nodes[i].weight);
    }
    int id,num,child;
    for(int i = 0 ;i < m ; i++){
        scanf("%d%d",&id,&num);
        for(int j = 0 ;j < num ; j++){
            scanf("%d" , &child);
            nodes[id].child.push_back(child);
        }
        sort(nodes[id].child.begin() , nodes[id].child.end() , cmp);
    }

	DFS(0);

	return 0;
}
