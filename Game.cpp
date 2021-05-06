/*************************************************************************
 * Filename: Game.cpp
 * Date created: 5/3/2021
 *
 * Description: Implementation file for the Game struct
*************************************************************************/

#include "Game.h"

Game::Game(string game_id, string penalties, char HoA) {
    this->game_id = game_id;
    if (HoA == 'A') {
        away_penalties = stoi(penalties);
    } else {
        home_penalties = stoi(penalties);
    }
}
