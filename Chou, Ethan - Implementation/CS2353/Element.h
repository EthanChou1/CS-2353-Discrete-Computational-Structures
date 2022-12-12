//
// Created by ethan on 3/11/2022.
//

#ifndef CS2353_ELEMENT_H
#define CS2353_ELEMENT_H
#include <iostream>
#include <vector>
using namespace std;

class Element {
public:
    Element();
    Element(string nameInput);
    string getName();
    void addPreference(Element pref);
    vector<Element> getPreferences();
    void setName(string name);

private:
    string name;
    vector<Element> preferences;
};


#endif //CS2353_ELEMENT_H
