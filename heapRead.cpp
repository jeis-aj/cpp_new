#include <iostream>
using namespace std; 

struct data{
	int integer;
	string word;
};
typedef struct data  *dPtr;
int main(int argc, char *argv[])
{
	dPtr d = (dPtr)0x7ffc3dd4c8c0;
	cout<< "addr: " << d <<endl;
	cout << d->integer;
	cout << d->word;
	return 0;
}
