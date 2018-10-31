/*main.cpp*/

#include "LargeInt.h"

int main()
{
	LargeInt n1, n2, n3;
	cout<<"Demonstrate Addition\n\n";
	cout<<"Enter first integer: ";
	cin>>n1;
	cout<<"Enter second integer: ";
	cin>>n2;
	n3 = n1 + n2;
	cout<<n1<<" + "<<n2<<" = "<<n3<<endl;
	cout<<"\nDemonstrate Subtraction\n\n";
	cout<<"Enter first integer: ";
	cin>>n1;
	cout<<"Enter second integer: ";
	cin>>n2;
	n3 = n1 - n2;
	cout<<n1<<" - "<<n2<<" = "<<n3<<endl;
		
	return 0;
}

/*END of main.cpp*/
