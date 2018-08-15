#include<cstdio>
 
using namespace std;
 
int hashTable[1005];//不能只开500空间会段错误 ， 虽然钱面值《=500，但 m-i会大于500，算法笔记实战p147
int main(){
 
    int n ,m;
    scanf("%d%d",&n,&m);
    for(int i = 0 ; i < n ; i++){
        int t;
        scanf("%d",&t);
        hashTable[t]++;
    }
 
    for(int i = 1 ; i <= m/2 ; i++){
        if(i*2 == m && hashTable[i] >=2){
            printf("%d %d\n",i,i);
            return 0;
        }
        if(hashTable[i] != 0 && hashTable[m-i] != 0){
            printf("%d %d",i,m-i);
            return 0;
        }
    }
    printf("No Solution");
    return 0 ;
}
