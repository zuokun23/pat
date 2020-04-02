#include<iostream>
#include<string>
using namespace std;

bool isPrime(int n){//判断是否是质数只能被1和自身整除2 3 5 
	if(n == 0 || n == 1)
		return false;
	for(int i = 2 ; i*i <= n ; i++){//n = i*j(i<=j)则i最大取根号n 
		if(n % i == 0)
			return false;
	} 
	return true;	
}

int main(){
	
	int l , k;
	string s;
	cin >> l >> k >> s;
	for(int i = 0 ; i + k - 1 < l ; i++){
		string t = s.substr(i,k);
		int num = stoi(t);
		if(isPrime(num)){
			
			for(int i = 0 ; i < t.size() ; i++){//输出0023这样的质数
				if(t[i] == '0')
					cout << '0';
				else//防止0203这样的情况
					break;
			}
			cout << num;
			return 0;
		}
		
	}
	cout << "404\n";
	return 0;
} 
