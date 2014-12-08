#ifndef __HUMAN_
#define __HUMAN_
#include "Player.h"

class Human : public Player {
public:
	int takeTurn(player p, const Mancala& game);
};
#endif