#include <vector>
#include <iostream>
#include "lPQuestion.h"
#include "fraction.h"
using namespace std;

lPQuestion::lPQuestion(){
    countLessInq = 0;
    cout << "Enter Number of Variables: " << endl;
    cin >> numVar;
    varNames.resize(numVar, "");
    objFunc.resize(numVar, 0);

    cout << "Enter Variables in Equations: " << endl;
    for(int i=0;i<numVar;i++){
        cin >> varNames[i];
    }

    cout << "Choose Maximization or Minization Problems: " << endl;
    cout << "0: Maximization" << endl;
    cout << "1: Minimization" << endl;
    cin >> isMinimization;

    cout << "Enter Objective Function: " << endl;
    for(int i=0;i<numVar;i++){
        cout << "Enter coefficient of " << varNames[i] << ": ";
        cin >> objFunc[i];
    }

    cout << "Enter Number Inequalities/Equalities : " << endl;
    cin >> numEquations;

    inequalities.resize(numEquations, vector<int> (numVar+2, 0));
    for(int i=0;i<numEquations;i++){
        cout << "Enter" << i+1 << "th equation's parameters : " << endl;
        for(int j=0;j<numVar;j++){
            cout << "Enter coefficient of " << varNames[j] << ": ";
            cin >> inequalities[i][j];
        }
        cout << "Select:" << endl;
        cout << "0: For <=" << endl;
        cout << "1: For =" << endl;
        cout << "2: For >=" << endl;
        cin >> inequalities[i][numVar];
        cout << "Enter constant: ";
        cin >> inequalities[i][numVar+1];
        if(inequalities[i][numVar] == 0) countLessInq++;
    }
    for(int i=0;i<numEquations;i++){
        for(int j=0;j<numVar+2;j++){
            cout <<inequalities[i][j] << " ";
        }
        cout << endl;
    }
}
