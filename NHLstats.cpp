/*************************************************************************
 * Filename: NHLstats.cpp
 * Date created: 5/2/2021
 *
 * Description: Source file for the functions that retrieve
 * statistics in my final project.
 *
 * Last updated: 5/2/2021
*************************************************************************/

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Alec.h"
#include "Game.h"
#include "Referee.h"

using namespace std;

vector<int> getHomePIMs() {
    vector<int> totalPIMs;
    vector<string> curLine;
    string line, strPIM;
    int pim, lineTracker;

    fstream infile;
    infile.open("game_team_stats.csv", ios::in);

    if (infile.is_open()) {
        getline(infile, line);
        ++lineTracker;
        while(getline(infile, line)) {
            ++lineTracker;
            curLine = split(line);
            if (curLine[2] == "home") {
                try {
                    pim = stoi(curLine[9]);
                    if (pim >=0)
                        totalPIMs.push_back(pim);
                } catch (exception &e) {
                    cout << e.what() << endl;
                    // SUPER helpful when initially figuring out issues
                    cout << "Line: " << lineTracker << endl;
                }
            }
        }

    } else {
        totalPIMs.push_back(0);
        cout << "Failed to open file \"game_team_stats.csv\"" << endl;
    }

    return totalPIMs;
}

vector<int> getAwayPIMs() {
    vector<int> totalPIMs;
    vector<string> curLine;
    string line, strPIM;
    int pim, lineTracker;

    fstream infile;
    infile.open("game_team_stats.csv", ios::in);

    if (infile.is_open()) {
        getline(infile, line);
        ++lineTracker;
        while(getline(infile, line)) {
            ++lineTracker;
            curLine = split(line);
            if (curLine[2] == "away") {
                try {
                    pim = stoi(curLine[9]);
                    if (pim >= 0)
                        totalPIMs.push_back(pim);
                } catch (exception &e) {
                    cout << e.what() << endl;
                    cout << "Line: " << lineTracker << endl;
                }
            }
        }

    } else {
        totalPIMs.push_back(0);
        cout << "Failed to open file \"game_team_stats.csv\"" << endl;
    }

    return totalPIMs;
}

int getHomePenalties() {

    int lineTracker, penalties;
    double numTracker=0.0;
    string line;
    vector<string> curLine;

    fstream infile;
    infile.open("game_team_stats.csv", ios::in);

    if (infile.is_open()) {
        getline(infile, line);
        ++lineTracker;
        while (getline(infile, line)) {
            ++lineTracker;
            curLine = split(line);
            if (curLine[2] == "home") {
                try {
                    penalties += stoi(curLine[10]);
                    ++numTracker;
                } catch (exception &e) {
                    cout << e.what() << endl;
                    cout << "Line: " << lineTracker << endl;
                }
            }
        }
    } else {
        cout << "Something went wrong opening \"game_team_stats.csv\"" << endl;
    }

    return penalties / numTracker;
}

int getAwayPenalties() {

    int lineTracker, penalties;
    double numTracker=0.0;
    string line;
    vector<string> curLine;

    fstream infile;
    infile.open("game_team_stats.csv", ios::in);

    if (infile.is_open()) {
        getline(infile, line);
        ++lineTracker;
        while (getline(infile, line)) {
            ++lineTracker;
            curLine = split(line);
            if (curLine[2] == "away") {
                try {
                    penalties += stoi(curLine[10]);
                    ++numTracker;
                } catch (exception &e) {
                    cout << e.what() << endl;
                    cout << "Line: " << lineTracker << endl;
                }
            }
        }
    } else {
        cout << "Something went wrong opening \"game_team_stats.csv\"" << endl;
    }

    return penalties / numTracker;
}

double getAvg(vector<int> &rawNums) {
    double total = accumulate(rawNums.begin(), rawNums.end(), 0);
    double avg = total / rawNums.size();

    return avg;
}

vector<Ref> getRefStructs() {

    bool found;
    string line;
    vector<string> splitLine;
    vector<Ref> refValues;

    fstream infile;
    infile.open("game_officials.csv", ios::in);

    if (infile.is_open()) {
        getline(infile, line);
        while (getline(infile,line)) {
            found = false;
            splitLine = split(line);
            for (Ref &ref : refValues) {
                if (splitLine[1] == ref.name && splitLine[2] == "Referee") {
                    ref.game_ids.push_back(splitLine[0]);
                    found = true;
                    break;
                }
            }
            if (!found && splitLine[2] == "Referee") {
                Ref curRef = Ref(splitLine[1], splitLine[0]);
                refValues.push_back(curRef);
            }
        }

    } else {
        cout << "Could not open \"game_officials.csv\"" << endl;
    }

    return refValues;
}