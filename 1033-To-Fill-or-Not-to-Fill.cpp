#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;
struct station{
	double price , dis;
}st[maxn];
double Cmax , D , Davg;
int n;

bool cmp(station a , station b){
	return a.dis < b.dis;
}
int main(){
	
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%lf%lf",&st[i].price,&st[i].dis);
	}
	//注意
	st[n].price = 0;
	st[n].dis = D;
	sort(st , st+n , cmp);
	//注意
	if(st[0].dis != 0){
		printf("The maximum travel distance = 0.00\n");
	}else{
		int now = 0;//当前加油站
		double MAX = Cmax*Davg;
		double ans = 0 ,nowTank = 0;//总花费，当前油量
		while(now < n){//未到达终点
			//在能到达范围内找最小或找最近的小于自己
			double priceMin = INF;
			int k = -1;
			for(int i = now+1 ; i <= n && st[i].dis - st[now].dis <= MAX; i++){
				if(st[i].price < priceMin){
					priceMin = st[i].price;
					k = i;
					if(priceMin < st[now].price)
						break;
				}
			}
			if(k == -1)//满油未找到加油站				break;
				break;
			//从now到k所需油量
			double need = (st[k].dis - st[now].dis)/Davg;
			if(priceMin < st[now].price){
				//买恰好到k的油
				if(nowTank < need){
					ans += (need - nowTank)*st[now].price;
					nowTank = 0;//达到k后油量为0
				}else{//油量超过need
					nowTank -= need;
				}
			}else{
				ans += (Cmax-nowTank)*st[now].price;//加满
				nowTank = Cmax - need;
			}
			now = k;//进入加油站k
		}
		if(now == n)//能到达终点
			printf("%.2f\n",ans);
		else//不能到达
			printf("The maximum travel distance = %.2f\n",st[now].dis+MAX);
	}
	return 0;
}
