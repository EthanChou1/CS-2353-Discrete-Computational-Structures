#include <iostream>
#include <fstream>
#include "ListGenerator.h"
using namespace std;
int main(int argc, char** argv) {
    cout << "Attempting to open " << argv[2] << endl;
    cout << "Attempting to open and write to " << argv[3] << endl;
    cout << "Attempting to open and write to " << argv[4] << endl;
    vector<string> listA;
    vector<string> listB;
    ifstream nameList(argv[2]);
    ofstream setA(argv[3]);
    ofstream setB(argv[4]);
    ListGenerator generator;
    int setNum = atoi(argv[1]);
    cout << "How many elements do you want per name (Maximum of (Total number of names in list / 2) ex: 100 total names / 2 = maximum of 50 pairs)?" << endl;
    cout << "This number should be typed into the program arguments in CLion." << endl;
    cout << "Generating Sets..." << endl;

    generator.readNameList(nameList, listA, listB, setNum);
    generator.outputToSetA(setA, listA, listB, setNum);
    generator.outputToSetB(setB, listA, listB, setNum);

    cout << "Writing to File..." << endl;
    cout << "Done!" << endl;
    nameList.close();
    setA.close();
    setB.close();
    return 0;
}
