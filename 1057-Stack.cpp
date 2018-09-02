//树状数组
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;

#define lowbit(i) ((i)&(-i))
const int MAXN = 100010;
stack<int> s;
int c[MAXN];

void update(int x ,int v){
	for(int i = x ; i < MAXN ; i += lowbit(i)){
		c[i] += v;
	}
}
int getSum(int x){
	int sum = 0;
	for(int i = x ; i > 0 ; i -= lowbit(i)){
		sum += c[i];
	}
	return sum;
}

void peekMedian(){
	int l = 1 , r = MAXN , mid , k = (s.size()+1)/2;
	while(l < r){
		mid = (l+r)/2;
		if(getSum(mid) >= k)
			r = mid;
		else
			l = mid+1;
	}
	printf("%d\n",l);
}

int main(){

	int n , x;
	char str[12];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%s",str);
		if(strcmp(str , "Push") == 0){
			scanf("%d",&x);
			s.push(x);
			update(x , 1);
		}else if(strcmp(str , "Pop") == 0){
			if(s.empty()) printf("Invalid\n");
			else{
				printf("%d\n",s.top());
				update(s.top() , -1);
				s.pop();				
			}
		}else if(strcmp(str , "PeekMedian") == 0){
			if(s.empty()) printf("Invalid\n");
			else peekMedian();//求中位数			
		}
	}
	return 0;
}
