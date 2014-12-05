#ifndef __PLAYER_
#define __PLAYER_
#include "Mancala.h"

class Player {
public:
	virtual int takeTurn(player p, Mancala& game) = 0;
};
#endif