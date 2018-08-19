/*biginteger.h*/

#ifndef BIG_INTEGER_H
#define BIG_INTEGER_H

#include<iostream>
#include<string>

using namespace std;

class BigInteger
{
	private:
		string integer;
	public:
		BigInteger();	
		BigInteger(string integer);		
		BigInteger(BigInteger &obj);		
		void setInteger(string integer);
		string getInteger();
		string add(string op1, string op2);
		BigInteger operator + (BigInteger &op);
		friend ostream& operator << (ostream& o, BigInteger& b);
		friend istream& operator >> (istream &i, BigInteger& b);		
};

#endif
