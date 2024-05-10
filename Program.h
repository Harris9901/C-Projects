#ifndef PROGRAM_H
#define PROGRAM_H
#include "sll.h"
#include "queue.h"
#include "newoperator.h"
#include "Stack.h"
#include "Ds.h"
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

struct Value1
{
    string varCommand;
    string DStype;
    string value;

    int userInput;
};

class Program

{

    vector<string> commands;
    map<string, unique_ptr<Stack<string>>> stackMap;
    map<string, unique_ptr<Queue<string>>> queueMap;

public:
    Program();

    int countWords(string &str);

    void parseCommands();
};

#endif