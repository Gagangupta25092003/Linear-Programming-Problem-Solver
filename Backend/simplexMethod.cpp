#include <vector>
#include <iostream>
#include "lPQuestion.h"
#include <string>
#include "simplexMethod.h"
#include <iomanip>
#include <limits>

using namespace std;

SimplexMethod::SimplexMethod(lPQuestion &ques){
    cout << "Came Here" << endl;
    rows = ques.numEquations+1;
    cols = ques.numVar + ques.countLessInq + 1;
    simplexTable.resize(rows);

    for(auto &row:simplexTable){
        row.resize(cols, 0);
    }
    int count = ques.numEquations;
    cout << "Rows: " << rows << endl;
    cout << "Cols: " << cols << endl;
    cout << "Slack Variables: " <<  ques.countLessInq << endl;


    for(int i=0;i<cols;i++){
        simplexTable[0][i] = 0; 
    }
    for(int i=0;i<ques.numEquations;i++){
        simplexTable[0][i] = ques.objFunc[i];
    }
    for(int i=1;i<rows;i++){
        cout << "i: "<< i << " j:  ";
        for(int j =0;j<ques.numEquations;j++){
            cout << j << " ";
            simplexTable[i][j] = ques.inequalities[i-1][j];
        }
        cout << "Count: " << count << endl;
        simplexTable[i][count] = 1;
        count++;
        simplexTable[i][cols-1] = ques.inequalities[i-1][ques.numVar+1];
    }
    cout << "Made Table " << endl;
    vars.resize(cols-1);
    // basicVars.resize(ques.countLessInq + 1);
    // int k = 0;
    // for(int i=0;i<ques.numEquations;i++){
    //     vars[i] = ques.varNames[i];
    //     k++;
    // }
    cout << " dsf" << endl;
    // basicVars[0] = "Fn";
    // for(int i=0;i<ques.countLessInq;i++){
    //     vars[k+i] = "s1";
    //     // vars[k+i] = "s" + to_string(i+1);
    //     basicVars[i+1] = vars[k+i];
    // }
    cout << "Exit" << endl;

}

void SimplexMethod::printSimplexTable(){
    cout << "Simplex Table " << endl;
    // for(int i=0;i<cols-1;i++){
    //     cout << vars[i] << " ";
    // }
    cout << endl;
    for(int i=0;i<rows;i++){
        // cout << basicVars[i] << " ";
        for(int j =0;j<cols;j++){
            cout << simplexTable[i][j] << " ";
        }
        cout << endl;

    }
    cout << "doneppr" << endl;
}
// Display simplex table for debugging
void SimplexMethod::displayTable(const vector<vector<double>>& table) {
    for (const auto& row : table) {
        for (double val : row) {
            cout << setw(10) << val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Find the pivot column (the most negative value in the first row)
int SimplexMethod::findPivotColumn(const vector<vector<double>>& table) {
    int pivotCol = -1;
    double minValue = 0.0;
    for (int j = 0; j < table[0].size() - 1; ++j) {
        if (table[0][j] < minValue) {
            minValue = table[0][j];
            pivotCol = j;
        }
    }
    return pivotCol;
}

// Find the pivot row using the minimum ratio test
int SimplexMethod::findPivotRow(const vector<vector<double>>& table, int pivotCol) {
    int pivotRow = -1;
    double minRatio = numeric_limits<double>::infinity();
    for (int i = 1; i < table.size(); ++i) {  // Start from the second row
        if (table[i][pivotCol] > 0) {
            double ratio = table[i].back() / table[i][pivotCol];
            if (ratio < minRatio) {
                minRatio = ratio;
                pivotRow = i;
            }
        }
    }
    return pivotRow;
}

// Perform row operations to update the simplex table
void SimplexMethod::pivot(vector<vector<double>>& table, int pivotRow, int pivotCol) {
    double pivotValue = table[pivotRow][pivotCol];
    
    // Divide the pivot row by the pivot element to make it 1
    for (int j = 0; j < table[0].size(); ++j) {
        table[pivotRow][j] /= pivotValue;
    }

    // Make other entries in the pivot column zero
    for (int i = 0; i < table.size(); ++i) {
        if (i != pivotRow) {
            double factor = table[i][pivotCol];
            for (int j = 0; j < table[0].size(); ++j) {
                table[i][j] -= factor * table[pivotRow][j];
            }
        }
    }
}

// Simplex algorithm to solve the simplex table
void SimplexMethod::simplex() {
    while (true) {
        int pivotCol = findPivotColumn(simplexTable);
        
        // If there is no negative element in the first row, optimal solution is found
        if (pivotCol == -1) {
            cout << "Optimal solution found.\n";
            break;
        }

        int pivotRow = findPivotRow(simplexTable, pivotCol);
        
        // If no valid pivot row is found, the solution is unbounded
        if (pivotRow == -1) {
            cout << "Unbounded solution.\n";
            return;
        }

        // Perform pivot operation
        pivot(simplexTable, pivotRow, pivotCol);
        
        // Display updated table (for debugging)
        displayTable(simplexTable);
    }

    // Display the optimal solution
    cout << "Optimal solution:\n";
    for (int i = 1; i < simplexTable.size(); ++i) {  // Start from the second row
        cout << "x" << i << " = " << simplexTable[i].back() << "\n";
    }
    cout << "Objective function value = " << simplexTable[0].back() << endl;
}

int SimplexMethod::solve(){
    cout << "Solve" << endl;
    simplex();
    return 1;
}



