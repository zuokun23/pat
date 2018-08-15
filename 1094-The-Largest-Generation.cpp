//BFS 第一版可以应用到很多题目，第二版为针对此题优化
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

const int MAXN = 110;
int n , m;
//bool vis[MAXN] = {false};
int heightNum[MAXN] = {0};

struct node{
	int height;
	vector<int> child;
}Node[MAXN];

void BFS(){//利用BFS来完成高度的填写

	queue<int> q;
	q.push(1);
	//vis[1] = true;
	Node[1].height = 1;

	while(!q.empty()){
		
		int u = q.front();
		q.pop();

		for(int i = 0 ; i < Node[u].child.size() ; i++){
			int v = Node[u].child[i];
			Node[v].height = Node[u].height + 1;
			q.push(v);
		}
	}
}
int main(){
	
	scanf("%d%d",&n , &m);
	for(int i = 0 ; i < m ; i++){
		int father , numChild , child;
		scanf("%d%d",&father,&numChild);
		for(int j = 0 ; j < numChild ; j++){ 
			scanf("%d",&child);
			Node[father].child.push_back(child);
		}
	}

	BFS();

	for(int i = 1 ; i <= n ; i++){
		heightNum[Node[i].height]++;
	}
	int ret1 = 0,ret2=0;
	for(int i = 1 ; i <= n ; i++){
		if(heightNum[i] > ret2){
			ret1 = i;
			ret2 = heightNum[i];
		}
	}

	printf("%d %d",ret2,ret1);
	return 0;
}

//第二版BFS
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100];
int level[100];
int book[100];
int main() {
    int n, m, a, k, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&a, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[a].push_back(c);
        }
    }
    queue<int> q;
    q.push(1);
    level[1] = 1;
    while(!q.empty()) {
        int index = q.front();
        q.pop();
        book[level[index]]++;
        for(int i = 0; i < v[index].size(); i++) {
            level[v[index][i]] = level[index] + 1;
            q.push(v[index][i]);
        }
        
    }
    int maxnum = 0, maxlevel = 1;
    for(int i = 1; i < 100; i++) {
        if(book[i] > maxnum) {
            maxnum = book[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    return 0;
}

//3最容易理解的一种解法--利用DFS
#include <cstdio>
#include <vector>
using namespace std;
vector<int> v[100];
int book[100];
void dfs(int index, int level) {
    book[level]++;
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], level+1);
}
int main() {
    int n, m, a, k, c;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        scanf("%d %d",&a, &k);
        for(int j = 0; j < k; j++) {
            scanf("%d", &c);
            v[a].push_back(c);
        }
    }
    dfs(1, 1);
    int maxnum = 0, maxlevel = 1;
    for(int i = 1; i < 100; i++) {
        if(book[i] > maxnum) {
            maxnum = book[i];
            maxlevel = i;
        }
    }
    printf("%d %d", maxnum, maxlevel);
    return 0;
}
