#include "Date.h"

int main()
{
	Date d1(2003,5,14);
	Date d2 = d1 + 90;
	int a = d2 - d1;
	d1--;
	d1.Print();
	d2.Print();
	cout << a << endl;
	return 0;
}