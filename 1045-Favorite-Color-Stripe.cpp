//方法一：LCS
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 210;
const int maxl = 10010;
int dp[maxn][maxl];//状态
int a[maxn] , b[maxl];

int main(){

	int n , m , l;
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= m ; i++)
		scanf("%d",&a[i]);
	scanf("%d",&l);
	for(int i = 1 ; i <= l ; i++)
		scanf("%d",&b[i]);

	//边界
	for(int i = 0  ; i <= m ; i++)
		dp[i][0] = 0;
	for(int i = 0 ; i <= l ; i++)
		dp[0][i] = 0;
	//状态转移方程
	for(int i = 1 ; i <= m ; i++)
		for(int j = 1 ; j <= l ; j++)
			if(a[i] == b[j])
				dp[i][j] = max(dp[i][j-1] , dp[i-1][j]) + 1;
			else
				dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
	
	printf("%d\n",dp[m][l]);
	return 0;
}
