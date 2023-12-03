#include "Postfix.h"

Postfix::Postfix(string _infix) : infix(_infix)
{
	priority.insert({ '+', 1 });
	priority.insert({ '-', 1 });
	priority.insert({ '*', 2 });
	priority.insert({ '/', 2 });
	priority.insert({ '(', 0 });
	ToPostfix();
}

string Postfix::GetInfix() { return infix; }

string Postfix::GetPostfix() { return postfix; }

string Postfix::ToPostfix()
{
	TStack<char> st;
	char stackSymbol;
	for (char symbol : infix)
	{
		switch (symbol)
		{
		case '(':
			st.push(symbol);
			break;
		case ')':
			stackSymbol = st.pop();
			while (stackSymbol != '(')
			{
				postfix += stackSymbol;
				stackSymbol = st.pop();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!st.isEmpty())
			{
				stackSymbol = st.pop();
				if (priority[symbol] <= priority[stackSymbol])
					postfix += stackSymbol;
				else {
					st.push(stackSymbol);
					break;
				}
			}
			st.push(symbol);
			break;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			postfix += symbol;
			break;
		}
	}
	while (!st.isEmpty())
	{
		stackSymbol = st.pop();
		postfix += stackSymbol;
	}
	return postfix;
}

int Postfix::Calculate()
{
	TStack<int> st;
	int leftOperand, rightOperand;
	string number = "";
	for (char symbol : postfix)
	{
		switch (symbol)
		{
		case '+':
			rightOperand = st.pop();
			leftOperand = st.pop();
			st.push(leftOperand + rightOperand);
			break;
		case '-':
			rightOperand = st.pop();
			leftOperand = st.pop();
			st.push(leftOperand - rightOperand);
			break;
		case '*':
			rightOperand = st.pop();
			leftOperand = st.pop();
			st.push(leftOperand * rightOperand);
			break;
		case '/':
			rightOperand = st.pop();
			leftOperand = st.pop();
			st.push(leftOperand / rightOperand);
			break;
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
			number = symbol;
			st.push(stoi(number)); //correct convert string to int
			break;
		}

	}
	return st.pop();
}