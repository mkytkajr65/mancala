#ifndef __MANCALA_
#define __MANCALA_

enum player { one = 0, two = 1 };

class Mancala {
public:
	const static int nHouses = 6;

	Mancala();
	~Mancala();
	Mancala(const Mancala&);
	void setup();
	int* getHouses(player p) { return houses[p]; }
	int getStore(player p) { return store[p]; }
	bool play(player p, int house);
	bool isGameOver();
	void printBoard();
private:
	int** houses;
	int* store;
};

struct position {
	player side;
	int index;

	position opposite() {
		position p;
		if (side == one) p.side = two;
		else p.side = one;
		p.index = Mancala::nHouses - index - 1;
		return p;
	}
};

#endif