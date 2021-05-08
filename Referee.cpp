/*************************************************************************
 * Filename: Referee.cpp
 * Date created: 5/3/2021
 *
 * Description: Implementation file for the Ref struct
 * - final commit
*************************************************************************/

#include <string>
#include "Referee.h"

Ref::Ref(string name, string id) {
    this->name = name;
    game_ids.push_back(id);
    homePens = 0;
    awayPens = 0;
}

double Ref::getHomeAwayRatio() {
    double ratio = (double)homePens / awayPens;
    return ratio;
}

int Ref::getTotalPens() {
    return homePens + awayPens;
}

double Ref::getPenaltyGameRatio() {
    return (double) getTotalPens() / game_ids.size();
}
