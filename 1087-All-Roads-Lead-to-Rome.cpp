#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

const int INF = 100000000;
const int MAXV = 210;
int n,k;
string st;
int G[MAXV][MAXV],weight[MAXV];
map<string,int> id1;//city2no
map<int ,string> id2;//no2city
int d[MAXV];//1
bool vis[MAXV] = {false};//2
vector<int> pre[MAXV];//3
vector<int> path,tmpPath;
int num = 0,maxHap = 0 ,maxAvgHap = 0;//满足第一判据数,第二判据,第三判据

void Dijkstra(int s){
    fill(d , d+MAXV , INF);
    d[s] = 0;

    for(int i = 0 ; i < n ; i++){
        int u = -1,min = INF;
        for(int j = 0 ; j < n ; j++){
            if(vis[j] == false && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u == -1) return;

        vis[u] = true;

        for(int v = 0 ; v < n ; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] <d[v]){
                    d[v] = d[u] +G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u] + G[u][v] == d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void DFS(int v){
    tmpPath.push_back(v);
    if(v == id1[st]){
        num += 1;
        int hap = 0;
        int avgHap = 0;
        for(int i = tmpPath.size() - 2 ; i >= 0 ; i--){
            hap += weight[tmpPath[i]];
        }
        avgHap = hap / (tmpPath.size() - 1);
        if(hap > maxHap){
            maxHap = hap;
            maxAvgHap = avgHap;//不要丢掉此句
            path = tmpPath;
        }else if(hap == maxHap && avgHap > maxAvgHap){
            maxAvgHap = avgHap;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    for(int i = 0 ; i < pre[v].size() ;i++)
        DFS(pre[v][i]);
    tmpPath.pop_back();
}

int main(){
    scanf("%d%d",&n,&k);
    cin >> st;//注意字符串的输入
    id1.insert(make_pair(st,0));
    id2.insert(make_pair(0,st));
    for(int i = 1 ; i < n ; i++) {//n-1个点权
        string a;
        int b;
        cin >> a;
        scanf("%d",&b);
        //i为城市id号
        id1.insert(make_pair(a,i));
        id2.insert(make_pair(i,a));
        weight[i] = b;
    }
    fill(G[0] , G[0]+MAXV*MAXV , INF);
    for(int i = 0 ; i < k ; i++){
        string a,b;
        int c;
        cin >> a >> b;
        scanf("%d",&c);
        G[id1[a]][id1[b]] = c;
        G[id1[b]][id1[a]] = c;
    }

    Dijkstra(id1[st]);
    DFS(id1["ROM"]);

    printf("%d %d %d %d\n",num,d[id1["ROM"]],maxHap,maxAvgHap);
    for(int i = path.size() - 1 ; i > 0 ; i--){
        int id_tmp = path[i];
        //printf("%s->",id2[id_tmp]);
        cout<< id2[id_tmp] << "->";//输出string类型注意最好不用printf
    }
    printf("ROM\n");
}
