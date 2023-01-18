#include <iostream>
#include <ctime>
using namespace std; 
int main(int argc, char *argv[])
{
	time_t timeData1;
	time_t timeData2;
	time(&timeData1);
	time(&timeData2);
	cout<< timeData2-timeData1 <<endl;
	return 0;
}
