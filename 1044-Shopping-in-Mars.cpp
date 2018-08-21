//方法一 双指针，滑动窗口
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const int INF = 100000000;
const int MAXN = 100010;
int chain[MAXN];

int main(){
	
	int n , m;
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < n ; i++){
		
		scanf("%d",&chain[i]);
	}

	int i = 0 , j = -1;//[i,j]为我们的滑动窗口
	int min = INF , tmp = 0;//初值与滑动窗口对应
	vector<int> ret;
	while(i < n && j < n){//j < n也可
		if(tmp >= m && tmp - m < min){
			ret.clear();
			ret.push_back(i);
			ret.push_back(j);
			min = tmp - m;
			tmp -= chain[i++];
		}else if(tmp >= m && tmp - m == min){
			ret.push_back(i);
			ret.push_back(j);
			tmp -= chain[i++];
		}else if(tmp >= m)
			tmp -= chain[i++];
		else
			tmp += chain[++j];
	}

	for(int i = 0 ; i < ret.size() ; i += 2){
		printf("%d-%d\n",ret[i]+1,ret[i+1]+1);
	}
	return 0;
}
//方法二： 二分法，因为二分法对付的是有序数组，明显sum是单调增的
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> sum,ret;
int n,m;

void lower_bound(int i , int &j ,int &tmp){
	int left = i , right = n;//故意写成n，一般为n+1
	while(left < right){
		int mid = (left + right)/2;
		if(sum[mid] - sum[i-1] >= m)
			right = mid;
		else 
			left = mid + 1;
	}
	j = right;
	tmp = sum[j]-sum[i-1];
}
int main(){
	scanf("%d%d",&n,&m);
	sum.resize(n+1);
	sum[0] = 0;
	for(int i = 1 ; i <= n ; i++){
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	int minAns = sum[n];
	for(int i = 1 ; i <= n ; i++){//枚举左端点
		int j  ,tmp;
		lower_bound(i,j,tmp);
		if(tmp > minAns) continue;
		if(tmp >= m){
			if(tmp < minAns){
				ret.clear();
				minAns = tmp;
			}
			ret.push_back(i);
			ret.push_back(j);
		}

	}
	for(int i = 0; i < ret.size() ; i+=2)
		printf("%d-%d\n",ret[i],ret[i+1]);
	return 0;
}
