#include "Mancala.h"

Mancala::Mancala(const Mancala& copy) {
	for (int i = 0; i < 2; i++) {
		store[i] = copy.store[i];
		for (int j = 0; j < nHouses; j++) {
			houses[i][j] = copy.houses[i][j];
		}
	}
}

void Mancala::setup() {
	store[two] = 0;
	store[one] = 0;
	for (int i = 0; i < nHouses; i++) {
		houses[two][i] = 3;
		houses[one][i] = 3;
	}
}

//Game logic
bool Mancala::play(player p, int house) {
	if (house < 0 || house > nHouses ) return true;
	int n = houses[p][house];
	if (n == 0) return true;
	houses[p][house] = 0;

	position pos;
	pos.side = p;
	pos.index = house;
	do {
		pos.index++;
		if (pos.index == nHouses) {
			if (pos.side == p) {
				pos = pos.opposite();
				store[p]++;
				n--;
				if (n == 0) {
					return true;
				}
			} else {
				pos = pos.opposite();
			}
		} else {
			houses[pos.side][pos.index]++;
			n--;
			position opp = pos.opposite();
			if (n == 0 && pos.side == p && houses[pos.side][pos.index] == 1 && houses[opp.side][opp.index] > 0) {
				store[p] += houses[pos.side][pos.index] + houses[opp.side][opp.index];
				houses[pos.side][pos.index] = 0;
				houses[opp.side][opp.index] = 0;
			}
		}
	} while(n > 0);
	return false;
}

//Final state check
bool Mancala::isGameOver() {
	int oneSide = 0;
	int twoSide = 0;
	for (int i = 0; i < nHouses; i++) {
		oneSide += houses[one][i];
		twoSide += houses[two][i];
	}
	
	if (oneSide == 0 || twoSide == 0) {
		store[one] += oneSide;
		store[two] += twoSide;
		return true;
	}
	return false;
}

#include <iostream>
using std::cout;
using std::endl;

void Mancala::printBoard() {
	cout << '\t';
	for (int i = nHouses - 1; i >= 0; i--) {
		cout << houses[two][i] << '\t';
	}
	cout << endl;

	cout << store[two] << "\t\t\t\t\t\t\t" << store[one] << endl;

	cout << '\t';
	for (int i = 0; i < nHouses; i++) {
		cout << houses[one][i] << '\t';
	}
	cout << endl;
}