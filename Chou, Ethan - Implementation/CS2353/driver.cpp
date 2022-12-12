//
// Created by ethan on 3/11/2022.
//

#include "driver.h"

void driver::createElement(ifstream& file, SetOfElements& list) {
    string temp;
    string temp2;
    bool first = true;
    char* buffer = new char[5000];
    int count = 0;
    int compare = 0;

    while(file.getline( buffer, 5000))
    {
        Element name;
        if(first)
        {
            file.getline( buffer, 5000);
            first = false;
        }
        char* word = strtok(buffer, "\"");
        while(word != nullptr)
        {
            char *token = strtok(word, ":,");
            if(count == 0)
            {
                temp = token;
//                cout << temp << ":";
                name.setName(temp);
                name.addPreference(temp);
                count++;
            }
            else
            {
                temp = token;
//                cout << temp << ",";
                name.addPreference(temp);
            }
            word = strtok(nullptr, "\"");
        }
//        cout << endl;
        count = 0;
        addToSet(name, list);
    }
    delete[] buffer;
}

void driver::addToSet(Element &e, SetOfElements& list) {
    list.addElement(e);
}

void driver::outputSetA(Element &temp, SetOfElements& listA) {
    cout << "Set A contains:" << endl;
    for(int i = 0; i < listA.getElements().size(); i++)
    {
        temp.setName(listA.getElements().at(i).getName());
        cout << temp.getName() <<":  (";
        vector<Element> test = listA.getElements().at(i).getPreferences();
        for(int j = 1; j < test.size() - 1; j++)
        {
            cout << test.at(j).getName() <<", ";
        }
        cout << test.at(test.size() - 1).getName() <<")";
        cout << endl;
    }
    cout << endl;
}

void driver::outputSetB(Element &temp, SetOfElements &listB) {
    cout << "Set B contains:" << endl;
    for(int i = 0; i < listB.getElements().size(); i++)
    {
        temp.setName(listB.getElements().at(i).getName());
        cout << temp.getName() <<":  (";
        vector<Element> test = listB.getElements().at(i).getPreferences();
        for(int j = 1; j < test.size() - 1; j++)
        {
            cout << test.at(j).getName() <<", ";
        }
        cout << test.at(test.size() - 1).getName() <<")";
        cout << endl;
    }
    cout << endl;
}

