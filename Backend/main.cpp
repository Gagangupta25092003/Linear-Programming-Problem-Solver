#include <vector>
#include <iostream>
#include "lPQuestion.h"
#include "fraction.h"
#include "simplexMethod.h"
using namespace std;

int main(){
    cout << "Started" << endl;
    lPQuestion ques = lPQuestion();
    cout << "Started" << endl;
    SimplexMethod sm = SimplexMethod(ques);
    sm.printSimplexTable();
    sm.solve();

    cout << "Done" << endl;
}