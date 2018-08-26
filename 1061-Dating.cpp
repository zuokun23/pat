//1 pat c++无法使用gets,此题我用c写的，建议c++下使用getline 算法笔记p75
#include<stdio.h>
#include<string.h>

int main(){
    
	char week[7][5] = {"MON" , "TUE" , "WED" , "THU" , "FRI" , "SAT" , "SUN"};
	char str1[70] , str2[70] , str3[70] , str4[70];
    gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	int minLen1 = strlen(str1) > strlen(str2) ? strlen(str1) : strlen(str2);
	int minLen2 = strlen(str3) > strlen(str4) ? strlen(str3) : strlen(str4);

	int i;
	for(i = 0 ; i < minLen1 ; i++){
		
		if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G'){
			printf("%s ",week[str1[i]- 'A']);
			break;
		}
	}
	for(i++ ; i < minLen1 ; i++){
		if(str1[i] == str2[i] ){
			if(str1[i] >= '0' && str1[i] <= '9'){
				printf("%02d:",str1[i] - '0');
				break;
			}else if(str1[i] >= 'A' && str1[i] <= 'N'){
				printf("%02d:",str1[i] - 'A' + 10);				
				break;
			}
		}
	}

	for(i = 0 ; i < minLen2 ; i++){
		if(str3[i] == str4[i]){
			if(str3[i] >= 'a' && str3[i] <= 'z' || str3[i] >= 'A' && str3[i] <= 'Z'){
				printf("%02d\n",i);
                break;
			}
		}
	}
	return 0;
}	


//2 pat是linux系统，无法运行下面的程序
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int main(){
    
	char week[7][5] = {"MON" , "TUE" , "WED" , "THU" , "FRI" , "SAT" , "SUN"};
	char str1[70] , str2[70] , str3[70] , str4[70];
    gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	int minLen1 = strlen(str1) > strlen(str2) ? strlen(str1) : strlen(str2);
	int minLen2 = strlen(str3) > strlen(str4) ? strlen(str3) : strlen(str4);

	int i;
	for(i = 0 ; i < minLen1 ; i++){
		
		if(str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G'){
			printf("%s ",week[str1[i]- 'A']);
			break;
		}
	}
	for(i++ ; i < minLen1 ; i++){
		if(str1[i] == str2[i] ){
			if(str1[i] >= '0' && str1[i] <= '9'){
				printf("%02d:",str1[i] - '0');
				break;
			}else if(str1[i] >= 'A' && str1[i] <= 'N'){
				printf("%02d:",str1[i] - 'A' + 10);				
				break;
			}
		}
	}

	for(i = 0 ; i < minLen2 ; i++){
		if(str3[i] == str4[i]){
			if(str3[i] >= 'a' && str3[i] <= 'z' || str3[i] >= 'A' && str3[i] <= 'Z'){
				printf("%02d\n",i);
                break;
			}
		}
	}
	return 0;
}	
