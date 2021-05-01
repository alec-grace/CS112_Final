/*************************************************************************
 * Filename: Alec.h
 * Date: 4/17/2021
 *
 * Description: My personal header file to use across all projects for
 * simple but useful functions like split and playAgain
 *
 * Last updated: 4/29/2021
*************************************************************************/

#include <string>
#include <iostream>
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

bool playAgain() {
    string ans;
    char newAns;
    do {
        cout << "Would you like to enter another game? (Y/N): ";
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

int randoNum(int start, int end)
{
    unsigned seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    static default_random_engine rand(seed);
    uniform_int_distribution<int> randDistro(start, end);

    return randDistro(rand);
}

void rStrip(string &str, char const &stripChar) {

    while (str.back() == stripChar)
        str.pop_back();
}

void rStrip(string &str) {

    while (str.back() == ' ')
        str.pop_back();
}

void lStrip(string &str, char const &stripChar) {

    while (str.front() == stripChar)
        str.erase(str.begin());
}

void lStrip(string &str) {

    while (str.front() == ' ')
        str.erase(str.begin());
}

void strip(string &str, char const &stripChar) {

    while (str.front() == stripChar)
        str.erase(str.begin());

    while (str.back() == stripChar)
        str.pop_back();
}

void strip(string &str) {

    while (str.front() == ' ')
        str.erase(str.begin());

    while (str.back() == ' ')
        str.pop_back();
}