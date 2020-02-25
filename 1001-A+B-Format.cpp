//字符串处理 to_string() + %
#include <iostream>

using namespace std;

int main(){

    int a,b;
    cin >> a >> b;
    string s = to_string(a+b);
    int len = s.length();
    for(int i = 0 ; i < len ; i++){
        cout<<s[i];
        if(s[i] == '-') continue;
        if( (i+1)%3 == len%3 && i != len-1) printf(",");//编号为i+1(从1开始)的字符 与 编号为len的字符地位相同
    }
}

//死板方法 % + / + stack
#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int a,b,c;
    stack<int> st;
    scanf("%d%d",&a,&b);
    c = a+b;
    if(c == 0)
      printf("0");
    if(c < 0) {//处理负数
        printf("-");
        c = 0 - c;
    }
    while(c > 0){//入栈
        st.push(c % 1000);
        c /= 1000;
    }
    int len = st.size();
    while(!st.empty()){//出栈
        if(st.size() == len)
            printf("%d",st.top());
        else
            printf("%03d",st.top());
        if(st.size() != 1)
            printf(",");
        st.pop();
    }

    return 0;
}

//
#include<cstdio> 

using namespace std;

int main(){
	
	int a , b , c , pos = 0;
	int d[10]; 
	scanf("%d %d",&a,&b);
	c = a + b;
	
	if(c < 0){//负值
	
		printf("-");
		c = 0 - c;
	}else if(c == 0){//0
		printf("0");
	}
	
	while(c != 0){
		d[pos++] = c%1000;
		c = c /1000;
	}
	
	for(int i = pos-1 ; i >= 0 ; i--){
		if(i == pos -1)//，0与，000
			printf("%d",d[i]);
		else
			printf("%03d",d[i]);
		
		if(i != 0)//，
			printf(",");
	}

	return 0;
}


