//file:test.cpp

#include "permute.h"
#include <iostream>

using namespace std;

int main()
{
	PermuteHandler<IPTable, TableHandler> iph;
	byte_t text[8]={'a','b','c','d','e','f','g','h'};
	cout<<"text:"<<text<<endl;
	byte_t ctext[8]={0};
	iph.Permute(text, 8, ctext, 8);
	
	PermuteHandler<IP_1Table, TableHandler> _1iph;
	byte_t ttext[8]={0};
	_1iph.Permute(ctext, 8, ttext, 8);
	cout<<"ttext:"<<ttext<<endl;
	return 0;
}
