#ifndef LP_QUESTION
#define LP_QUESTION

#include <vector>
#include "fraction.h" 
#include <iostream>
using namespace std;

class lPQuestion{
    public:
        //Variables
        int numVar;
        vector<string> varNames;
        bool isMinimization = false;
        vector<int> objFunc;
        int numEquations;
        int countLessInq;
        vector<vector<int>> inequalities;
        //functions
        lPQuestion();
};

#endif