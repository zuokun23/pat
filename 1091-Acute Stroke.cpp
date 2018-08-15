#include <iostream>
#include <queue>

using namespace std;

struct node{
    int x, y ,z;
    node(int x ,int y ,int z):x(x),y(y),z(z){}
};
int m , n ,l , t;
int arr[1300][130][80];
bool vis[1300][130][80] = {false};
int X[6] = {0 , 0 , 0 , 0 , 1 , -1 };
int Y[6] = {0 , 0 , 1 , -1 , 0 , 0 };
int Z[6] = {1 , -1 , 0 , 0 , 0 , 0 };

bool judge(int x ,int y ,int z){
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
    if(arr[x][y][z] == 0 || vis[x][y][z] == true) return false;
    return true;
}
int BFS(int x , int y ,int z){

    //初始化
    queue<node> q;
    vis[x][y][z] = true;
    q.push(node(x,y,z));
    int ret = 0 ;

    while(!q.empty()){

        node top = q.front();
        q.pop();
        ret += 1;

        for(int i = 0 ; i < 6 ; i++){//访问可到达且未访问的
            int tx = top.x + X[i];
            int ty = top.y + Y[i];
            int tz = top.z + Z[i];
            if(judge(tx, ty ,tz)){
                q.push(node(tx , ty , tz));
                vis[tx][ty][tz] = true;
            }
        }
    }

    if(ret >= t)
        return ret;
    else
        return 0;
}
int main(){

    scanf("%d%d%d%d",&m,&n,&l,&t);
    for(int i = 0 ; i < l ; i++)//z
        for(int j = 0 ; j < m ; j++)//x
            for(int k = 0 ; k < n ; k++)//y
                scanf("%d",&arr[j][k][i]);

    int ans = 0;
    for(int i = 0 ; i < l ; i++)//z
        for(int j = 0 ; j < m ; j++)//x
            for(int k = 0 ; k < n ; k++)//y
                if(vis[j][k][i] == false && arr[j][k][i] == 1)//有肿瘤块且未被访问
                    ans += BFS(j , k , i);

    printf("%d",ans);
    return 0;
}
