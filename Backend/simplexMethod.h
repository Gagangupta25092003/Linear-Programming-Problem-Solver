#ifndef SIMPLEX_METHOD
#define SIMPLEX_METHOD

#include <iostream>
#include <vector>
#include "lPQuestion.h"
using namespace std;

class SimplexMethod{
    public:
        int rows;
        int cols;
        vector<string> vars;
        vector<string> basicVars;
        vector<vector<double>> simplexTable;
        vector<pair<string,int>> answer;

        SimplexMethod(lPQuestion &ques);
        int solve();
        void printSimplexTable();
        void simplex();
        void pivot(vector<vector<double>>& table, int pivotRow, int pivotCol);
        int findPivotRow(const vector<vector<double>>& table, int pivotCol);
        int findPivotColumn(const vector<vector<double>>& table);
        void displayTable(const vector<vector<double>>& table);
};

#endif