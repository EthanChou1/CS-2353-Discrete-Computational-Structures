//
// Created by ethan on 3/11/2022.
//

#ifndef CS2353_DRIVER_H
#define CS2353_DRIVER_H
#include "Element.h"
#include "SetOfElements.h"
#include "StableMatch.h"
#include <fstream>
#include <cstring>
class driver {
public:
    void createElement(ifstream&, SetOfElements&);
    void addToSet(Element&, SetOfElements&);
    void outputSetA(Element&, SetOfElements&);
    void outputSetB(Element&, SetOfElements&);
    void match();
};


#endif //CS2353_DRIVER_H
