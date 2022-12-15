#include <iostream>	
using namespace std; 

void check(int);
bool fn(int ,int);
bool fn2(int ,int);
int main(int argc, char *argv[])
{
	cout << " enter a number: " << endl;
	int num;
	cin  >> num;
	for (int i = 1 ; i <= num ; ++i  ){
		/* cout << i; */
		/* check(i); */
		bool result = fn(i,5);
		bool result2 = fn2(i,5);
		cout<< "fn "<<i << " : " << "5 " << result;
		cout << "	---   ";
		cout<< "fn2 "<<i << " : " << "5 " << result2;
		cout << endl;
	}
	
	/* fn ( num ); */
	return 0;
}

void check(int num){	

	if( num% 15 == 0  ){
		cout << "fizz buzz" << endl; return; }

	if( num% 10 == 0  ){
		cout << "fizz " << endl;return;}
	if( num% 5 == 0  ){
		cout << "buzz" << endl;return;}
	cout << " notthing !" << endl;
}
bool fn(int num1,int num2){
	// bad practice
	if(num1 - num2 > 10){
		if ( num1%2 == 0 ) return true;
		else
			return false;
	}
	else 
		return false;
}

bool fn2(int num1,int num2){
	// good practice
	if(num1 - num2 > 10 && num1%2 == 0){
		return true; }
	return false;
}
