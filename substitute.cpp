//file: substitute.cpp

#ifndef SUBSTITUTE_H
#include "substitute.h"
#endif


bool SubstituteHandler::Substitute(const byte_t *plain_text, int plen, byte_t *cipher_text, int clen)
{
	in_bits_t in_bits;
	in_trans_t ibt(&in_bits);
	if( !ibt.Transform2Bits(plain_text, 6) )
		return false;

	out_bits_t out_bits;
	if( !unit1_t::Substitute(in_bits, out_bits) )
		return false;
	
	if( !unit2_t::Substitute(in_bits, out_bits) )
		return false;
	
	if( !unit3_t::Substitute(in_bits, out_bits) )
		return false;
	
	if( !unit4_t::Substitute(in_bits, out_bits) )
		return false;
	
	if( !unit5_t::Substitute(in_bits, out_bits) )
		return false;
	
	if( !unit6_t::Substitute(in_bits, out_bits) )
		return false;
	
	if( !unit7_t::Substitute(in_bits, out_bits) )
		return false;
	
	if( !unit8_t::Substitute(in_bits, out_bits) )
		return false;
	

	out_trans_t obt(&out_bits);
	return obt.Transform2Bytes(cipher_text, 4);
}


///////////////////////////////////////////////////////////////////////////////////
bool SubstituteUnit::operator()(const in_unit_bits_t &inunit 
		,out_unit_bits_t &outunit 
		,TableHandlerAbstract &tableh
)
{

	//substitute operations
	unsigned int i = inunit[IN_COUNT-1];
	i = i<<1;
	i = i|inunit[0];
	unsigned int j = inunit.GetByte(1, IN_COUNT-2);
	byte_t cipher = tableh.Get(i, j);
	if((int)cipher == -1)
		return false;

	out_unit_trans_t bt(&outunit);
	return bt.Transform2Bits(&cipher, 1);
}

