//参考https://www.liuchuo.net/archives/2331
#include <iostream>
#include <string>
#include <map>

using namespace std;

const int MAXV = 2010;//总人数
int G[MAXV][MAXV] = {0}, weight[MAXV] = {0};//边权和点权
map<string , int> strToInt;
map<int , string> intToStr;
map<string ,int> gang;//head,人数
int n , k , m = 0;//m总人数
bool vis[MAXV] = {false};

int change(string str) {//返回str对应的编号

    if(strToInt.find(str) == strToInt.end()) {//未找到
        strToInt[str] = m;
        intToStr[m] = str;
        return m++;//先返回再++
    }else{
        return strToInt[str];
    }
}

void DFS(int u , int& head , int& numMerber , int& edgeW){

    vis[u] = true;
    numMerber += 1;
    if(weight[u] > weight[head])
        head = u;
    for(int i = 0 ; i < m ; i++){
        if(G[u][i] != 0) {//能访问
            edgeW += G[u][i];
            G[u][i] = G[i][u] =0;
            if(vis[i] == false )
                DFS(i , head , numMerber , edgeW);
        }
    }
}

void DFSTrave(){

    for(int i = 0 ; i < m ; i++){
        if(vis[i] == false){
            int head = i , numMerber = 0 , edgeW = 0;//边权
            DFS(i , head ,numMerber , edgeW);
            if(numMerber > 2 && edgeW > k){
                gang[intToStr[head]] = numMerber;
            }
        }
    }
}
int main(){
    //本题涉及字符串的输入，最好还是用cin cout
    cin >> n >> k;
    string a,b;
    int w;
    for(int i = 0 ; i < n ; i++){
        cin >> a >> b >> w;
        int id1 = change(a);
        int id2 = change(b);
        G[id1][id2] += w;//注意可以叠加，测试用例1
        G[id2][id1] = G[id1][id2];//无向图
        weight[id1] += w;
        weight[id2] += w;
    }

    DFSTrave();//遍历整个图

    cout << gang.size() << endl;
    for(auto it = gang.begin() ; it != gang.end() ; it++){
        cout << it->first << " " << it->second <<endl;
    }

    return 0;
}
