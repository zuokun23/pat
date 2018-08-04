#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int MAXV = 100010;
vector<int> T[MAXV];//孩子表示法
int n ;
double p , r;
int maxDepth = -1 , maxNum = 0;

void DFS(int u , int& depth){
    depth += 1;
    if(T[u].size() == 0){
        if(depth > maxDepth) {
            maxDepth = depth;
            maxNum = 1;
        }else if(depth == maxDepth){
            maxNum += 1;
        }

        depth -= 1;
        return;
    }

    for(int i = 0 ; i < T[u].size() ; i++){
        DFS(T[u][i],depth);
    }
    depth -= 1;
}

int main(){
    int root;
    scanf("%d%lf%lf",&n,&p,&r);
    for(int i = 0 ; i < n ; i++){
        int tmp;
        scanf("%d",&tmp);
        if(tmp == -1)
            root = i;
        else
            T[tmp].push_back(i);//孩子表示法
    }

    int depth = 0;
    DFS(root , depth);

    printf("%.2f %d",p * pow(1 + r/100 , maxDepth-1) , maxNum);
    return 0;
}
