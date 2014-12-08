#ifndef __CPU_
#define __CPU_
#include "Mancala.h"
#include "Player.h"
#include <limits.h>
#include <vector>

class CPU : public Player {
public:
	CPU(int level) { this->level = level; }
	int takeTurn(player p, const Mancala& game);
private:
	int level;
};

class Node {
public:
	Node(const Mancala& state, player p, int move) {
		playerMove = p;
		this->move = move;
		stateAfterMove = new Mancala(state);
		if (stateAfterMove->play(p, move)) {
			nextPlayer = p;
		} else {
			nextPlayer = oppositePlayer(p);
		}
	}

	Mancala* getState() { return stateAfterMove; }
	player getPlayer() { return playerMove; }
	player getNextPlayer() { return nextPlayer; }
	int getMove() { return move; }

	int generateAlphaBeta(player me) {
		return stateAfterMove->getStore(me) - stateAfterMove->getStore(oppositePlayer(me));
	}
private:
	Mancala* stateAfterMove;
	player playerMove;
	int move;
	player nextPlayer;
};
#endif