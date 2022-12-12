//
// Created by ethan on 3/11/2022.
//

#ifndef LISTGENERATOR_LISTGENERATOR_H
#define LISTGENERATOR_LISTGENERATOR_H
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ListGenerator {
public:
    ListGenerator() = default;
    void readNameList(ifstream&, vector<string>&, vector<string>&, int&);
    void outputToSetA(ostream&, vector<string>&, vector<string>&, int&);
    void outputToSetB(ostream&, vector<string>&, vector<string>&, int&);
};


#endif //LISTGENERATOR_LISTGENERATOR_H
