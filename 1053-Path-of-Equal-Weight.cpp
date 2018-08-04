//常规写法
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
//2DFS中使用sum来提前终止递归，又叫剪枝，见算法笔记p305
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

void DFS(int u){//对此处进行了修改
    tmpPath.push_back(u);
    weights += nodes[u].weight;
    if(weights == s){
        if(nodes[u].child.size() == 0)
            path.push_back(tmpPath);
    }else if(weights < s){
        for(int i = 0 ; i < nodes[u].child.size() ; i++){
            DFS(nodes[u].child[i]);
        }
    }
    weights -= nodes[u].weight;
    tmpPath.pop_back();
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

    for(int i = 0 ; i < path.size() ; i++){
        for(int j = 0 ; j < path[i].size() ; j++)
            printf("%d ",nodes[path[i][j]].weight);
        printf("\n");
    }
}
