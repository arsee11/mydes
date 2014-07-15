//file: test_helper.h
#include <iostream>

#ifndef TABLES_H
#include "tables.h"
#endif

using namespace std;

template<class BITSET>
void PrintBits(BITSET &bits)
{
	cout<<"bits:";
	for(int i=0; i<bits.size(); i++)
		cout<<bits[i]?"1":"0";

	cout<<endl;

}

void PrintBytes(const byte_t *bytes, int len)
{
	cout<<"bytes:";
	cout.width(2);
	for(int i=0; i<len; i++)
		cout<<hex<<(int)bytes[i]<<" ";

	cout<<endl;
}

