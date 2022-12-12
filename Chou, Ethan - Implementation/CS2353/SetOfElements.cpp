//
// Created by ethan on 3/11/2022.
//

#include "SetOfElements.h"

SetOfElements::SetOfElements(vector<Element>& temp) {
    elementsSet = temp;
}

void SetOfElements::addElement(Element e) {
    elementsSet.push_back((e));
}

vector<Element> SetOfElements::getElements() {
    return elementsSet;
}

