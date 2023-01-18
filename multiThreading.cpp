#include <iostream>
#include <thread>
using namespace std; 

long fact(int);
void fn(int,int);
int main(int argc, char *argv[])
{
	/*
	thread t1(fn,7);
	thread t2(fn,8);
	thread t3(fn,9);
	thread t4(fn,5);
	*/
	int str = 88;
	auto t5 = thread(fn,11,str);
	t5.join();	
	return 0;
}
void fn(int num,int hel){
	cout << hel <<endl;
	auto val = fact(num);
	cout << "fatorial  of " << num << " is " << val <<endl;
	cout <<endl;
}

long fact(int num){
	if (num == 1)
		return 1;
	return num*fact(num-1);
}
