#include<cstdio>

using namespace std;

int main(){
	
	int n , pre = 0 , time = 0;
	scanf("%d",&n);
	int cur;
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&cur);
		if(cur > pre){
			time += ((cur - pre) * 6 + 5);
		}else{
			time += ((pre - cur) * 4 + 5);
		}
		pre = cur;
	}
	
	printf("%d",time);
	return 0;
}
