/*************************************************************************
 * Filename: Alec.h
 * Date created: 4/17/2021
 *
 * Description: My personal header file to use across all projects
 * for simple but useful functions like split and playAgain
 *
 * Last updated: 5/5/2021
*************************************************************************/

#include <string>
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

//Get yes or no input from user
bool playAgain() {
    string ans;
    char newAns;
    do {
        cout << "Would you like to view more stats? (Y/N): ";
        cin.sync();
        getline(cin, ans);
        newAns = ans[0];
    } while (!isalpha(newAns));

    if (tolower(newAns) == 'y') {
        return true;
    } else {
        return false;
    }
}

//Split a string with any string delimiter
vector<string> split(string str, string delimiter)
{
    vector<string> returnList;

    size_t pos = 0;
    string word;

    while ((pos = str.find(delimiter)) != string::npos) {
        word = str.substr(0, pos);
        returnList.push_back(word);
        str.erase(0, pos + delimiter.length());
    }

    returnList.push_back(str);

    return returnList;
}

//Split a string with default comma as delimiter
vector<string> split(string &str)
{
    vector<string> returnList;

    size_t pos = 0;
    string word;

    while ((pos = str.find(',')) != string::npos) {
        word = str.substr(0, pos);
        returnList.push_back(word);
        str.erase(0, pos + 1);
    }

    returnList.push_back(str);

    return returnList;
}

//Get a random integer within a range
int randoNum(int start, int end)
{
    unsigned seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    static default_random_engine rand(seed);
    uniform_int_distribution<int> randDistro(start, end);

    return randDistro(rand);
}

//Remove all specific chars from back of string
void rStrip(string &str, char const &stripChar) {

    while (str.back() == stripChar)
        str.pop_back();
}

//Remove all spaces from back of string
void rStrip(string &str) {

    while (str.back() == ' ')
        str.pop_back();
}

//Remove all specific chars from front of string
void lStrip(string &str, char const &stripChar) {

    while (str.front() == stripChar)
        str.erase(str.begin());
}

//Remove all spaces from front of string
void lStrip(string &str) {

    while (str.front() == ' ')
        str.erase(str.begin());
}

//Remove all specific chars from front and back of string
void strip(string &str, char const &stripChar) {

    while (str.front() == stripChar)
        str.erase(str.begin());

    while (str.back() == stripChar)
        str.pop_back();
}

//Remove all spaces from front and back of string
void strip(string &str) {

    while (str.front() == ' ')
        str.erase(str.begin());

    while (str.back() == ' ')
        str.pop_back();
}

//Take input as an integer within a range
int getIntput(string &message, int beginRange, int endRange) {
    bool incorrect = true;
    string strInput;
    int intput;

    cout << message;

    do
    {
        getline(cin, strInput);

        try {
            intput = stoi(strInput);
            incorrect = false;
        }
        catch (exception &e) {
            cout << "ERROR: " << e.what() << endl;
            incorrect = true;
            intput = -1;
        }

        if (intput < beginRange || intput > endRange){
            cout << "Must be a integer between " << to_string(beginRange)
                << " and " << endRange << "..." << endl << "Choice: ";
            incorrect = true;
        }

    } while (incorrect);

    return intput;
}

//Take input as an integer, no range
int getIntput(string &message) {
    bool incorrect = true;
    string strInput;
    int intput;

    cout << message;

    do
    {
        getline(cin, strInput);

        try {
            intput = stoi(strInput);
            incorrect = false;
        }
        catch (exception &e) {
            cout << "ERROR: " << e.what() << endl;
            incorrect = true;
            intput = -1;
        }

    } while (incorrect);

    return intput;
}

//Get the index of a specific string in a vector of strings
int getIndex(string const &findStr, vector<string> const &searchVec) {

    int index;
    auto it = find(searchVec.begin(), searchVec.end(), findStr);

    if (it != searchVec.end()) {
        index = it - searchVec.begin();
    } else {
        index = -1;
    }

    return index;
}

//Changes whole string to lowercase
string lowerCase(string &my_str) {
    transform(my_str.begin(), my_str.end(), my_str.begin(), ::tolower);
    return my_str;
}

//Rounds a double to 2 decimal places
double round2(double &toRound) {
    double rounded;
    rounded = floor((toRound * 100.0) + 0.5)/100.0;

    return rounded;
}
