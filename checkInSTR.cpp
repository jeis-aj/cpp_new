#include <iostream>
#include <queue>
using namespace std; 


class Animal{
	protected:
		string name;
	public:
		Animal(string nm){
		name = nm;
		}
		void sayName(){
			cout <<"name is : "<< name <<endl;
		}
};

class dog:public Animal{
	private:
		string breed;
	public:
		dog(string name, string breed):Animal(name){
			this->breed = breed;	
			this->name = name;
		}
		void sayBreed(){
			cout << "breed : " << breed <<endl;
		}
};

int fn1(int val){
	cout << val <<endl;
	return val;
}
int fn2(int val){
	cout << val <<endl;
	return val;
}
int fn3(int val){
	cout << val <<endl;
	return val;
}

int (*fn[])(int) { fn1,fn2, fn3 };
int main(int argc, char *argv[])
{
	int  i = 0;
	while(i < 3){
		fn[i](i);
		i++;	
	}
	char *kl[3] = { "ells","jsl","ls" ,"hsls"};
	dog pup("dokey","german");
	pup.sayName();
	pup.sayBreed();
	return 0;
}
int other(int argc, char *argv[])
{
	queue<char> que;	
	string one = "helo";
	string two = "eol";

	for (auto ch : two){
		que.push(ch);
	}
	for ( auto ch: one  ){
		if( ch == que.front() ){
			que.pop();
		}
	}
	cout  << one <<endl;
	cout  << two <<endl;
	if (que.empty()){
		cout << " passed " <<endl;
	}
	else {
		cout << "failed " <<endl;
	}
	return 0;
}
