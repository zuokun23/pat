#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    
	int n;
	scanf("%d",&n);

	int maxLen = 0;
	vector<int> maxSeq;
	int sqr = (int)sqrt(1.0*n);
	for(int i = 2 ; i <= sqr ; i++){//第一个因子>=2
		int t = n , j = i;
		vector<int> tmpSeq;
		while(t % j == 0){
			t /= j;
			tmpSeq.push_back(j);
			j++;
		}
		if(j - i > maxLen){
			maxLen = j - i;
			maxSeq = tmpSeq;
		}
		
	}

	if(maxLen == 0){
		printf("1\n%d",n);
	}else{
		printf("%d\n",maxLen);
		for(int i = 0 ; i < maxLen ; i++){
			printf("%d",maxSeq[i]);
			if(i != maxLen - 1) printf("*");
		}
	}

	return 0;
}
