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
#include <cmath>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Alec.h"
#include "Game.h"
#include "Player.h"
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
                if (lowerCase(splitLine[1]) == lowerCase(ref.name) && splitLine[2] == "Referee") {
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
    infile.close();

    return refValues;
}

vector<Game> getGameStructs() {

    bool found;
    int addHome, addAway;
    char HoA;
    string line;
    vector<string> splitLine;
    vector<Game> gameValues;

    fstream infile;
    infile.open("game_team_stats.csv", ios::in);

    if (infile.is_open()) {
        getline(infile, line);
        while (getline(infile,line)) {
            found = false;
            splitLine = split(line);
            for (Game &game : gameValues) {
                if (splitLine[0] == game.game_id) {
                    found = true;
                    if (splitLine[2] == "home") {
                        addAway = stoi(splitLine[10]);
                        game.away_penalties = addAway;
                    } else if (splitLine[2] == "away") {
                        addHome = stoi(splitLine[10]);
                        game.home_penalties = addHome;
                    }
                    break;
                }
            }
            if (!found) {
                if (splitLine[2] == "home") {
                    HoA = 'A';
                } else {
                    HoA = 'H';
                }
                Game curGame = Game(splitLine[0], splitLine[10], HoA);
                gameValues.push_back(curGame);
            }
        }
    } else {
        cout << "Could not open \"game_team_stats.csv\"" << endl;
    }
    infile.close();

    return gameValues;
}

vector<Ref> getCompleteRefs(vector<Ref> refValues,
                               vector<Game> gameValues) {
    vector<string> currentRef;
    vector<Ref> completeRefs;
    string refString;

    for (Ref &curRef : refValues) {
        for (string game_id : curRef.game_ids) {
            for (Game &game : gameValues) {
                if (game_id == game.game_id) {
                    curRef.awayPens += game.away_penalties;
                    curRef.homePens += game.home_penalties;
                    break;
                }
            }
        }
        completeRefs.push_back(curRef);
    }

    return completeRefs;
}

vector<string> getTop3(vector<Ref> &allRefs) {
    vector<string> top3;
    vector<Ref> runningTotal;
    Ref placeholder = Ref("Placeholder", "12345");//had to put this in otherwise the return vector was empty??
    placeholder.awayPens = 1;
    runningTotal.push_back(placeholder);
    int index = 0, filler = 0;
    string addRef, stringVal, fName, lName;
    double roundedRatio;
    char zero = '0';

    for (Ref &curRef : allRefs) {
        if (curRef.game_ids.size() < 5) {
            continue;
        }
        index = 0;
        for (Ref &topRef : runningTotal) {
            if (curRef.getHomeAwayRatio() > topRef.getHomeAwayRatio() && filler >= 3) {
                runningTotal.erase(runningTotal.begin() + index);
                runningTotal.push_back(curRef);
                break;
            } else if (filler < 3) {
                if (filler == 1) {
                    runningTotal.erase(runningTotal.begin());
                }
                runningTotal.push_back(curRef);
                ++filler;
            }
            ++index;
        }
    }

    for (Ref &top : runningTotal) {
        roundedRatio = floor((top.getHomeAwayRatio() * 100.0) + 0.5)/100.0;
        stringVal = to_string(roundedRatio);
        rStrip(stringVal, zero);

        fName = split(top.name, " ")[0];
        lName = split(top.name, " ")[1];
        fName[0] = toupper(fName[0]);
        lName[0] = toupper(lName[0]);

        addRef = fName + " " + lName + " ratio: " + stringVal;
        top3.push_back(addRef);
    }

    return top3;
}

vector<string> getMostPenalties(vector<Ref> &allRefs) {
    Ref placeholder("joe", "1234");
    vector<string> mostRef;
    vector<Ref> bigMan {placeholder};

    for (Ref &curRef : allRefs) {
        if (curRef.getPenaltyGameRatio() > bigMan[0].getPenaltyGameRatio()
        && curRef.game_ids.size() > 10) {
            bigMan.clear();
            bigMan.push_back(curRef);
        }
    }

    mostRef.push_back(bigMan[0].name);
    mostRef.push_back(to_string(bigMan[0].getTotalPens()));
    mostRef.push_back(to_string(bigMan[0].game_ids.size()));

    return mostRef;
}

vector<string> getLeastPenalties(vector<Ref> &allRefs) {
    vector<string> leastRef;
    vector<Ref> bigMan;
    int counter = 0;

    for (Ref &curRef : allRefs) {
        if (counter == 0) {
            bigMan.push_back(curRef);
            ++counter;
        } else if (curRef.getPenaltyGameRatio() < bigMan[0].getPenaltyGameRatio()
            && curRef.game_ids.size() > 10) {
            bigMan.clear();
            bigMan.push_back(curRef);
        }
    }

    leastRef.push_back(bigMan[0].name);
    leastRef.push_back(to_string(bigMan[0].getTotalPens()));
    leastRef.push_back(to_string(bigMan[0].game_ids.size()));

    return leastRef;
}

bool playerExists(string &firstName, string &lastName) {
    bool exists = false;
    string line;
    vector<string> curLine;

    fstream infile;
    infile.open("player_info.csv", ios::in);

    if (infile.is_open()) {
        while (getline(infile, line)) {
            curLine = split(line);
            if (lowerCase(lastName) == lowerCase(curLine[2])
            && lowerCase(firstName) == lowerCase(curLine[1])) {
                exists = true;
                break;
            }
        }
    } else {
        cout << "Could not open \"player_info.csv\"" << endl;
        exists = false;
    }

    infile.close();
    return exists;
}

Player createPlayer(string &firstName, string &lastName) {
////Could have moved this to the Player constructor but
////did not realize until too late so I don't have time now

    fstream playerFile, gameFile;
    playerFile.open("player_info.csv", ios::in);
    gameFile.open("game_skater_stats.csv", ios::in);
    string noSkaterFirst = "Doesn't";
    string noSkaterLast = "Exist";
    string noSkaterID = "1111";

    Player skater(noSkaterFirst, noSkaterLast, noSkaterID);

    string line;
    vector<string> curLine;
    int counter = 0;

    if (playerFile.is_open() && gameFile.is_open()) {
        getline(playerFile, line);
        while (getline(playerFile, line)) {
            curLine = split(line);
            if (lowerCase(firstName) == lowerCase(curLine[1])
            && lowerCase(lastName) == lowerCase(curLine[2])) {
                skater.playerID = curLine[0];
                skater.fName = curLine[1];
                skater.lName = curLine[2];
                skater.fName[0] = toupper(skater.fName[0]);
                skater.lName[0] = toupper(skater.lName[0]);
                break;
            }
        }
        playerFile.close();

        getline(gameFile, line);
        while (getline(gameFile, line)) {
            ++counter;
            curLine = split(line);
            if (curLine[1] == skater.playerID) {
                skater.game_ids.push_back(curLine[0]);
                try {
                    skater.assists += stoi(curLine[4]);
                    skater.goals += stoi(curLine[5]);
                    if (curLine[13] != "NA")
                        skater.takeaways += stoi(curLine[13]);
                    if (curLine[14] != "NA")
                        skater.giveaways += stoi(curLine[14]);
                    if (curLine[17] != "NA")
                        skater.blockedShots += stoi(curLine[17]);
                    skater.plusMinus += stoi(curLine[18]);
                    skater.pims += stoi(curLine[10]);
                } catch (exception &e) {
                    cout << endl << "Error: " << e.what() << " at line " << counter << endl;
                }
            }
        }

        gameFile.close();
    } else {
        cout << "Could not open one of the files" << endl;
        Player(noSkaterFirst, noSkaterLast, noSkaterID);
    }

    return skater;
}
