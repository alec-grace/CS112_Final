/*************************************************************************
 * Filename: Referee.h
 * Date created: 5/3/2021
 *
 * Description: Header file for the Ref struct
*************************************************************************/

#ifndef FINALPROJECT_REFEREE_H
#define FINALPROJECT_REFEREE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Ref {
    string name;
    vector<string> game_ids;
    int homePens;
    int awayPens;
    int getTotalPens();
    double getPenaltyGameRatio();
    Ref(string name, string id);
    double getHomeAwayRatio();
};

#endif //FINALPROJECT_REFEREE_H
