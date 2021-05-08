/*************************************************************************
 * Filename: Team.h
 * Date created: 5/8/2021
 *
 * Description: Header file for the Team struct
 * - final commit
*************************************************************************/

#ifndef FINALPROJECT_TEAM_H
#define FINALPROJECT_TEAM_H

#include <string>
#include <vector>

using namespace std;

struct Team{
    string name;
    string teamID;

    string teamIDs[33][2]; //Table to get team name from id #
    int teamCompare[33][3]; //Each team has teamID, wins, losses

    Team(string &teamName);
    void compareTeams();
    vector<string> getBestMatchup();
    vector<string> getWorstMatchup();
    double getFaceOffsToWins();
    double getFaceOffsToLosses();
    vector<double> getTurnOverRatios();
};

#endif //FINALPROJECT_TEAM_H
