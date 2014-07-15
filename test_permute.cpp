//file:test_permute.cpp

#include "permute.h"
#include <iostream>
#include <bitset>

using namespace std;

template<class BITSET>
void PrintBits(BITSET &bits)
{
	cout<<"bits:";
	for(int i=0; i<bits.size(); i++)
		cout<<bits.test(i)?"1":"0";

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


void TestTransformation2Bitset()
{
	PermuteHandler<IPTable, TableHandler> iph;
	
	cout<<"test Transformation2Bitset:"<<endl; 
	byte_t text[8]={'a','b','c','d','e','f','g','h'};
	cout<<"text:"<<text<<endl;

	bitset<64> bits;
	cout<<"return:"<<iph.Tramsformation2Bitset(text, 8, bits)<<endl;
	PrintBits(bits);
}


void TestTransfomation2Bytes()
{
	cout<<"TestTransfomation2Bytes:"<<endl;
	bitset<32> bits(0xff00ff00);
	PrintBits(bits);
	
	PermuteHandler<IPTable, TableHandler> iph;
	byte_t text[4]={0};
	iph.Tramsformation2Bytes(bits, text, 4);
	PrintBytes(text, 4);
}


void TestPermute()
{
	cout<<"TestPermute:"<<endl;
	PermuteHandler<IPTable, TableHandler> iph;
	byte_t text[8]={'a','b','c','d','e','f','g','h'};
	cout<<"text:"<<endl;
	PrintBytes(text,8);
	
	byte_t ctext[8]={0};
	iph.Permute(text, 8, ctext, 8);
	cout<<"ctext:"<<endl;
	PrintBytes(ctext, 8);
	bitset<64> bits(0);
	iph.Tramsformation2Bitset(ctext, 8, bits);
	PrintBits(bits);
}

int main()
{
	//TestTransformation2Bitset
	TestTransformation2Bitset();

	//TestTransfomation2Bytes
	TestTransfomation2Bytes();

	//TestPermute
	TestPermute();
	
	return 0;
}
