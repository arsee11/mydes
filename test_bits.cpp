//file: test_bits.cpp

#include "bits.h"
#include "test_helper.h"

void testRang1()
{
	cout<<"testRang1:"<<endl;

	bitset<8> sbits;
	Bitset<32> bits(0xA1F01001);
	PrintBits(bits);
	bits.Rang(24, 8, sbits);
	PrintBits(sbits);
	sbits = bits.Rang(0,8, sbits); 
	PrintBits(sbits);
	
}

void testRang2()
{
	cout<<"testRang2:"<<endl;

	Bitset<32> bits(0);
	bitset<8> sbits0(0x01);
	bits.Rang(0, sbits0);
	PrintBits(bits);
	bitset<8> sbits1(0x10);
	bits.Rang(8, sbits1);
	PrintBits(bits);
	bitset<8> sbits2(0xf0);
	bits.Rang(16, sbits2);
	PrintBits(bits);
	bitset<8> sbits3(0xa1);
	bits.Rang(24, sbits3);
	PrintBits(bits);
	
}

void testGetByte()
{
	byte_t byte=0;
	Bitset<32> bits(0x10203040);
	byte = bits.GetByte(0, 8);
	PrintBytes(&byte, 1);
	byte = bits.GetByte(8, 8);
	PrintBytes(&byte, 1);
	byte = bits.GetByte(16, 8);
	PrintBytes(&byte, 1);
	byte = bits.GetByte(24, 8);
	PrintBytes(&byte, 1);
}

int main()
{

	testRang1();
	testRang2();
	testGetByte();
	return 0;
}
