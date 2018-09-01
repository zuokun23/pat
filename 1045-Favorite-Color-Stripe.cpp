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
//方法二：LIS
#include<cstdio>
#include<algorithm>
#include<cstring>

const int maxc = 210;//最大颜色数
const int maxn = 10010;//最大L
int HashTable[maxc];//将喜欢的颜色--(映射)->递增序列，将不喜欢的颜色映射为-1
int A[maxn],dp[maxn];//LIS的原数组和dp数组
using namespace std;

int main(){
	
	int n , m  , x;
	scanf("%d%d",&n,&m);
	fill(HashTable , HashTable+maxc , -1);
	for(int i = 0 ; i < m ; i++){
		scanf("%d",&x);
		HashTable[x] = i;//将喜欢颜色映射为递增序列0,1,..m-1
	}
	int L , num = 0;//num存放颜色序列中eva喜欢的颜色总数
	scanf("%d",&L);
	for(int i = 0 ; i < L ;i++){
		scanf("%d",&x);
		if(HashTable[x] >= 0)//若是喜欢的数组，则加入A数组中
			A[num++] = HashTable[x];
	}

	//以下为LIS问题的模板
	int ans = -1;
	for(int i = 0 ; i < num ; i++){
		
		dp[i] = 1;//边界
		for(int j = 0 ; j < i ; j++)
			if(A[j] <= A[i] && dp[j]+1 > dp[i])
				dp[i] = dp[j] + 1;//状态转移方程
		ans = max(ans , dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
