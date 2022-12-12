//
// Created by ethan on 3/11/2022.
//

#include "Element.h"

Element::Element() {
    name = "placeholder";
    preferences;
}

Element::Element(string nameInput) {
    name = nameInput;
    preferences;
}

string Element::getName() {
    return name;
}

void Element::addPreference(Element pref) {
    preferences.push_back(pref);
}

vector<Element> Element::getPreferences() {
    return preferences;
}

void Element::setName(string nameInput) {
    name = nameInput;
}

