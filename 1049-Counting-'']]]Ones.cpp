//方法一：运行超时
#include<cstdio>

using namespace std;

int cnt = 0;

int main(){
    
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++){
		int t = i;
        while(t != 0){
			if(t % 10 == 1)
				cnt++;
			t /= 10;
		}
    }
    printf("%d",cnt);
}
//ac成功
#include<cstdio>
 
using namespace std;
 
int cnt = 0;
 
int main(){
     
    int n , a = 1 ,ans = 0;
    int left , now , right;
    scanf("%d",&n);
    while(n / a != 0){
        left = n / (a*10);
        now = n % (a*10) / a;//先得到后部分再的得最高位，或者先得前面部分再得最低位 n / a % 10
        right = n % a;
        if(now == 0)
            ans += left*a;
        else if(now == 1)
            ans += (left*a + right + 1);
        else
            ans += (left + 1)*a;
        a *= 10;
    }
 
    printf("%d",ans);
    return 0 ;
}
