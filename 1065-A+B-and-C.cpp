#include<cstdio>

using namespace std;

int main(){
    
    int n;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i++){

        long long a , b , c;
        scanf("%lld %lld %lld",&a,&b,&c);
		long long d = a + b;

		if(a > 0 && b > 0 && d < 0)
			printf("Case #%d: true\n",i);
		else if(a < 0 && b < 0 && d >= 0)
			printf("Case #%d: false\n",i);
		else if(d > c)
			printf("Case #%d: true\n",i);
		else
			printf("Case #%d: false\n",i);
	}

	return 0;
}
