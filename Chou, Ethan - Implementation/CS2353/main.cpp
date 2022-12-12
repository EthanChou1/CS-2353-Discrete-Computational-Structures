#include <iostream>
#include <fstream>
#include "driver.h"
using namespace std;
int main(int argc, char** argv) {
    cout << "Attempting to open " << argv[1] << endl;
    cout << "Attempting to open " << argv[2] << endl;
    ifstream setA(argv[1]);
    ifstream setB(argv[2]);
    driver mainDriver;
    SetOfElements listA;
    SetOfElements listB;
    StableMatch match;
    Element temp;
    mainDriver.createElement(setA, listA);
    mainDriver.createElement(setB, listB);
    mainDriver.outputSetA(temp, listA);
    mainDriver.outputSetB(temp, listB);
    match.Matching(listA, listB);

    return 0;
}
