#include<cstdio>
#include<cmath>

using namespace std;

bool isPrime(int n){
	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i = 2 ; i <= sqr ; i++){
		if(n % i == 0)
			return false;
	}
	return true;
}

const int maxn = 100010;
int prime[maxn] , pNum = 0;
void Find_Prime(){
	for(int i = 1 ; i < maxn ; i++){
		if(isPrime(i))
			prime[pNum++] = i;
	}
}

struct factor{
	int x , cnt;
}fac[10];

int main(){
    
	
	int n;
	scanf("%d",&n);
    if(n == 1){
        printf("1=1");
        return 0;
    }
	Find_Prime();
	int facNum = 0;//不同质因子数量
	int sqr = (int)sqrt(1.0*n);
	printf("%d=",n);
	for(int i = 0 ; i < pNum && prime[i] <= sqr; i++){
		
		if(n % prime[i] == 0){
			fac[facNum].x = prime[i];
			fac[facNum].cnt = 0;

			while(n % prime[i] == 0){
				fac[facNum].cnt++;
				n /= prime[i];
			}
			facNum++;
		}
		if(n == 1)
			break;
	}

	if(n != 1){
		fac[facNum].x = n;
		fac[facNum].cnt = 1;
		facNum++;
	}

	for(int i = 0 ; i < facNum ;i++){
		if(fac[i].cnt > 1)
			printf("%d^%d",fac[i].x,fac[i].cnt);
		else
			printf("%d",fac[i].x);
		if(i != facNum-1)
			printf("*");
	}
	return 0;
}
