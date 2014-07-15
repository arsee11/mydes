//file: test_substitute.cpp

#include "test_helper.h"
#include "substitute.h"

void testSubstitute1()
{
	cout<<"testSubstitute1:"<<endl;
	typedef SubstituteHandler sub_t;

	sub_t sub;
	byte_t plain[7]={'o','p','q','r','s','t'};
	PrintBytes(plain, 6);
	in_bits_t ibits;
	in_trans_t itr(&ibits);
	itr.Transform2Bits(plain, 6);
	PrintBits(ibits);
	byte_t cipher[5]={0};	
	cout<<sub.Substitute(plain, 6, cipher, 4)<<endl;
	PrintBytes(cipher, 4);
	out_bits_t obits;
	out_trans_t otr(&obits);
	otr.Transform2Bits(cipher, 4);
	PrintBits(obits);
}

void testSubstitute2()
{
	
	std::cout<<"testSubstitute2:"<<std::endl;

	in_bits_t ibits(0xAFFAAFAA);
	out_bits_t obits;

	
	PrintBits(ibits);


	typedef SubstituteUnitT<1> sub_t;
	cout<<"result:"<<sub_t::Substitute(ibits, obits)<<endl;
	PrintBits(obits);
	typedef SubstituteUnitT<3> sub_t3;
	cout<<"result:"<<sub_t3::Substitute(ibits, obits)<<endl;
	PrintBits(obits);
	typedef SubstituteUnitT<6> sub_t6;
	cout<<"result:"<<sub_t6::Substitute(ibits, obits)<<endl;
	PrintBits(obits);

}

int main()
{
	testSubstitute1();
	testSubstitute2();
	return 0;
}
