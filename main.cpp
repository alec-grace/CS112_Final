/********************************************************************
 * Filename: main.cpp
 * Author: Alec Grace
 * Description:
********************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Alec.h"

using namespace std;

int main() {

    vector<string> oldLine, newLine;
    string curLine;

    fstream infile, outfile;
    infile.open("og_game_team_stats.csv", ios::in);
    outfile.open("game_team_stats.csv", ios::out);
    if (infile.is_open()) {
        while (getline(infile, curLine)) {
            oldLine = split(curLine, ",");
            for (string line : oldLine) {
                strip(line, '"');
                outfile << line << ",";
            }
            outfile << endl;
        }
    }

    infile.close();
    outfile.close();

//    vector<string> curLine;
//    string line;
//
//    fstream infile, outfile;
//    infile.open("game.csv", ios::in);
//    outfile.open("game.csv", ios::out);
//
//    while (getline(infile, line)) {
//        curLine = split(line, ",");
//        curLine.erase(curLine.begin()+11);
//        curLine.pop_back();
//
//        for (string &obj : curLine) {
//            outfile << obj << ",";
//        }
//        outfile << endl;
//    }
//
//    infile.close();
//    outfile.close();

    return 0;
}