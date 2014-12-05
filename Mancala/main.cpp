#include "Mancala.h"
#include "Human.h"
#include "cpu.h"
#include <iostream>

int main() {
	Mancala game;
	game.setup();

	Human one;
	CPU two;

	do {
		for (int input = one.takeTurn(player::one, game); game.play(player::one, input) && !game.isGameOver(); input = one.takeTurn(player::one, game));
		if (game.isGameOver()) break;
		for (int input = two.takeTurn(player::two, game); game.play(player::two, input) && !game.isGameOver(); input = two.takeTurn(player::two, game));
		if (game.isGameOver()) break;
	} while (true);

	if (game.getStore(player::one) > game.getStore(player::two)) {
		std::cout << "Player One Wins!" << std::endl;
	} else if (game.getStore(player::one) == game.getStore(player::two)) {
		std::cout << "Game ends in a tie..." << std::endl;
	} else {
		std::cout << "Player Two Wins!" << std::endl;
	}

	std::cin.get();

	return 0;
}