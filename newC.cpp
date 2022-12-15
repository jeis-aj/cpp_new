#include <iostream>
#include <sstream>
#include <vector>

using namespace std; 

int finalLength(char* input1,char* input2 , char* input3,char* input4)
{
	string a(input1);
	string d(input2);
	string e(input3);
	string f(input4);
	/* cin >> a; */
	string arr[]{ d, e, f };

	int sz = sizeof (arr)/sizeof(arr[0]);
	/*
	int i = 0;
	while ( sz  ){
		cin >> arr [i];
		i++;
		sz--;
	}
	*/
	int i = 0;
	cout << "out" <<endl;
	while (1){
	cout << "arr el: "<<arr[i] <<endl;
	int index = a.find( arr[i] );
	cout << "inx: "<<index <<endl;
		if ( index == -1 ){
			int len =  a.length();
			return len; 
			/* break; */
		}
		else{
			a.erase(index,sizeof(arr[i]));
		}
	i++;
	}
	return 0 ;
}

#include <stack>
#include <queue>
#include <vector>

int fn(char* nm, char* wd){
	string name(nm);
	string word(wd);
	int count =0 ;

	int index;
	index = name.find(word);
	string temp;

	/*
	if (index >= 0)
	{
		count = name.length() - word.length();
		name.erase(index,word.length());
		cout << name <<endl;
	}
	else
		return -1;
	return count;
	*/
	return 0;
}

int length_of_remaining(char* nm, char* wd,string* arr,int sz){
	string name(nm);
	string word(wd);

	queue<char> que;
	for (auto ch: name){
	que.push(ch);
	}
	int index = 0;
	for ( auto ch: name )
	{
		if ( ch == que.front() ){
			que.pop();
		}
	}
	if ( !que.empty() ){
		return name.length();
	}
	return 0;
}

int otherMain()
{
	char name[] = " arun jyothish ";
	char word[] = "run";
	int count = fn(name,word);
	cout << "otherMain()" <<endl;
	cout << count <<endl;
	return 0;
}

int lo(){
	cout << "new fn" <<endl;
	return 0;
}

int (*xn[])(void) = {otherMain,lo};

int main(int argc, char *argv[])
{
	string str = "hello world",word;
	stringstream ss(str);
	while ( ss >> word ){
		cout << word <<endl;
		cout << "length of word: " << word.length() <<endl;
	}
	xn[0]();
	(*xn)();

	for (auto val: xn){
		cout << "infor" <<endl;
		val();
	}
	return 0;
}

