#include <iostream>
#include <sstream>
using namespace std; 

int other()
{
	char ch[10] = "hi hello";
	string str(ch);			// c_str to string conversion

	stringstream ss(str);	// Stringstream creating out of string
	string st;
	ss >> st;				// read word by from ss
	cout << st <<endl;
	return 0;	
}


int main(int argc, char *argv[])
{
	other();
	return 0;
}
