#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
 
using namespace std;
 
struct Student{
    char id[10];
    int v , t , sum;
    int flag;
}stu[100010];
 
bool cmp(Student a , Student b){
    if(a.flag != b.flag) return a.flag < b.flag;
    else if(a.sum != b.sum) return a.sum > b.sum;
    else if(a.v != b.v) return a.v > b.v;
    else return strcmp(a.id,b.id) < 0;
}
int main(){
     
    int n , l , h;
    scanf("%d%d%d",&n,&l,&h);
 
    int num = 0;//参加排序的人数
    for(int i = 0 ; i < n ; i++){
        char id[10];
        int v,t;
        scanf("%s%d%d",id,&v,&t);
        if(v < l || t < l)
            continue;
        strcpy(stu[num].id , id);
        stu[num].v = v;
        stu[num].t = t;
        stu[num].sum = v + t;
 
        if(v >= h && t >= h)
            stu[num].flag = 1;
        else if(v >= h && t < h)
            stu[num].flag = 2;
        else if(v < h && t < h && v >= t)
            stu[num].flag = 3;
        else
            stu[num].flag = 4;
        num += 1;
    }
 
    sort(stu , stu+num , cmp);
 
    printf("%d\n",num);
    for(int i = 0 ; i < num ; i++){
        printf("%s %d %d\n",stu[i].id,stu[i].v,stu[i].t);
    }
    return 0;
}
