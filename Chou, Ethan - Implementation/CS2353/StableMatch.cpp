//
// Created by ethan on 3/11/2022.
//

#include "StableMatch.h"

using namespace std;
typedef vector<string> PrefList;
typedef map<string, PrefList> PrefMap;
typedef map<string, string> Couples;

/** references
 * https://rosettacode.org/wiki/Stable_marriage_problem#C.2B.2B
 * used to figure out how to pair things together
 * This function will first convert two lists of Elements to a string
 * and place it into 2 temporary 2d array of strings, then it will match them together
 * It will then call the prefer and stability function to make sure
 * the pairings are stable.
 * @param listA
 * @param listB
 */
void StableMatch::Matching(SetOfElements & listA, SetOfElements & listB) {
    int size = listA.getElements().size();
    string tempA[size + 1][size + 1];
    string tempB[size + 1][size + 1];
    vector<Element> tempVector;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size + 1; j++)
        {
            tempVector = listA.getElements().at(i).getPreferences();
            string tempString = tempVector.at(j).getName();
            tempA[i][j] = tempString;
        }
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size + 1; j++)
        {
            tempVector = listB.getElements().at(i).getPreferences();
            string tempString = tempVector.at(j).getName();
            tempB[i][j] = tempString;
        }
    }
    const char* listAChar[size + 1][size + 1];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size + 1; j++)
        {
            listAChar[i][j] = tempA[i][j].c_str();
        }
    }
    const char* listBChar[size + 1][size + 1];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size + 1; j++)
        {
            listBChar[i][j] = tempB[i][j].c_str();
        }
    }
    PrefMap listASet, listBSet;
    queue<string> single;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j < size + 1; ++j)
        {
            listASet[listAChar[i][0]].push_back(listAChar[i][j]);
            listBSet[listBChar[i][0]].push_back(listBChar[i][j]);
        }
        single.push(listAChar[i][0]);
    }
    Couples matched;
    while (!single.empty())
    {
        const string &matchmaker = single.front();
        const PrefList &preflist = listASet[matchmaker];

        for (const auto & bName : preflist)
        {
            if (matched.find(bName) == matched.end())
            {
                matched[bName] = matchmaker; //
                break;
            }

            const string &aName = matched[bName];

            if (prefers(listBSet[bName], matchmaker, aName))
            {
                single.push(aName); //
                matched[bName] = matchmaker;
                break;
            }
        }
        single.pop();
    }
    cout << "Stable Pairings:" << endl;
    for (Couples::const_iterator it = matched.begin(); it != matched.end(); ++it)
    {
        cout << "(" << it->first << ", " << it->second << ")" << endl;
    }

    check_stability(matched, listASet, listBSet);
}

/** references
 * https://rosettacode.org/wiki/Stable_marriage_problem#C.2B.2B
 * used to figure out how to pair things together
 * This function will check the stability of the pairing by
 * using the prefer function
 * @param matched
 * @param listA
 * @param listB
 */
void StableMatch::check_stability(const Couples &matched, const PrefMap &listA, const PrefMap &listB) {
    cout << endl;
    bool stable = true;
    for (auto it = matched.begin(); it != matched.end(); ++it)
    {
        const string &listAName = it->first;
        const string &listBName = it->second;
        const PrefList &prefList = listA.at(listBName);

        for (auto it = prefList.begin(); it != prefList.end(); ++it)
        {
            if (*it == listAName)
                break;
            if (prefers(prefList, *it, listAName) &&
                prefers(listB.at(*it), listBName, matched.at(*it)))
            {
                stable = false;
            }
        }
    }
    if (stable) cout << "Result of verification function: true" << endl;
}

/** references
 * https://rosettacode.org/wiki/Stable_marriage_problem#C.2B.2B
 * used to figure out how to pair things together
 * This function will check to see if the two people
 * int the pairings prefer each other, if not, it will return false
 * @param prefer
 * @param first
 * @param second
 */
bool StableMatch::prefers(const PrefList &prefer, const string &first, const string &second) {
    for (const auto & it : prefer)
    {
        if (it == first) return true;
        if (it == second) return false;
    }
    return false; // no preference
}




