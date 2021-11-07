#include <iostream>
#include "ZFraction.h"
using namespace std;

int main()
{
	ZFraction a(9, 16), b(2, 3);
	cout.precision(3);
	cout.setf(ios::fixed);
	cout << pow(a, 2) << endl;

	return 0;
}