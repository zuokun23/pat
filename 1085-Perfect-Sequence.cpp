#include<cstdio>
#include<algorithm>
#include<vector>
 
using namespace std;
 
vector<int> seq;
 
int upper_bound(int l , int r , int x){
     
    int mid;
    while(l < r){
        mid = l + (r - l)/2;
        if(seq[mid] > x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main(){
     
    int n , p , tmp;
    scanf("%d%d",&n,&p);
    for(int i = 0 ; i < n ; i++){
        scanf("%d",&tmp);
        seq.push_back(tmp);
    }
 
    sort(seq.begin() , seq.end());
 
    int maxL = 0 , pos;
    for(int i = 0 ; i < n ; i++){
         
        pos = upper_bound(i , n , seq[i]*p) - 1;//特意包含位置n,>m*p的第一个位置-1 //具体见算法笔记p128
        if(pos - i + 1 > maxL)
            maxL = pos - i + 1;
    }
    printf("%d",maxL);
    return 0;
}
