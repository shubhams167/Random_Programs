/*LargeInt.h*/

#ifndef LARGE_INTEGER_H
#define LARGE_INTEGER_H

#include<iostream>
#include<string>

using namespace std;

class LargeInt
{
	private:
		string integer;
	public:
		LargeInt();
		LargeInt(int);	
		LargeInt(string integer);		
		LargeInt(LargeInt &obj);		
		void setInteger(string integer);
		string getInteger();
		string add(string op1, string op2);
		string sub(string op1, string op2);
		LargeInt operator + (LargeInt &op);
		LargeInt operator - (LargeInt &op);
		friend ostream& operator << (ostream& o, LargeInt& b);
		friend istream& operator >> (istream &i, LargeInt& b);		
};

#endif

/*END of LargeInt.h*/
