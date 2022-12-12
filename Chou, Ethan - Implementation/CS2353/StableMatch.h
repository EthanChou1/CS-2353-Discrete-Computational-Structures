//
// Created by ethan on 3/11/2022.
//

#ifndef CS2353_STABLEMATCH_H
#define CS2353_STABLEMATCH_H
#include <iostream>
#include <vector>
#include "SetOfElements.h"
#include <map>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
#define SINGLE 0
using namespace std;
typedef vector<string> PrefList;
typedef map<string, PrefList> PrefMap;
typedef map<string, string> Couples;
class StableMatch {
public:
    StableMatch() = default;
    void Matching(SetOfElements&, SetOfElements&);
    bool prefers(const PrefList &prefer, const string &first, const string &second);
    void check_stability(const Couples &matched, const PrefMap &listA, const PrefMap &listB);
};


#endif //CS2353_STABLEMATCH_H
