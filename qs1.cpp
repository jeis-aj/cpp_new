#include <iostream>
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
	int i = 0;
	while ( sz  ){
		cin >> arr [i];
		i++;
		sz--;
	}
	i = 0;
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
