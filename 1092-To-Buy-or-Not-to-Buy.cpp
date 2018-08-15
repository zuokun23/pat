//hash表的简单应用，见算法笔记实战p133
#include<iostream>
#include<string>

using namespace std;

int hashTable[62] = {0};

int change(char a){
	
	if(a >='0' && a <='9') return a - '0';
	else if(a >= 'A' && a <= 'Z') return a - 'A' + 10;
	else return a - 'a' + 36;
}
int main(){
	
	string whole,target;
	cin >> whole >> target;

	int miss = 0;

	for(int i = 0 ; i < whole.size() ; i++){
		int  t = change(whole[i]);
		hashTable[t]++;
	}

	for(int i = 0 ; i < target.size() ; i++){
		int t = change(target[i]);
		hashTable[t]--;
		if(hashTable[t] < 0)
			miss++;
	}

	if(miss > 0)
		cout << "No " << miss <<endl;
	else
		cout << "Yes " << whole.size() - target.size() <<endl;
	return 0;
}
