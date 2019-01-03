#include<cstdio>

using namespace std;
const int maxn = 1010;

int main(){

    float coefficient[maxn] = {0};
    int k , t1;
    float t2;
    scanf("%d",&k);
    for(int i = 0 ; i < k ; i++){
        scanf("%d%f",&t1,&t2);
        coefficient[t1] = t2;
    }
    scanf("%d",&k);
    for(int i = 0 ; i < k ; i++){
        scanf("%d%f",&t1,&t2);
        if(coefficient[t1] == 0)
            coefficient[t1] = t2;
        else
            coefficient[t1] += t2;
    }

    int cnt = 0;
    for(int i = 0 ; i < maxn ; i++)
        if(coefficient[i] != 0)
            cnt++;
    printf("%d",cnt);
    for(int i = maxn-1 ; i >= 0 ; i--)
        if(coefficient[i] != 0)
            printf(" %d %.1f",i,coefficient[i]);
    return 0;
}
