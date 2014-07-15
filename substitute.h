//file: substitute.h
#ifndef SUBSTITUTE_H
#define SUBSTITUTE_H

#ifndef TABLES_H
#include "tables.h"
#endif

#ifndef BITS_H
#include "bits.h" 
#endif

/////////////////////////////////////////////////////////////////////
//types
typedef BitsTransformation<Bitset<48> >	in_trans_t;
typedef in_trans_t::holder_t 		in_bits_t;
typedef BitsTransformation<Bitset<32> >	out_trans_t;
typedef out_trans_t::holder_t 		out_bits_t;

typedef BitsTransformation< Bitset<4> > out_unit_trans_t;
typedef out_unit_trans_t::holder_t 	out_unit_bits_t;
typedef BitsTransformation< Bitset<6> > in_unit_trans_t;
typedef in_unit_trans_t::holder_t 	in_unit_bits_t;

template<int idx>
class SubstituteUnitT;

///////////////////////////////////////////////////////
//for s1 to s8
class SubstituteHandler
{
public:
	typedef SubstituteUnitT<1> unit1_t;
	typedef SubstituteUnitT<2> unit2_t;
	typedef SubstituteUnitT<3> unit3_t;
	typedef SubstituteUnitT<4> unit4_t;
	typedef SubstituteUnitT<5> unit5_t;
	typedef SubstituteUnitT<6> unit6_t;
	typedef SubstituteUnitT<7> unit7_t;
	typedef SubstituteUnitT<8> unit8_t;

	//enum{ IN_COUNT = unit1_t::table_t::IN_COUNT };
	//enum{ OUT_COUNT = unit1_t::table_t::OUT_COUNT };
public:
	bool Substitute(const byte_t *plain_text, int plen, byte_t *cipher_text, int clen);

};


////////////////////////////////////////////////////////////////////
class SubstituteUnit
{
	enum{ IN_COUNT = 6 };
	enum{ OUT_COUNT = 4};
public:
	bool operator()(const in_unit_bits_t &inunit, out_unit_bits_t &outunit, TableHandlerAbstract &talbeh);
};

////////////////////////////////////////////////////////////////////
template<int i>
struct Int2Type
{
	enum{value =i };
};


//	template<class T >
//	struct TableIdx
//	{
//		typedef T table_t;
//	};
//
//	template<>struct TableIdx<Int2Type<1> >
//	{
//		enum{value=1};
//		typedef S1Table table_t;
//	};

	template<int i >
	struct TableIdx
	{
	};

	template<>struct TableIdx<1 >
	{
		typedef S1Table table_t;
	};

	template<>struct TableIdx<2>
	{
		typedef S2Table table_t;
	};

	template<>struct TableIdx<3>
	{
		typedef S3Table table_t;
	};

	template<>struct TableIdx<4>
	{
		typedef S4Table table_t;
	};

	template<>struct TableIdx<5>
	{
		typedef S5Table table_t;
	};

	template<>struct TableIdx<6>
	{
		typedef S6Table table_t;
	};

	template<>struct TableIdx<7>
	{
		typedef S7Table table_t;
	};

	template<>struct TableIdx<8>
	{
		typedef S8Table table_t;
	};
template<int idx>
class SubstituteUnitT
{


public:
	typedef typename TableIdx<idx >::table_t table_t;
	typedef TableHandler<table_t> tableh_t;
	
public:
	static bool Substitute(const in_bits_t &in_bits, out_bits_t &out_bits)
	{
		in_unit_bits_t inunit = GetUnit(in_bits);
		out_unit_bits_t outunit;
		tableh_t th;
		if( !_subunit( inunit, outunit, th ) )
			return false;

		SetUnit(outunit, out_bits);
		
		return true;
	}

	static in_unit_bits_t GetUnit(const in_bits_t &in_bits)
	{
		in_unit_bits_t inunit = in_bits.Rang(table_t::IN_COUNT * (idx-1), table_t::IN_COUNT, inunit); 
		return inunit;

	}

	static void SetUnit(const out_unit_bits_t &outunit, out_bits_t &out_bits)
	{
		out_bits.Rang(table_t::OUT_COUNT* (idx-1), outunit);
	}


private:
	static SubstituteUnit _subunit;



};

template<int idx>
SubstituteUnit SubstituteUnitT<idx>::_subunit;




#endif /*SUBSTITUTE_H*/
