//素数 + 哈希表的平方探测法
#include<cstdio>
#include<cmath>

using namespace std;

bool hashTable[10010] = {false};

bool isPrime(int n){

	if(n <= 1) return false;
	int sqr = (int)sqrt(1.0*n);
	for(int i = 2 ; i <= sqr ; i++){
		if(n%i == 0)
			return false; 
	}
	return true;
}
int main(){

	int mSize , n;
	
	scanf("%d%d",&mSize,&n);
	while(isPrime(mSize) == false)
		mSize++;


	for(int i = 0 ; i < n ; i++){
		int pos;
		scanf("%d",&pos);
		pos = pos%mSize;

		if(hashTable[pos] == false){
			if(i == n-1)
				printf("%d\n",pos);
			else	
				printf("%d " , pos);
			hashTable[pos] = true;
		}else{
			int step;
			for(step = 1 ; step < mSize ; step++){
				
				int newPos = (pos + step*step)%mSize;
				if(hashTable[newPos] == false){
					if(i == n-1)
						printf("%d\n",newPos);
					else	
						printf("%d " , newPos);
					hashTable[newPos] = true;
					break;
				}
			}
			if(step == mSize){
				if(i == n-1)
					printf("-\n");
				else	
					printf("- ");
			}

		}

	}
	return 0;
}
