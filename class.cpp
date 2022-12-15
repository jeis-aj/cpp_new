#include <iostream>
using namespace std; 


class P1{
	public:
		 void fn(void){
			cout << "P1 called" <<endl;
		}
};

class P2{
	public:
		virtual void fn(void){
			cout << "P2 called" <<endl;
		}
};

class C1: public P1,public P2{
	public:
		void fn(void){
			cout << "C1 called" <<endl;
		}
};
int main(int argc, char *argv[])
{
		P1 obj1;
		P2 obj2;
		C1 obj3;
		
		P2* clsPtr;
		clsPtr = &obj3;
		
		/* obj3.fn(); */
		
		clsPtr->fn();
		
	return 0;
}
