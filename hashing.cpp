#include <iostream>
#include <functional>

using namespace std; 

template<class T = string>
long hsh(T var);
/* long hsh(string var); */

int main(int argc, char *argv[])
{
	string  word ;
	cout << "Guess word, try your luck "<<endl;
	cin >> word;

	enum {
	arg1 = 5318824520001978269, arg2 =  -4955407720277690990, arg3 = 8613752895730747617 , 
	arg4 = 8986539799709475083 , arg5 = -9069455997982671576 ,
	};

	switch (hsh(word)){
		case  arg1:
			{
				cout << " you will find your love soon"<<endl;
				break;
			}
		case  arg2:
			{
				cout << "beauty in your face , haaa haa"<<endl;
				break;
			}
		case  arg3:
			{
				cout << "don't go near  any construction site. LOL!!"<<endl;
				break;
			}
		case  arg4:
			{
				cout << "you should take a lottery !!!"<<endl;
				break;
			}
		case  arg5:
			{
				cout << " you are better than average "<<endl;
				break;
			}
		default:
			cout << "you are not lucky enough "<<endl;
			break;
	}
	/* cout << hsh(word); */

	return 0;
}

template<class T>
long hsh(T var){
	/* long hsh(string var){ */
	hash<T> hashrt ;
	return hashrt(var);
}
