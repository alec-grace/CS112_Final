/********************************************************************
 * Filename: main.cpp
 * Author: Alec Grace
 * Description:
********************************************************************/

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Alec.h"
#include "Game.h"
#include "NHLstats.h"
#include "Referee.h"

using namespace std;

int main() {

    int choice;
    double homeAvg, awayAvg;
    string fName, lName, choiceMessage = "Enter Choice: ";
    vector<int> homePIMs, awayPIMs;
    vector<Ref> completeRefs, allRefs;
    vector<Game> allGames;
    vector<string> top3, mostRef;

    do
    {
        cout << "Which category of stats would you like to view?" << endl
            << "1. Officials" << endl
            << "2. Players" << endl
            << "3. Teams" << endl
            << "4. Quit" << endl << endl;
        choice = getIntput(choiceMessage, 1, 4);

        switch (choice) {
            case 1:             //Official Stats
                cout << "1. Do officials favor home teams on average?" << endl
                    << "2. Do specific officials favor home teams?" << endl
                    << "3. Who gives the most penalties per game?" << endl
                    << "4. Who gives the least penalties per game?" << endl
                    << "5. Quit" << endl << endl;

                choice = getIntput(choiceMessage, 1, 6);

                switch (choice) {
                    case 1: //Average penalties and penalty minutes
                        homePIMs = getHomePIMs();
                        awayPIMs = getAwayPIMs();
                        homeAvg = getAvg(homePIMs);
                        awayAvg = getAvg(awayPIMs);

                        cout << fixed;
                        cout.precision(2);

                        cout << "Average number of penalty minutes given to home teams: "
                            << homeAvg << endl
                            << "Average number of penalty minutes given to away teams: "
                            << awayAvg << endl;


                        cout << "The average number of penalties given to home teams: "
                            << getHomePenalties() << endl
                            << "The average number of penalties given to away teams: "
                            << getAwayPenalties() << endl;

                        cout << "Conclusion: Based on how close the values are, it does not "
                            << endl << "look like there is any advantage to the home team overall."
                            << endl << endl;
                        break;


                    case 2: //Officials most biased towards home teams
                        if (!completeRefs.empty()) {
                            top3 = getTop3(completeRefs);
                        } else {
                            completeRefs = getCompleteRefs(getRefStructs(), getGameStructs());
                            top3 = getTop3(completeRefs);
                        }


                        cout << "It does seem like there are some refs that favor the home " << endl
                            << "team in terms of penalties. These are the top 3 offenders " << endl
                            << "and their ratio of home to away penalties: " << endl << endl;
                        for (string const &ref : top3) {
                            cout << ref << endl;
                        }
                        cout << endl;
                        break;


                    case 3:
                        if (!completeRefs.empty()) {
                            mostRef = getMostPenalties(completeRefs);
                        } else {
                            completeRefs = getCompleteRefs(getRefStructs(), getGameStructs());
                            mostRef = getMostPenalties(completeRefs);
                        }
                        fName = split(mostRef[0], " ")[0];
                        lName = split(mostRef[0], " ")[1];
                        fName[0] = toupper(fName[0]);
                        lName[0] = toupper(lName[0]);

                        cout << "Most penalties per game (minimum 10 games) is: " << fName << " " << lName
                        << " with " << mostRef[1] << " penalties in " << mostRef[2] << " games." << endl;
                        cout << endl;
                        break;

                    case 4:
                        if (!completeRefs.empty()) {
                            mostRef = getLeastPenalties(completeRefs);
                        } else {
                            completeRefs = getCompleteRefs(getRefStructs(), getGameStructs());
                            mostRef = getLeastPenalties(completeRefs);
                        }
                        fName = split(mostRef[0], " ")[0];
                        lName = split(mostRef[0], " ")[1];
                        fName[0] = toupper(fName[0]);
                        lName[0] = toupper(lName[0]);

                        cout << "Least penalties per game (minimum 10 games) is: " << fName << " " << lName
                             << " with " << mostRef[1] << " penalties in " << mostRef[2] << " games." << endl;
                        cout << endl;
                        break;


                    default:
                        cout << "Why are you here?" << endl;
                        break;
                }
                break;
            case 2:
                cout << "--Players not implemented--" << endl;
                break;
            case 3:
                cout << "--Teams not implemented--" << endl;
                break;
            case 4:
                exit(0);
            default:
                cout << "Why are you here?" << endl;
                break;
        }

    } while (playAgain());


//TESTING 123 TESTING 123 TESTING 123

////Ref Struct Testing
//    vector<Ref> myRefs = getRefStructs();
//
//    cout << myRefs[29].name << endl;
//    for (string id : myRefs[29].game_ids) {
//        cout << "Game: " << id << endl;
//    }
////Game Struct Testing
//    vector<Game> myGames = getGameStructs();
//
//    cout << myGames[0].game_id << endl;
//    cout << myGames[0].home_penalties << endl;
//    cout << myGames[0].away_penalties << endl;

//TESTING 123 TESTING 123 TESTING 123

// FILE EDITING FOR DATA CLEANING
//    fstream infile, outfile;
//    infile.open("game_team_stats.csv", ios::in);
//    outfile.open("new_game_team.csv", ios::out);
//
//    string line;
//    vector<string> curLine;
//
//    if (infile.is_open() && outfile.is_open()) {
//        while (getline(infile, line)) {
//            curLine = split(line);
//            if (curLine[10] == "NA") {
//                curLine.erase(curLine.begin()+10);
//                curLine.insert(curLine.begin()+10, "-1");
//            }
//            for (string &item : curLine) {
//                outfile << item << ",";
//            }
//            outfile << endl;
//        }
//    }
//
//    infile.close();
//    outfile.close();


    return 0;
}