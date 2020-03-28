//1
#include<cstdio>

using namespace std;

double coef[2001] = {0.0} ,a[1001] = {0.0} , b[1001] = {0.0};

int main(){
	
	int n , m , exp;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d",&exp);
		scanf("%lf",&a[exp]);
	}
	scanf("%d",&m);
	for(int i = 0 ; i < m ; i++){
		scanf("%d",&exp);
		scanf("%lf",&b[exp]);
	}
	for(int i = 0 ; i < 1001 ; i++){
		if(a[i] != 0){
			for(int j = 0 ; j < 1001 ; j++){
				if(b[j] != 0){
					coef[i+j] += a[i]*b[j];
				}
			}
		} 
	}
	int num = 0;
	for(int i = 0 ; i < 2001 ; i++){
		if(coef[i] != 0)
			num++;
	}
	printf("%d",num);
	for(int i = 2000 ; i >= 0 ; i--){
		if(coef[i] != 0)
			printf(" %d %.1f",i,coef[i]);
	} 
	return 0;
}

//2
#include<cstdio>

using namespace std;

struct Poly{
	int exp;//指数 
	double coef;//系数 
} poly[1001];
double ans[2001] = {0.0};

int main(){
	
	int n , m , num = 0;
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%d %lf" , &poly[i].exp , &poly[i].coef);
	}
	scanf("%d",&m);
	for(int i = 0 ; i < m ; i++){
		int exp;
		double coef;
		scanf("%d %lf",&exp,&coef);
		for(int j = 0 ; j < n ; j++){
			ans[exp+poly[j].exp] += coef*poly[j].coef;
		}
	}
	for(int i = 0 ; i < 2001 ; i++)
		if(ans[i] != 0)
			num++;
	printf("%d",num);
	for(int i = 2000 ; i >= 0 ; i--)
		if(ans[i] != 0)
			printf(" %d %.1f",i,ans[i]);
			
	return 0;
}
