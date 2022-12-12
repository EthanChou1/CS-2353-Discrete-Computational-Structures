//
// Created by ethan on 3/11/2022.
//

#include "ListGenerator.h"
using namespace std;

void ListGenerator::readNameList(ifstream& file, vector<string>& listA, vector<string>& listB, int& num) {
    char* buffer = new char[1000];
    string temp;
    int counter = 0;
    int secondCounter = 0;
    while(file.getline( buffer, 100) ) {
        if(counter < num)
        {
            temp = buffer;
            listA.push_back(temp);
            int count = 0;
            for(int i = 0 ; i < listA.size(); i++) //Removes duplicates
            {
                if(listA.at(i) == temp)
                {
                    count++;
                    if(count > 1)
                    {
                        listA.pop_back();
                        count = 0;
                    }
                }
            }
            counter++;
        }
        else if(counter >= num && secondCounter < num)
        {
            temp = buffer;
            listB.push_back(temp);
            int count = 0;
            for(int i = 0 ; i < listB.size(); i++) //Removes duplicates
            {
                if(listB.at(i) == temp)
                {
                    count++;
                    if(count > 1)
                    {
                        listB.pop_back();
                        count = 0;
                    }
                }
            }
            secondCounter++;
        }
    }
    delete[] buffer;
}

void ListGenerator::outputToSetA(ostream& output, vector<string>& listA, vector<string>& listB, int& num) {
    vector<string> temp = listB;
    output << num << endl;
    for(int i = 0; i < listA.size(); i++)
    {
        random_shuffle(temp.begin(), temp.end());
        output << listA.at(i) << ":";
        for(int j = 0; j < temp.size(); j++)
        {
            if(j < temp.size() - 1)
            {
                output << temp.at(j) << ",";
            }
            else if(j < temp.size())
            {
                output << temp.at(temp.size() - 1) << endl;
            }
        }
    }
}

void ListGenerator::outputToSetB(ostream& output, vector<string>& listA, vector<string>& listB, int& num) {
    vector<string> temp = listA;
    output << num << endl;
    for(int i = 0; i < listB.size(); i++)
    {
        random_shuffle(temp.begin(), temp.end());
        output << listB.at(i) << ":";
        for(int j = 0; j < temp.size(); j++)
        {
            if(j < temp.size() - 1)
            {
                output << temp.at(j) << ",";
            }
            else if(j < temp.size())
            {
                output << temp.at(temp.size() - 1) << endl;
            }
        }
    }
}
