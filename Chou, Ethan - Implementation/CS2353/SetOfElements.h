//
// Created by ethan on 3/11/2022.
//

#ifndef CS2353_SETOFELEMENTS_H
#define CS2353_SETOFELEMENTS_H
#include <iostream>
#include <vector>
#include "Element.h"
using namespace std;

class SetOfElements {
public:
    SetOfElements() = default;
    SetOfElements(vector<Element>&);
    void addElement(Element e);
    vector<Element> getElements();
private:
    vector<Element> elementsSet;
};


#endif //CS2353_SETOFELEMENTS_H
