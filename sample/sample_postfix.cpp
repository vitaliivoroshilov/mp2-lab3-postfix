#include "postfix.h"

int main()
{
	string infix = "3 + 5 * 6 / ( 1 + 2 ) - 1";
	Postfix postfix(infix);
	cout << postfix.GetInfix() << endl;
	cout << postfix.GetPostfix() << endl;
	cout << postfix.Calculate() << endl;

	return 0;
}