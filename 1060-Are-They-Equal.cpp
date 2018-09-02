//科学计数法:找.和第一个非零数的位置
#include<iostream>
#include<string>
using namespace std;

int n;

string getAns(string s , int &k){

	int posPoint = s.size() , posNumber = s.size();//不存在
	for(int i = 0 ; i < s.size() ; i++)
		if(s[i] == '.'){
			posPoint = i;
			break;
		}
	for(int i = 0 ; i < s.size() ; i++)
		if(s[i] >= '1' && s[i] <= '9'){//找第一个非0
			posNumber = i;
			break;
		}
	
	if(posNumber == s.size()){//000.000
		string ans;
		for(int i = 0 ; i < n ; i++)
			ans += '0';
		k = 0;
		return ans;
	}
	if(posNumber < posPoint){//011.23 11.23 1123
		
		k = posPoint - posNumber;
		string ans;
		int pos = posNumber;//索引
		for(int i = 0 ; i < n ; i++){
			if(pos >= s.size()){
				ans += '0';
				continue;
			}
			if(s[pos] == '.')
				pos++;
			ans += s[pos++];
		}
		return ans;
	}else{//00.0123
		k = 0 - (posNumber - posPoint - 1);
		string ans;
		int pos = posNumber;
		for(int i = 0 ; i < n ; i++){
			if(pos >= s.size()){
				ans += '0';
				continue;
			}
			ans += s[pos++];
		}
		return ans;
	}
}

int main(){

	string s1 , s2 , ans1 , ans2;
	cin >> n >> s1 >> s2;
	int k1,k2;//指数
	ans1 = getAns(s1 , k1);
	ans2 = getAns(s2 , k2);

	if(ans1 == ans2 && k1 == k2)
		cout << "YES 0." << ans1 << "*10^" << k1;
	else{
		cout << "NO 0." << ans1 << "*10^" << k1;
		cout << " 0." << ans2 << "*10^" << k2;	
	}
	return 0 ;
}
