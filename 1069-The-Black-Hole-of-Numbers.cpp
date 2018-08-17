#include<cstdio>
#include<algorithm>

using namespace std;

int num[5];
void int2Array(int n){

	for(int i = 0 ; i <= 3 ;i++){
		num[i] = n % 10;
		n /= 10;
	}
}

bool cmp(int a ,int b){
	return a > b ? true : false;
}

int array2Int(){
	
	int a = 0;
	for(int i = 0 ; i <= 3 ; i++){
		a = a*10 + num[i];
	}
	return a;
}

int main(){
    
	int n , MAX ,MIN;
	scanf("%d",&n);
	while(1){
		int2Array(n);
		sort(num , num+4);
		MIN = array2Int();
		sort(num , num + 4 , cmp);
		MAX = array2Int();
		n = MAX - MIN;
		printf("%04d - %04d = %04d\n",MAX,MIN,n);
		if(n == 0 || n == 6174) break;
	}
	return 0;
}
