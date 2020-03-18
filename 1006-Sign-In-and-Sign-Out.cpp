//1柳神的代码
#include<iostream>

using namespace std;
int main(){
	
	int num;
	scanf("%d",&num);
	string locked , unlocked;
	int min = 24*60*60 , max = 0;
	for(int i = 0 ; i < num ; i++){
		int h_i , h_o , m_i , m_o , s_i , s_o;
		int in , out;
		string s;
		cin >> s;
		scanf("%d:%d:%d %d:%d:%d",&h_i , &m_i , &s_i , &h_o , &m_o , &s_o);
		in = h_i * 3600 + m_i * 60 + s_i;//算出总秒数来比较时间先后
		out = h_o * 3600 + m_o * 60 + s_o;
		if(in < min){
			min = in;
			unlocked = s;
		}
		if(out > max){
			max= out;
			locked = s;
		}
	}
	cout << unlocked << " " << locked;
}

//2分别比较小时 分钟 秒数（用结构体更简单）
#include<iostream>

using namespace std;
int main(){
	
	int num;
	scanf("%d",&num);
	string locked , unlocked;
	int h_i_res = 24 , m_i_res = 60 , s_i_res = 60 , h_o_res = 0 , m_o_res = 0 , s_o_res = 0;
	for(int i = 0 ; i < num ; i++){
		int h_i , h_o , m_i , m_o , s_i , s_o;
		string s;
		cin >> s;
		scanf("%d:%d:%d %d:%d:%d",&h_i , &m_i , &s_i , &h_o , &m_o , &s_o);
		int flag_1 = 0 , flag_2 = 0;
		if(h_i < h_i_res){
			flag_1 = 1;
		}else if(h_i == h_i_res && m_i < m_i_res){
			flag_1 = 1;
		}else if(h_i == h_i_res && m_i == m_i_res && s_i < s_i_res){
			flag_1 = 1;
		}
		if(flag_1 == 1){
			h_i_res = h_i;
			m_i_res = m_i;
			s_i_res = s_i;
			unlocked = s;
		}
		
		if(h_o > h_o_res){
			flag_2 = 1;
		}else if(h_o == h_o_res && m_o > m_o_res){
			flag_2 = 1;
		}else if(h_o == h_o_res && m_o == m_o_res && s_o > s_o_res){
			flag_2 = 1;
		}
		if(flag_2 == 1){
			h_o_res = h_o;
			m_o_res = m_o;
			s_o_res = s_o;
			locked = s;
		}
	}
	cout << unlocked << " " << locked;
}
