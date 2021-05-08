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
#include "Player.h"
#include "Referee.h"
#include "Team.h"

using namespace std;

int main() {

    //General variables
    int choice;
    string choiceMessage = "Enter Choice: ";
    vector<Game> allGames;

    //Referee variables
    double homeAvg, awayAvg;
    string refLastName, refFirstName;
    vector<int> homePIMs, awayPIMs;
    vector<Ref> completeRefs, allRefs;
    vector<string> top3, mostRef;

    //Player variables
    string playerFirstLast;
    vector<string> playerFullName;

    //Team variables
    string teamName;
    vector<string> bestMatch, worstMatch;
    double faceOffRatioW, faceOffRatioL;
    vector<double> takeGiveRatios;

    do
    {
        cout << "Which category of stats would you like to view?" << endl
            << "1. Officials" << endl
            << "2. Players" << endl
            << "3. Teams" << endl
            << "4. Quit" << endl << endl;
        choice = getIntput(choiceMessage, 1, 4);

        switch (choice) {
    ////Official Stats
            case 1:
                cout << "\tSelect a question to answer: "
                    << "1. Do officials favor home teams on average?" << endl
                    << "2. Do specific officials favor home teams?" << endl
                    << "3. Who gives the most penalties per game?" << endl
                    << "4. Who gives the least penalties per game?" << endl
                    << "5. Quit" << endl << endl;

                choice = getIntput(choiceMessage, 1, 6);
            //Referee calculations
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
                        refLastName = split(mostRef[0], " ")[0];
                        refFirstName = split(mostRef[0], " ")[1];
                        refLastName[0] = toupper(refLastName[0]);
                        refFirstName[0] = toupper(refFirstName[0]);

                        cout << "Most penalties per game (minimum 10 games) is: " << refLastName << " " << refFirstName
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
                        refLastName = split(mostRef[0], " ")[0];
                        refFirstName = split(mostRef[0], " ")[1];
                        refLastName[0] = toupper(refLastName[0]);
                        refFirstName[0] = toupper(refFirstName[0]);

                        cout << "Least penalties per game (minimum 10 games) is: " << refLastName << " " << refFirstName
                             << " with " << mostRef[1] << " penalties in " << mostRef[2] << " games." << endl;
                        cout << endl;
                        break;

                    case 5:
                        break;


                    default:
                        cout << "Why are you here?" << endl;
                        break;
                }
                break;


    ////Player Stats
            case 2:
                do {
                    cout << "Enter a players full name: ";
                    getline(cin, playerFirstLast);
                    playerFullName = split(playerFirstLast, " ");
                    if (playerFullName.size() != 2) {
                        cout << "Must enter in format [first name] [space] [last name]" << endl;
                    }
                } while (playerFullName.size() != 2);

                if (playerExists(playerFullName[0], playerFullName[1])) {
                    cout << "Select a statistic to view: " << endl
                        << "1. Average points per game" << endl
                        << "2. Average penalty minutes per game" << endl
                        << "3. Little things that contribute" << endl
                        << "4. Quit" << endl << endl;

                    choice = getIntput(choiceMessage, 1, 4);
                    Player player = createPlayer(playerFullName[0], playerFullName[1]);

                    switch (choice) {
                        case 1:
                            cout << player.fName << " " << player.lName << " averages "
                            << player.getAvgPoints() << " points per game. " << endl << endl;
                            break;

                        case 2:
                            cout << player.fName << " " << player.lName << " averages "
                            << player.getAvgPims() << " penalty minutes per game." << endl << endl;
                            break;

                        case 3:
                            cout << player.fName << " " << player.lName << " averages " << endl
                                << player.getAvgBlocked() << " blocked shots per game," << endl
                                << player.getTurnoverRatio() << " takeaways for every give away, " << endl
                                << "and has a " << player.plusMinus << " plus/minus overall." << endl << endl;
                            break;

                        case 4:
                            break;

                        default:
                            cout << "How did you get here??" << endl;
                            break;

                    }
                } else {
                    cout << "No player with the name \"" << playerFullName[0]
                        << playerFullName[1] << "\" exists in this file. " << endl << endl;
                }
                break;


            case 3:
                cout << "Enter a team name:  ";
                getline(cin, teamName);

                if (teamExists(teamName)) {
                    cout << "Select statistic to view: " << endl
                        << "1. Team they win the most against" << endl
                        << "2. Team they win the least against" << endl
                        << "3. Face-off win % vs game win/loss" << endl
                        << "4. Giveaway-takeaway ratio vs win/loss" << endl
                        << "5. Quit" << endl << endl;

                    choice = getIntput(choiceMessage, 1, 5);
                    Team thisTeam(teamName);

                    switch (choice) {
                        case 1:
                            thisTeam.compareTeams();
                            bestMatch = thisTeam.getBestMatchup();
                            cout << "The " << thisTeam.name << " match up best against: " << endl << "the "
                                << bestMatch[0] << " with a win/loss ratio of " << bestMatch[1] << endl << endl;
                            break;

                        case 2:
                            thisTeam.compareTeams();
                            worstMatch = thisTeam.getWorstMatchup();
                            cout << "The " << thisTeam.name << " match up worst against: " << endl << "the "
                                 << worstMatch[0] << " with a win/loss ratio of " << worstMatch[1] << endl << endl;
                            break;

                        case 3:
                            faceOffRatioW = thisTeam.getFaceOffsToWins();
                            faceOffRatioL = thisTeam.getFaceOffsToLosses();

                            cout << "The " << thisTeam.name << " average a " << faceOffRatioW << "% face off"
                            << " win percentage in games that they win." << endl
                            << "They also average a " << faceOffRatioL << "% face off win percentage"
                            << " in games that they lose." << endl << endl;
                            break;

                        case 4:
                            takeGiveRatios = thisTeam.getTurnOverRatios();

                            cout << "The " << thisTeam.name << " average " << takeGiveRatios[0]
                                << " takeaways for every give away in games they win." << endl
                                << "They average " << takeGiveRatios[1] << " in games they lose." << endl << endl;
                            break;

                        case 5:
                            break;

                        default:
                            cout << "How did you end up here???" << endl;
                            break;

                    }
                } else {
                    cout << "Team: [" << teamName << "] does not exist in this file." << endl << endl;
                }
                break;

            case 4:
                break;

            default:
                cout << "Why are you here?" << endl;
                break;

        }

    } while (playAgain());


////TESTING 123 TESTING 123 TESTING 123

//Ref Struct Testing
//    vector<Ref> myRefs = getRefStructs();
//
//    cout << myRefs[29].name << endl;
//    for (string id : myRefs[29].game_ids) {
//        cout << "Game: " << id << endl;
//    }
//Game Struct Testing
//    vector<Game> myGames = getGameStructs();
//
//    cout << myGames[0].game_id << endl;
//    cout << myGames[0].home_penalties << endl;
//    cout << myGames[0].away_penalties << endl;

////TESTING 123 TESTING 123 TESTING 123

//// FILE EDITING FOR DATA CLEANING
//    fstream infile, outfile;
//    infile.open("og_player_info.csv", ios::in);
//    outfile.open("player_info.csv", ios::out);
//
//    string line;
//    vector<string> curLine;
//
//    if (infile.is_open() && outfile.is_open()) {
//        while (getline(infile, line)) {
//            curLine = split(line);
//
//            for (string &item : curLine) {
//                if (find(curLine.begin(), curLine.end(), item) == curLine.end() - 1) {
//                    strip(item, '"');
//                    outfile << item << endl;
//                } else {
//                    strip(item, '"');
//                    outfile << item << ",";
//                }
//            }
//        }
//    }
//
//    infile.close();
//    outfile.close();


    return 0;
}
