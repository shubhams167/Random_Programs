/*LargeInt.cpp*/

#include "LargeInt.h"

using namespace std;

/*Constructors*/
LargeInt::LargeInt()
{
	integer = "";
}

LargeInt::LargeInt(int integer)
{
	this->integer = to_string(integer);
}

LargeInt::LargeInt(string integer)
{
	this->integer = integer;
}

LargeInt::LargeInt(LargeInt &obj)
{
	this->integer = obj.integer;
}

/*Mutator*/
void LargeInt::setInteger(string integer)
{
	this->integer = integer;
}

/*Accessor*/
string LargeInt::getInteger()
{
	return this->integer;
}

/*Function to perform addition*/
string LargeInt::add(string op1, string op2)
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

/*Function to perform subtraction*/
string LargeInt::sub(string op1, string op2)
{
	string result;
	short int digit1 = 0, digit2 = 0, digitSub = 0;
	/*Make operands of same length*/
	while(op2.length() > op1.length())//If operand 2 is larger than operand 1
	{
		op1.insert(op2.begin(), '0');	//Fill op1 with zeroes to make them of equal size
	}
	while(op2.length() < op1.length())//If operand 1 is larger than operand 2
	{
		op2.insert(op2.begin(), '0');	//Fill op2 with zeroes to make them of equal size
	}
	/*Iterate through both operand strings and subtract corresponding digit*/
	for(int i = op1.length() - 1; i >= 0; i--)
	{
		digit1 = op1[i] - '0';
		digit2 = op2[i] - '0';
		if(digit1 < digit2)//If digit of first operand is larger than corresponding digit of second operand then
		{
			if(i > 0 && (op1[i - 1] - '0') != '0')//If left digit of operand 1 is not 0 then we can take 1 from it and add it to digit1 of operand 1
			{
				op1[i - 1] = op1[i - 1] - 1;
				digit1 = digit1 + 10;//Add 10 to digit1
				digitSub = digit1 - digit2;
				result.insert(result.begin(), '0' + digitSub);
			}
			else//No more digit on left of operand
			{
				digitSub = digit2 - digit1;
				result.insert(result.begin(), '0' + digitSub);
				result.insert(result.begin(), '-');//Add a negative sign at the starting
				break;//Subtraction is complete here
			}
		}
		else
		{
			digitSub = digit1 - digit2;
			result.insert(result.begin(), '0' + digitSub);
		}
	}
	/*Check zeroes in starting and if found remove them*/
	while(result[0] == '0' || (result[0] == '-') && result[1] == '0')
		result.erase(0, 1);
	return result;
}

/*Overload + operator*/
LargeInt LargeInt::operator + (LargeInt &op)
{
	LargeInt b;
	b.setInteger(add(this->integer, op.integer));
	return b;
}

/*Overload - operator*/
LargeInt LargeInt::operator - (LargeInt &op)
{
	LargeInt b;
	b.setInteger(sub(this->integer, op.integer));
	return b;
}


/*Definition of friend operator functions*/
ostream& operator << (ostream& o, LargeInt& b)
{
	o << b.getInteger();
	return o;
}

istream& operator >> (istream &i, LargeInt& b)
{
	string integer;
	i >> integer;
	b.setInteger(integer);
	return i;
}

/*END of LargeInt.cpp*/
