#include <iostream>
#include <cstring>
using namespace std; 

template<class T>
class Myclass{
	private:
			T word;
	public:
		Myclass(T word){
		this->word = word;	
		}
		void pop(){
			cout << " hello .. " << word <<endl;
			cout << typeid(word).name()<<endl;
		}
};

union {
	int length;
	float amount;
	char name[10] ;
} data1, data2;


int main(int argc, char *argv[])
{
	char* h = (char*)"hwll";
	cout << h;
}
