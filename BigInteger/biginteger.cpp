/*biginteger.cpp*/

#include "biginteger.h"

using namespace std;

BigInteger::BigInteger()
{
	integer = "";
}

BigInteger::BigInteger(string integer)
{
	this->integer = integer;
}

BigInteger::BigInteger(BigInteger &obj)
{
	this->integer = obj.integer;
}

void BigInteger::setInteger(string integer)
{
	this->integer = integer;
}

string BigInteger::getInteger()
{
	return this->integer;
}

/*Function to perform addition*/
string BigInteger::add(string op1, string op2)
{
	string carry = "0";
	short int digit1 = 0, digit2 = 0, carryDigit = 0, digitSum = 0;
	/*Check which operand is larger in length and swap, if necessary, to make largest operand = op1 */
	if(op2.length() > op1.length())
	{
		string temp = op1; 
		op1 = op2;
		op2 = temp;
	}
	/*Make operands of same length*/
	while(op2.length() < op1.length())
	{
		op2.insert(op2.begin(), '0');	//Fill with zeroes
	}
	/*Iterate through both operand strings and add corresponding digit*/
	for(int i = op1.length() - 1; i >= 0; i--)
	{
		digit1 = op1[i] - '0';
		digit2 = op2[i] - '0';
		digitSum = digit1 + digit2 + carryDigit;
		/*If sum of digits is greater than 9 then there will be a carry digit otherwise carry digit will be 0*/
		if(digitSum > 9)
		{
			carryDigit = digitSum/10;
			digitSum = digitSum %10;
		}
		else
			carryDigit = 0;
		op1[i] = '0' + digitSum;
		/*When i is 0 and if carry digit is not 0 then insert carry digit at position 0 in op1 string*/
		if(i == 0 && carryDigit != 0)
		{
			op1.insert(op1.begin(), '0' + carryDigit);
		}
	}
	/*Check zeroes in starting and if found remove them*/
	while(op1[0] == '0')
		op1.erase(0, 1);
	return op1;
}

/*Overload + operator*/
BigInteger BigInteger::operator + (BigInteger &op)
{
	BigInteger b;
	b.setInteger(add(this->integer, op.integer));
	return b;
}

/*Definition of friend operator function*/
ostream& operator << (ostream& o, BigInteger& b)
{
	o << b.getInteger();
	return o;
}

istream& operator >> (istream &i, BigInteger& b)
{
	string integer;
	i >> integer;
	b.setInteger(integer);
	return i;
}
