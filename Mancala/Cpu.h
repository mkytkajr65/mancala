#ifndef __CPU_
#define __CPU_
#include "Mancala.h"
#include <limits.h>
#include <vector>

class CPU {
public:
	int takeTurn(player p, const Mancala game);
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

		alpha = INT_MIN;
		beta = INT_MAX;

		iterater = 0;
	}

	Mancala* getState() { return stateAfterMove; }
	player getPlayer() { return playerMove; }
	player getNextPlayer() { return nextPlayer; }
	int getMove() { return move; }

	int getAlpha() { return alpha; }
	int getBeta() { return beta; }
	void setAlpha(int a) { alpha = a; }
	void setBeta(int b) { beta = b; }

	void generateAlphaBeta(player me) {
		int h = stateAfterMove->getStore(me) - stateAfterMove->getStore(oppositePlayer(me));
		alpha = h;
		beta = h;
	}

	Node* parent;
	std::vector<Node*> children;
	int iterater;
private:
	Mancala* stateAfterMove;
	player playerMove;
	int move;
	player nextPlayer;

	int alpha;
	int beta;
};
#endif