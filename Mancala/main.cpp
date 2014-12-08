#include "Mancala.h"
#include "Human.h"
#include "Player.h"
#include "cpu.h"
#include <iostream>
using std::cout;
using std::endl;

void runGame(Player* one, Player* two) {
	Mancala game;
	game.setup();
	do {
		game.printBoard();
		for (int input = one->takeTurn(player::one, game); game.play(player::one, input) && !game.isGameOver(); input = one->takeTurn(player::one, game)) { game.printBoard(); }
		if (game.isGameOver()) break;
		game.printBoard();
		for (int input = two->takeTurn(player::two, game); game.play(player::two, input) && !game.isGameOver(); input = two->takeTurn(player::two, game)) { game.printBoard(); }
		if (game.isGameOver()) break;
	} while (true);

	if (game.getStore(player::one) > game.getStore(player::two)) {
		std::cout << "Player One Wins!" << std::endl;
	} else if (game.getStore(player::one) == game.getStore(player::two)) {
		std::cout << "Game ends in a tie..." << std::endl;
	} else {
		std::cout << "Player Two Wins!" << std::endl;
	}
}

int inputLevel() {
	int level = 0;
	do {
		cout << "What level CPU? ";
		std::cin >> level;
	} while(!(level > 0));
	return level;
}

int main() {
	do {
		Player* one;
		Player* two;
		int type = 0;
		do {
			cout << "Choose type of game: " << endl;
			cout << "Player 1 : Player 2" << endl;
			cout << "1: Player vs CPU" << endl;
			cout << "2: CPU vs Player" << endl;
			cout << "3: Player vs Player" << endl;
			cout << "4: CPU vs CPU" << endl;
			cout << "5: Exit" << endl;
			std::cin >> type;
		} while(!(type > 0 && type < 6));
		switch (type) {
		case 1:
			one = new Human();
			two = new CPU(inputLevel());
			break;
		case 2:
			one = new CPU(inputLevel());
			two = new Human();
			break;
		case 3:
			one = new Human();
			two = new Human();
			break;
		case 4:
			one = new CPU(inputLevel());
			two = new CPU(inputLevel());
			break;
		case 5:
			return 0;
		}

		runGame(one, two);
	} while(true);
	return 0;
}