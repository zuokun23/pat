//易理解版本
#include<cstdio>

using namespace std;

const int maxn = 10010;
int arr[maxn] , dp[maxn] , s[maxn];//s记录dp[i]对应的起始位置 

int main(){
	int n , flag = 0;
	scanf("%d",&n);
	
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&arr[i]) ;
		if(arr[i] >= 0 && flag == 0)//>=0不是>0 
			flag = 1;
	}
	if(flag == 0){
		printf("0 %d %d" , arr[0] , arr[n-1]);
		return 0;
	}
	
	dp[0] = arr[0];//边界
	s[0] = 0; 
	for(int i = 1 ; i < n ; i++){
		//状态转移方程 
		if(dp[i-1] > 0){
			dp[i] = arr[i] + dp[i-1];
			s[i] = s[i-1];
		}else{
			dp[i] = arr[i];
			s[i] = i;
		}
	}
	
	int k = 0;
	for(int i = 1 ; i < n ; i++){
		if(dp[i] > dp[k])
			k = i;
	}
	printf("%d %d %d" , dp[k] , arr[s[k]] , arr[k]);
	return 0;
} 
