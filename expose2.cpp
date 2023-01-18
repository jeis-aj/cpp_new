#include <iostream>
using namespace std; 

int main(int argc, char *argv[])
{
	/* int* varP = (int*)0x7ffc66905384; */
	int* varP = (int*)0x7ffe9afec3d4;
	cout << *varP << endl;
	cout << *varP << endl;
	cout << *varP << endl;
	while(1);
	return 0;
}

