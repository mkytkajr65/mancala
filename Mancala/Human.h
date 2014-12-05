#ifndef __HUMAN_
#define __HUMAN_
#include "Player.h"

class Human : public Player {
public:
	int takeTurn(player p, Mancala& game);
};
#endif