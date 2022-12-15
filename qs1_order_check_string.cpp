#include <iostream>
using namespace std; 

int main(int argc, char *argv[])
{
	string str1 = "hello";
	string str2 = "world";
	string str3 = "largeString";
	/* int inx = 3; */
	/* str3 = str3.substr(inx); */
	/* cout << str3 <<endl; */
	
	for (auto val: str1)
next:{
	cout << "for loop running " <<endl;
	int inx = 3;
		for (auto ch: str3){
			inx++;
			if ( val == ch )	{
				str3 = str3.substr(inx);
				inx = 0;
				goto next;
			}
		}
	}
	
	return 0;
}
