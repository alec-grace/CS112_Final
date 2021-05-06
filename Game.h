/*************************************************************************
 * Filename: Game.h
 * Date created: 5/3/2021
 *
 * Description: Header file for the Game struct
*************************************************************************/

#ifndef FINALPROJECT_GAME_H
#define FINALPROJECT_GAME_H

#include <string>
#include <vector>

using namespace std;

struct Game{
    string game_id;
    int home_penalties;
    int away_penalties;
    Game(string game_id, string penalties, char HoA);
};

#endif //FINALPROJECT_GAME_H
