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
int X[6] = {};
int Y[6] = {};
int Z[6] = {};

int BFS(int x , int y ,int z){

    //初始化
    queue<node> q;
    vis[x][y][z] = true;
    q.push(node(x,y,z));

    while(!q.empty()){

        node top = q.front();
        q.pop();
        for(int i = 0 ; i < 6 ; i++){//访问可到达且未访问的
            int tx = top.x + X[i];
            int ty = top.y + Y[i];
            int tz = top.z + Z[i];

        }
    }
}
int main(){

    scanf("%d%d%d%d",&m,&n,&l,&t);
    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < m ; j++)
            for(int k = 0 ; k < l ; k++)
                scanf("%d",&arr[i][j][k]);

    int ans = 0;
    for(int i = 0 ; i < m ; i++)
        for(int j = 0 ; j < m ; j++)
            for(int k = 0 ; k < l ; k++)
                if(vis[i][j][k] == false && arr[i][j][k] == 1)//有肿瘤块且未被访问
                    ans += BFS(i , j , k);

    printf("%d",ans);
    return 0;
}
