#include<iostream>
#include<string>

using namespace std;

int main(){
	
	int sum = 0;
	string a , b , c;//10的一百次方不能用int
	cin >> a;//scanf接受字符数组，cin接受字符串
	for(int i = 0 ; i < a.size() ; i++){
		sum += a[i] - 48; 
	}
	c = to_string(sum);
	
	for(int i = 0 ; i < c.size() ; i++){
		
		if(i != 0)
			printf(" ");
		if(c[i] == '0'){
			printf("zero");
			continue;
		}
		if(c[i] == '1'){
			printf("one");
			continue;
		}
		if(c[i] == '2'){
			printf("two");
			continue;
		}
		if(c[i] == '3'){
			printf("three");
			continue;
		}
		if(c[i] == '4'){
			printf("four");
			continue;
		}
		if(c[i] == '5'){
			printf("five");
			continue;
		}
		if(c[i] == '6'){
			printf("six");
			continue;
		}
		if(c[i] == '7'){
			printf("seven");
			continue;
		}
		if(c[i] == '8'){
			printf("eight");
			continue;
		}
		if(c[i] == '9'){
			printf("nine");
			continue;
		}
	}
	return 0;
} 
