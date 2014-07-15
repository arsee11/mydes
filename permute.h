//file: permute.h

#ifndef PERMUTE_H
#define PERMUTE_H

#ifndef TABLES_H
#include "tables.h"
#endif

#include <bitset>

template<class TABLE, template<class>class TableHanler>
class PermuteHandler
{
	typedef TableHanler<TABLE> tableh_t;
	typedef TABLE table_t;
public:
	PermuteHandler()
	{
	}

	bool Permute(const byte_t *plain_text, int plen, byte_t *cipher_text, int clen)
	{
		bitset<table_t::OUT_COUNT> out(0);
		bitset<table_t::IN_COUNT> in;
		if( !Tramsformation2Bitset(plain_text, plen, in) )
			return false;
		
		for(int i=0; i<table_t::OUT_COUNT; i++)
		{
			out[i] = in[ _tableh.Get(i/table_t::NROW, i%table_t::NCOL)-1 ];
			
		}
		
		Tramsformation2Bytes(out, cipher_text, clen);
	}

	template<class BITSET>
	bool Tramsformation2Bitset(const byte_t *text, int len, BITSET &bit_set)
	{
		if( BYTE_LEN* len != bit_set.size() )
			return false;

		for(int i=0; i<len; i++)
		{
			bitset<BYTE_LEN> bits_byte( *(text+i) );
			for(int j=0; j<BYTE_LEN; j++)
			{
				bit_set[i*BYTE_LEN+j] = bits_byte[j];
			}
		}

		return true;
	}

	template<class BITSET>
	bool Tramsformation2Bytes(BITSET &bit_set, byte_t *text, int len )
	{
		if( BYTE_LEN * len != bit_set.size() )
			return false;

		for(int i=0; i<len; i++)
		{
			bitset<8> bits_byte(0);
			for(int j=0; j<BYTE_LEN; j++)
			{
				bits_byte[j] = bit_set[i*8+j];
			}
			text[i] = (byte_t)bits_byte.to_ulong();
		}

		return true;
	}

private:
	tableh_t _tableh;
};

#endif /*PERMUTE_H*/
