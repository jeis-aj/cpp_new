#include <iostream>
using namespace std; 

struct data{
	int var;
	string word;
};
typedef struct data ptr;
int main(int argc, char *argv[])
{
	ptr *var = new (ptr){ 10,"hello" };
	cout << &var <<endl;
	cin.get();
	return 0;
}
