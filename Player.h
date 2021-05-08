/*************************************************************************
 * Filename: Player.h
 * Date created: 5/6/2021
 *
 * Description: Header file for the Player struct
 * - final commit
*************************************************************************/

#ifndef FINALPROJECT_PLAYER_H
#define FINALPROJECT_PLAYER_H

#include <vector>
#include <string>

using namespace std;

struct Player{
    string fName;
    string lName;
    string playerID;
    vector<string> game_ids;
    int goals;
    int assists;
    int pims;
    int takeaways;
    int giveaways;
    int blockedShots;
    int plusMinus;
    Player(string &firstName, string &lastName, string &id);
    double getAvgPoints();
    double getAvgPims();
    double getTurnoverRatio();
    double getAvgBlocked();
};

#endif //FINALPROJECT_PLAYER_H
