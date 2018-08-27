//解释请看https://www.liuchuo.net/archives/1896
#include<iostream>
#include<string>

const int MAXN = 100010;
const int MOD = 1000000007;
int pNum[MAXN] = {0};//[0..i]包含'P'个数
int tNum[MAXN] = {0};//[i..len-1]包含'T'个数

using namespace std;

int main(){
	
	string str;
	getline(cin , str);
	int len = str.size();
	for(int i = 0 ; i < len ; i++){
		if(i != 0)
			pNum[i] = pNum[i-1];
		if(str[i] == 'P')
			pNum[i]++;
	}
	for(int i = len-1 ; i >= 0 ; i--){
		if(i != len-1)
			tNum[i] = tNum[i+1];
		if(str[i] == 'T')
			tNum[i]++;
	}

	int ans = 0;
	for(int i = len - 1 ; i >= 0 ; i--){
		if(str[i] == 'A')
			ans = (ans + pNum[i]*tNum[i])%MOD;
	}

	printf("%d",ans);
	return 0;
}

//2代码改进
#include<iostream>
#include<string>

const int MAXN = 100010;
const int MOD = 1000000007;
int pNum[MAXN] = {0};//[0..i]包含'P'个数

using namespace std;

int main(){
	
	string str;
	getline(cin , str);
	int len = str.size();
	for(int i = 0 ; i < len ; i++){
		if(i != 0)
			pNum[i] = pNum[i-1];
		if(str[i] == 'P')
			pNum[i]++;
	}

	int ans = 0 , tNum = 0;//记录右边T个数
	for(int i = len - 1 ; i >= 0 ; i--){
		if(str[i] == 'A')
			ans = (ans + pNum[i]*tNum)%MOD;
		else if(str[i] == 'T')
			tNum++;
	}

	printf("%d",ans);
	return 0;
}
