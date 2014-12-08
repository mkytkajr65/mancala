#include "Human.h"
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int Human::takeTurn(player p, const Mancala& game) {
	int input;
	do {
	if (p == player::one) cout << "Player 1: ";
	else cout << "Player 2: ";
	cout << "Which pit do you wish to move? ";
	cin >> input;
	input--;
	cin.clear();
	} while (!(input >= 0 && input < 6));

	return input;
}