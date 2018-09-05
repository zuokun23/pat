#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 10010;
vector<int> seq; 
int matrix[maxn][maxn];

bool cmp(int a , int b){
	return a > b;
}

int main(){
	int N , m , n ;
	scanf("%d",&N);
	seq.resize(N);
	for(int i = 0 ; i < N ;i++){
		scanf("%d",&seq[i]);
	}
	sort(seq.begin() , seq.end() , cmp);
	m = (int)ceil(sqrt(1.0*N));
	while(N % m != 0 )
		m++;
	n = N/m;

	//默认至少存在一个数字
	int now = 0 , i = 0 , j = 0 ,l = 0 , r = n-1 , u = 0 , d = m-1;
	while(now < N){
			
		if(i == u && j <= r){
			matrix[i][j] = seq[now];	
			if(j != r)
				j++;
			else
				i++;//方便下次进入下个判断
		}else if(i <= d && j == r){
			matrix[i][j] = seq[now];
			if(i != d)
				i++;
			else
				j--;//方便进入下个判断
		}else if(i == d && j >= l){
			matrix[i][j] = seq[now];
			if(j != l)
				j--;
			else
				i--;//方便进入下个判断
		}else if(i >= u+1 && j == l){
			matrix[i][j] = seq[now];
			if(i != u+1)
				i--;
			else{
				j++;
				u++;
				d--;
				l++;
				r--;
			}
		}
		now++;
	}

	for(int i = 0 ; i < m ; i++){
		for(int j = 0 ; j < n ; j++){
			printf("%d",matrix[i][j]);
			if(j != n-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
