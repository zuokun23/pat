//超时
#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    
    int n , m , dis[100010];
	scanf("%d",&n);
	
	for(int i = 1 ; i <= n ;i++)
		scanf("%d",&dis[i]);
	scanf("%d",&m);

	for(int i = 0 ; i < m ; i++){
		
		int start , end , dis1 = 0 , dis2 = 0;
		scanf("%d%d",&start,&end);

		for(int j = start ; j != end ; j = j%n + 1)//j = (j+1 - 1)%n +1;
			dis1 += dis[j];
		for(int j = end ; j != start ; j = j%n + 1)//j = (j+1 - 1)%n +1;
			dis2 += dis[j];

		printf("%d\n",min(dis1,dis2));
	}
	return 0;
}
//入门模拟
#include<cstdio>
#include<algorithm>

using namespace std;

const int MAXN = 100010;
int dis[MAXN] , A[MAXN];//dis[i]表示1到i+1的距离，A表示i到i+1的距离
int n , m , sum = 0;//sum表示总距离

int main(){
    
	scanf("%d",&n);
	dis[0] = 0;//小技巧，方便下面int ret那句
	for(int i = 1 ; i <= n ;i++){
		scanf("%d",&A[i]);
		sum += A[i];
		dis[i] = sum;
	}
	scanf("%d",&m);
	for(int i = 0 ; i < m ; i++){
		
		int left , right;
		scanf("%d%d",&left,&right);
		if(left > right) swap(left , right);
		
		int ret = dis[right-1] - dis[left-1];
		ret = min(ret , sum - ret);
		printf("%d\n",ret);
	}
	return 0;
}
