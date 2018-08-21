#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

struct mooncake{
	double store;//库存可以为浮点数
	double sell;//总售价也可能浮点
	double price;
}cake[1010];

bool cmp(mooncake a ,mooncake b){
	return a.price > b.price;
}
int main(){	
	
	int n; 
	double d;//需求可能浮点数
	scanf("%d%lf",&n,&d);
	for(int i = 0 ; i < n ; i++){
		scanf("%lf",&cake[i].store);
	}
	for(int i = 0 ; i < n ; i++){
		scanf("%lf",&cake[i].sell);
		cake[i].price = cake[i].sell/cake[i].store;
	}

	sort(cake , cake + n , cmp);
	double sale = 0;//销售额可能浮点数
	for(int i = 0 ; i < n ; i++){
		
		if(d >= cake[i].store){
			d -= cake[i].store;
			sale += cake[i].sell;
		}else{
			sale += d*cake[i].price;
			break;
		}
	}
	printf("%.2lf",sale);
	return 0;
}
