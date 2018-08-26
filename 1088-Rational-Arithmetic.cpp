#include<cstdio>
#include<algorithm>

using namespace std;

typedef long long ll;
ll gcd(ll a , ll b){//求最大公约数
	return b == 0 ? a : gcd(b , a % b);
}

struct Fraction{
	ll up , down;
}a , b;

Fraction reduction(Fraction result){
	
	if(result.down < 0){
		result.down = -result.down;
		result.up = -result.up;
	}
	if(result.up == 0)
		result.down = 1;
	else{
		ll d = gcd(abs(result.up) , abs(result.down));
		result.up /= d;//约去最大公约数
		result.down /= d;
	}
	return result;
}
Fraction add(Fraction f1 , Fraction f2){

	Fraction result;
	result.up = (f1.up*f2.down + f1.down*f2.up);
	result.down = f1.down * f2.down;
	return reduction(result);
}
Fraction minu(Fraction f1 , Fraction f2){

	Fraction result;
	result.up = (f1.up*f2.down - f1.down*f2.up);
	result.down = f1.down * f2.down;
	return reduction(result);
}
Fraction multi(Fraction f1 , Fraction f2){

	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}
Fraction divide(Fraction f1 , Fraction f2){

	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

void showResult(Fraction r){
	r = reduction(r);
	if(r.up < 0 )	printf("(");//负数
	if(r.down == 1) 
		printf("%lld",r.up);//整数 包括0
	else if(abs(r.up) < abs(r.down)){//真分式
		printf("%lld/%lld",r.up,r.down);
	}else{//最简化后不可能有 == 此处为abs(r.up) > abs(r.down),假分式
		printf("%lld %lld/%lld" , r.up/r.down ,abs(r.up)%r.down , r.down);//小心abs
	}
	if(r.up < 0 )	printf(")"); 
}

int main(){
	
	scanf("%lld/%lld %lld/%lld",&a.up,&a.down,&b.up,&b.down);
	//加法
	showResult(a);
	printf(" + ");
	showResult(b);
	printf(" = ");
	showResult(add(a,b));
	printf("\n");
	//减法
	showResult(a);
	printf(" - ");
	showResult(b);
	printf(" = ");
	showResult(minu(a,b));
	printf("\n");
	//乘法
	showResult(a);
	printf(" * ");
	showResult(b);
	printf(" = ");
	showResult(multi(a,b));
	printf("\n");
	//除法
	showResult(a);
	printf(" / ");
	showResult(b);
	printf(" = ");
	if(b.up == 0)//特判
		printf("Inf");
	else
		showResult(divide(a,b));
	printf("\n");

	return 0;
}
