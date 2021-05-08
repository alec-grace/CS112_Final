/*************************************************************************
 * Filename: Team.cpp
 * Date created: 5/8/2021
 *
 * Description: Implementation file for the Team struct
 * - final commit
*************************************************************************/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include "Alec.h"
#include "Team.h"

Team::Team(string &teamName) {
    name = teamName;
    name[0] = toupper(name[0]);

    string line;
    int index;
    vector<string> curLine;

    fstream teamFile;
    teamFile.open("team_info.csv", ios::in);

    if (teamFile.is_open()) {
        getline(teamFile, line);
        while (getline(teamFile, line)) {
            curLine = split(line);
            teamIDs[index][0] = curLine[0];
            teamIDs[index][1] = curLine[3];
            if (lowerCase(curLine[3]) == teamName) {
                teamID = curLine[0];
            }
            ++index;
        }
    } else {
        cout << "Could not open file \"team_info.csv\"" << endl;
    }
    teamFile.close();

    for (int i = 0; i <= 32; ++i) {
        if (i < 30) {
            teamCompare[i][0] = i + 1;
            teamCompare[i][1] = 0;
            teamCompare[i][2] = 0;
        } else if (i <= 32) {
            teamCompare[i][0] = i + 22;
            teamCompare[i][1] = 0;
            teamCompare[i][2] = 0;
        }
    }
}

void Team::compareTeams() {

    int win, loss, compareID;
    string line, nextLine;
    vector<string> curLine, subLine;

    fstream gameFile;
    gameFile.open("game_team_stats.csv", ios::in);

    if (gameFile.is_open()) {
        getline(gameFile, line);
        while (getline(gameFile, line)) {
            win = 0;
            loss = 0;
            curLine = split(line);
            if (curLine[1] == teamID) {
                if (curLine[3] == "TRUE")
                    win = 1;
                else
                    loss = 1;
                getline(gameFile, nextLine);
                subLine = split(nextLine);
                compareID = stoi(subLine[1]);
                if (compareID <= 30) {
                    teamCompare[compareID - 1][1] += win;
                    teamCompare[compareID - 1][2] += loss;
                } else if (compareID >= 52 && compareID <= 54) {
                    teamCompare[compareID - 22][1] += win;
                    teamCompare[compareID - 22][2] += loss;
                }

            }
        }
    } else {
        cout << "Could not open file \"game_team_stats.csv\"" << endl;
    }
    gameFile.close();
}

vector<string> Team::getBestMatchup() {

    double checkMax, curMax=0;
    int curMaxID;
    string maxStr, teamName;
    vector<string> team;

    for (int i=0; i < 33; ++i) {
        checkMax = (double) teamCompare[i][1] / teamCompare[i][2];
        checkMax = round2(checkMax);
        if (checkMax > curMax) {
            curMax = checkMax;
            curMaxID = teamCompare[i][0];
        }
    }

    maxStr = to_string(curMax);
    rStrip(maxStr, '0');

    for (int i = 0; i < 33; ++i) {
        if (teamIDs[i][0] == to_string(curMaxID)) {
            teamName = teamIDs[i][1];
            break;
        }
    }
    team.push_back(teamName);
    team.push_back(maxStr);
    return team;
}

vector<string> Team::getWorstMatchup() {

    double checkMax, curMax=5;
    int curMaxID;
    string maxStr, teamName;
    vector<string> team;

    for (int i=0; i < 33; ++i) {
        checkMax = (double) teamCompare[i][1] / teamCompare[i][2];
        checkMax = round2(checkMax);
        if (checkMax < curMax) {
            curMax = checkMax;
            curMaxID = teamCompare[i][0];
        }
    }

    maxStr = to_string(curMax);
    rStrip(maxStr, '0');

    for (int i = 0; i < 33; ++i) {
        if (teamIDs[i][0] == to_string(curMaxID)) {
            teamName = teamIDs[i][1];
            break;
        }
    }
    team.push_back(teamName);
    team.push_back(maxStr);
    return team;
}

double Team::getFaceOffsToWins() {

    int tracker = 0;
    double faceOffRatio;
    vector<double> faceOffWins;
    string line;
    vector<string> curLine;

    fstream gameFile;
    gameFile.open("game_team_stats.csv", ios::in);

    if (gameFile.is_open()) {
        getline(gameFile,line);
        while (getline(gameFile, line)) {
            ++tracker;
            curLine = split(line);
            if (curLine[1] == teamID) {
                if (curLine[3] == "TRUE" && curLine[12] != "NA") {
                    try {
                        faceOffWins.push_back(stod(curLine[12]));
                    } catch (exception &e) {
                        cout << e.what() << " on line " << tracker << endl;
                    }
                }
            }
        }
    } else {
        cout << "Could not open file \"game_team_stats.csv\"" << endl;
        return 0.0;
    }

    gameFile.close();

    faceOffRatio = (double)accumulate(faceOffWins.begin(), faceOffWins.end(), 0) / faceOffWins.size();
    faceOffRatio = round2(faceOffRatio);

    return faceOffRatio;
}

double Team::getFaceOffsToLosses() {

    int tracker = 0;
    double faceOffRatio;
    vector<double> faceOffLoss;
    string line;
    vector<string> curLine;

    fstream gameFile;
    gameFile.open("game_team_stats.csv", ios::in);

    if (gameFile.is_open()) {
        getline(gameFile,line);
        while (getline(gameFile, line)) {
            ++tracker;
            curLine = split(line);
            if (curLine[1] == teamID) {
                if (curLine[3] == "FALSE" && curLine[12] != "NA") {
                    try {
                        faceOffLoss.push_back(stod(curLine[12]));
                    } catch (exception &e) {
                        cout << e.what() << " on line " << tracker << endl;
                    }
                }
            }
        }
    } else {
        cout << "Could not open file \"game_team_stats.csv\"" << endl;
        return 0.0;
    }

    gameFile.close();

    faceOffRatio = (double)accumulate(faceOffLoss.begin(), faceOffLoss.end(), 0) / faceOffLoss.size();
    faceOffRatio = round2(faceOffRatio);

    return faceOffRatio;
}

vector<double> Team::getTurnOverRatios() {

    double takeAway, giveAway, avg, wins, losses;
    vector<double> ratios, turnoversW, turnoversL;
    string line;
    vector<string> curLine;

    fstream gameFile;
    gameFile.open("game_team_stats.csv", ios::in);

    if (gameFile.is_open()) {
        getline(gameFile, line);
        while (getline(gameFile, line)) {
            curLine = split(line);
            if (curLine[1] == teamID) {
                if (curLine[13] != "NA")
                    giveAway = stod(curLine[13]);
                if (curLine[14] != "NA")
                    takeAway = stod(curLine[14]);

                avg = (double)takeAway / giveAway;
                avg = round2(avg);

                if (curLine[3] == "TRUE" && !isinf(avg)
                && avg == avg)
                    turnoversW.push_back(avg);
                else if (!isinf(avg) && avg == avg)
                    turnoversL.push_back(avg);
            }
        }
    } else {
        cout << "Could not open file \"game_team_stats.csv\"" << endl;
    }

    gameFile.close();

    wins = (double) accumulate(turnoversW.begin(), turnoversW.end(), 0) / turnoversW.size();
    wins = round2(wins);

    losses = (double) accumulate(turnoversL.begin(), turnoversL.end(), 0) / turnoversL.size();
    losses = round2(losses);

    ratios.push_back(wins);
    ratios.push_back(losses);

    return ratios;
}
