#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include <vector>
#include <map>
#include "TStack.h"

class Postfix
{
    string infix;
    string postfix;
    map<char, int> priority;
public:
    Postfix(string _infix = "");
    string GetInfix();
    string GetPostfix();
    string ToPostfix();
    int Calculate();
};

#endif
