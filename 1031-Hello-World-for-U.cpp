/*方法 1
分析：假设n = 字符串长度 + 2，因为2 * n1 + n2 = n，且要保证n2 >= n1, n1尽可能地大，分类讨论：
1. 如果n % 3 == 0，n正好被3整除，直接n1 == n2 == n3;
2. 如果n % 3 == 1，因为n2要比n1大，所以把多出来的那1个给n2
3. 如果n % 3 == 2, 就把多出来的那2个给n2
所以得到公式：n1 = n / 3，n2 = n / 3 + n % 3
把它们存储到二维字符数组中，一开始初始化字符数组为空格，然后按照u型填充进去，最后输出这个数组u。
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

char c[85];
int main(){
    
	cin.getline(c , 85);
	int len = strlen(c);
	int n1 , n2 , n3;//n1=n3最大，就是n2最小
	n1 = (len + 2 ) / 3 , n3 = n1 , n2 = (len + 2 - n1 - n3);
  
	for(int i = 0 ; i < n1 - 1 ; i++){
		printf("%c",c[i]);
		for(int j = 0 ; j < n2 - 2; j++)
			printf(" ");
		printf("%c\n",c[len-1-i]);
	}
	for(int i = n1-1 ; i <= n1 + n2 - 2 ; i++)
		printf("%c",c[i]);
	printf("\n");
	return 0;
}	

//方法2
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

char c[85];
int main(){
    
	cin.getline(c , 85);
	int len = strlen(c);
	int n1 , n2 , n3;//n1=n3最大，就是n2最小
	for(n2 = 3 ; n2 <= len ; n2++){
		if((len - n2 + 2) % 2 != 0)
			continue;
		if((len - n2 + 2) / 2 <= n2)
			break;
	}
	n1 = n3 = (len-n2+2)/2;
	
	for(int i = 0 ; i < n1 - 1 ; i++){
		printf("%c",c[i]);
		for(int j = 0 ; j < n2 - 2; j++)
			printf(" ");
		printf("%c\n",c[len-1-i]);
	}
	for(int i = n1-1 ; i <= n1 + n2 - 2 ; i++)
		printf("%c",c[i]);
	printf("\n");
	return 0;
}	
