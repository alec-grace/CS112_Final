/*************************************************************************
 * Filename: Player.cpp
 * Date created: 5/6/2021
 *
 * Description: Implementation file for the Player struct
 * - final commit
*************************************************************************/

#include "Alec.h"
#include "Player.h"

using namespace std;

Player::Player(string &firstName, string &lastName, string &id) {
    fName = firstName;
    lName = lastName;
    playerID = id;
    goals = 0;
    assists = 0;
    pims = 0;
    takeaways = 0;
    giveaways = 0;
    blockedShots = 0;
    plusMinus = 0;
}

double Player::getAvgPoints() {

    double ppg = (double) (goals + assists) / game_ids.size();
    ppg = round2(ppg);

    return ppg;
}

double Player::getAvgPims() {

    double avgPims = (double) pims / game_ids.size();
    avgPims = round2(avgPims);

    return avgPims;
}

double Player::getTurnoverRatio() {

    double ratio = (double) takeaways / giveaways;
    ratio = round2(ratio);

    return ratio;
}

double Player::getAvgBlocked() {

    double avgBlocked = (double) blockedShots / game_ids.size();
    avgBlocked = round2(avgBlocked);

    return avgBlocked;
}
