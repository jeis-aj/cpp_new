#include <iostream>
#include <map>
using namespace std; 

int main(int argc, char *argv[])
{
	map <char,bool> mp;	

	string str = " hello world";
	cout << str <<endl;
	int i = 0;
	for (char ch: str){
		bool &state = mp[ch];
		if(state){
			str.erase(i,1);
			--i;
		}
		else{
			state  = true;
		}
		++i;
	}
	
	/* str.erase(3,1); */
	cout << str <<endl;
	return 0;
}
