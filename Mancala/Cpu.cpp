#include "cpu.h"
#include <cstdlib>
#include <iostream>

int alphabeta(Node* node, int depth, int alpha, int beta, player maximizingPlayer, player currentPlayer) {
	if (depth == 0) return node->generateAlphaBeta(maximizingPlayer);

	if (maximizingPlayer == currentPlayer) {
		int* h = node->getState()->getHouses(currentPlayer);
		for (int i = 0; i < Mancala::nHouses; i++) {
			if (h[i] > 0) {
				Node* newNode = new Node(*node->getState(), node->getNextPlayer(), i);
				int nAlpha = alphabeta(newNode,  depth - 1, alpha, beta, maximizingPlayer, node->getNextPlayer());
				alpha = alpha > nAlpha?alpha:nAlpha;
				if (beta <= alpha) break;
			}
		}
		return alpha;
	} else {
		int* h = node->getState()->getHouses(currentPlayer);
		for (int i = 0; i < Mancala::nHouses; i++) {
			if (h[i] > 0) {
				Node* newNode = new Node(*node->getState(), node->getNextPlayer(), i);
				int nBeta = alphabeta(newNode,  depth - 1, alpha, beta, maximizingPlayer, node->getNextPlayer());
				beta = beta < nBeta?beta:nBeta;
				if (beta <= alpha) break;
			}
		}
		return beta;
	}
}

int CPU::takeTurn(player p, const Mancala& game) {
	Node* top = new Node(game, p, -1);

	int max = INT_MIN;
	int choice = -1;
	for (int i = 0; i < Mancala::nHouses; i++) {
		if (top->getState()->getHouses(p)[i] > 0) {
			Node* n = new Node(*top->getState(), p, i);
			int v = alphabeta(n, level, INT_MIN, INT_MAX, p, oppositePlayer(p));
			if (v >= max) {
				max = v;
				choice = i;
			}
		}
	}
	if (choice == -1) throw "error";
	std::cout << "CPU moves house: " << choice << std::endl;
	return choice;
}

