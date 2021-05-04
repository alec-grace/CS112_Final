/*************************************************************************
 * Filename: Referee.cpp
 * Date created: 5/3/2021
 *
 * Description: Implementation file for the Ref struct
*************************************************************************/

#include <string>
#include "Referee.h"

Ref::Ref(string name, string id) {
    this->name = name;
    game_ids.push_back(id);
}