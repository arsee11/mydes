//file:test_tables.cpp

#include "tables.h"
#include <iostream>

using namespace std;

int main()
{
	TableHandler<IPTable> tbh;
	
	cout<<"Get(0,0):"  <<(int)tbh.Get(0,0)<<endl;
	cout<<"Get(8,8):"  <<(int)tbh.Get(8,8)<<endl;
	cout<<"Get(7,7):"<<(int)tbh.Get(7,7)<<endl;
	cout<<"Get(5,6):"<<(int)tbh.Get(5,6)<<endl;
	return 0;
}
