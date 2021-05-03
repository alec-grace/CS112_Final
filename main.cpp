/********************************************************************
 * Filename: main.cpp
 * Author: Alec Grace
 * Description:
********************************************************************/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Alec.h"
#include "NHLstats.h"

using namespace std;

int main() {

    int choice;
    double homeAvg, awayAvg;
    string choiceMessage = "Enter Choice: ";
    vector<int> homePIMs, awayPIMs;

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
                    << "3. Who gives the most penalty minutes?" << endl
                    << "4. Who gives the lest penalty minutes?" << endl
                    << "5. What is the average number of penalty minutes per game?" << endl
                    << "6. Do penalty minutes significantly impact the game?" << endl
                    << "7. Quit" << endl << endl;

                choice = getIntput(choiceMessage, 1, 7);

                switch (choice) {
                    case 1:
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
                    case 2:
                        cout << "OK" << endl;
                        break;
                    default:
                        cout << "Why are you here?" << endl;
                        break;
                }
                break;
            case 2:
                cout << "--Not implemented--" << endl;
                break;
            case 3:
                cout << "--Not implemented--" << endl;
                break;
            case 4:
                exit(0);
            default:
                cout << "Why are you here?" << endl;
                break;
        }

    } while (playAgain());


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