//file: bits.h
#ifndef BITS_H
#define BITS_H

#include <bitset>

#ifndef TABLES_H
#include "tables.h"
#endif 

using namespace std;

template<class BIT_HOLDER>
class BitsTransformation
{
public:
	typedef BIT_HOLDER holder_t;
	typedef typename holder_t::bit_t bit_t;

public:	
	BitsTransformation(holder_t *bthldr)
		:_bthldr(bthldr)
	{}

	bool Transform2Bits(const byte_t *text, int len)
	{
		if( BYTE_LEN* len < _bthldr->size() )
			return false;

		return _bthldr->Transform2Bits(text, len);
	}

	bool Transform2Bytes(byte_t *text, int len )
	{
		if( BYTE_LEN * len < _bthldr->size() )
			return false;

		return _bthldr->Transform2Bytes(text, len);
	}
	
private:
	holder_t *_bthldr;
};


/////////////////////////////////////////////////////////////////////////////////
//std bitset holder
template<int nbits>
class Bitset
{
public:
	typedef bitset<nbits> bit_t;
	typedef typename bitset<nbits>::reference reference;

	Bitset(unsigned long val=0)
		:_bitset(val)
	{
	}
	int size() const { return _bitset.size(); }
	
	bool operator[](unsigned i) const { return _bitset[i]; }

	reference operator[](unsigned i) { return _bitset[i]; }

	byte_t GetByte(unsigned  start, unsigned count) const
	{
		bitset<8> bits;

		Rang(start, count, bits);

		return (byte_t)bits.to_ulong();
	}

	template<typename BITSET>
	BITSET &Rang(unsigned  start, unsigned count, BITSET &bits) const
	{
		for(unsigned j=0, i=start; i<start+count &&i<_bitset.size() && j<bits.size(); i++,j++)
		{
			bits[j] = _bitset[i];
		}

		return bits;
		
	}
	
	template<typename BITSET>
	void Rang(unsigned  start, const BITSET &bits)
	{
		unsigned count = bits.size();

		for(unsigned j=0, i=start; i<start+count &&i<_bitset.size() &&j<bits.size(); i++,j++)
			_bitset[i] =  bits[j];

	}	

	bool Transform2Bits(const byte_t *text, int len)
	{
		for(int i=0; i<len; i++)
		{
			bitset<BYTE_LEN> bits_byte( *(text+i) );
			for(int j=0; j<BYTE_LEN; j++)
			{
				_bitset[i*BYTE_LEN+j] = bits_byte[j];
			}
		}

		return true;
	}

	bool Transform2Bytes(byte_t *text, int len )
	{
		for(int i=0; i<len; i++)
		{
			bitset<8> bits_byte(0);
			for(int j=0; j<BYTE_LEN; j++)
			{
				bits_byte[j] = _bitset[i*8+j];
			}
			text[i] = (byte_t)bits_byte.to_ulong();
		}

		return true;
	}
	
private:
	bitset<nbits> _bitset;
};


#endif /*BITS_H*/
