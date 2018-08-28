//和1093思路很像
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn = 100010;
int num[maxn] , leftMax[maxn] , rightMin[maxn];
vector<int> ret;
int n;

int main(){
	
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d",&num[i]);

	leftMax[0] = 0;
	for(int i = 1 ; i < n ; i++)
		if(num[i-1] > leftMax[i-1])
			leftMax[i] = num[i-1];
		else
			leftMax[i] = leftMax[i-1];
	rightMin[n-1] = INF;
	for(int i = n - 2 ; i >= 0 ; i--)
		if(num[i+1] < rightMin[i+1])
			rightMin[i] = num[i+1];
		else
			rightMin[i] = rightMin[i+1];


	int cnt = 0;
	for(int i = 0 ; i <n ; i++){
		if(num[i] > leftMax[i] && num[i] < rightMin[i]){
			cnt++;
			ret.push_back(num[i]);
		}
	}

	printf("%d\n",cnt);
	sort(ret.begin() , ret.end());
	for(int i = 0 ; i < cnt ; i++){
		printf("%d",ret[i]);
		if(i != cnt -1)
			printf(" ");
	}
	printf("\n");
	
	return 0;
}

//对第一个代码进行了 变量含义的变化
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int maxn = 100010;
const int INF = 0x3fffffff;
int num[maxn] , leftMax[maxn];
vector<int> ret;
int n;

int main(){
	
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d",&num[i]);

	leftMax[0] = num[0];
	for(int i = 1 ; i < n ; i++)
		if(num[i] > leftMax[i-1])
			leftMax[i] = num[i];
		else
			leftMax[i] = leftMax[i-1];


	int cnt = 0 , rightMin = num[n-1];
	for(int i = n-1 ; i >= 0 ; i--){
		if(i == n-1){
			if(num[i] > leftMax[i-1]){
				cnt++;
				ret.push_back(num[i]);
			}
		}else if(i == 0){
			if(num[i] < rightMin){
				cnt++;
				ret.push_back(num[i]);
			}
		}else{
			if(num[i] > leftMax[i-1] && num[i] < rightMin){
				cnt++;
				ret.push_back(num[i]);
			}
		}
		rightMin = min(rightMin , num[i]);
	}

	printf("%d\n",cnt);
	sort(ret.begin() , ret.end());
	for(int i = 0 ; i < cnt ; i++){
		printf("%d",ret[i]);
		if(i != cnt -1)
			printf(" ");
	}
	printf("\n");

	return 0;
}

//部分正确，暴力搜索
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int num[100010];
int n;
vector<int> ans;

int main(){
	
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++)
		scanf("%d",&num[i]);

	int ret = 0 ;
	for(int i = 0 ; i < n ; i++){
		int j;
		for(j = 0 ; j < i ; j++)
			if(num[j] > num[i])
				break;
		if(j != i)
			continue;
		for(j = i+1 ; j < n ; j++)
			if(num[j] < num[i])
				break;
		if(j != n)
			continue;
		ret++;
		ans.push_back(num[i]);
	}
	sort(ans.begin() , ans.end());
	printf("%d\n",ret);
	for(int i = 0 ; i < ret ; i++){
		printf("%d",ans[i]);
		if(i != ret-1)
			printf(" ");
		else
			printf("\n");
	}
	return 0;
}
