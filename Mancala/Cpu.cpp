#include "cpu.h"
#include <cstdlib>
#include <vector>
#include <stack>
#include <iostream>
using std::cout;
using std::endl;

int DEPTH = 4;

int CPU::takeTurn(player p, const Mancala game) {
	Node* top = new Node(game, p, -1);
	Node* n = top;

	int depth = 0;
	//expand tree
	do {
		int* h = n->getState()->getHouses(n->getNextPlayer());
		do {
			if (n != top && n->getPlayer() == p && n->parent->getPlayer() != p && n->getBeta() < n->getAlpha()) {
				//prune
				//cout << "Pruning MAX" << endl;
				n = n->parent;
				depth--;
				break;
			}
			if (n != top && n->getPlayer() != p && n->parent->getPlayer() == p && n->getBeta() > n->getAlpha()) {
				//prune
				//cout << "Pruning MIN" << endl;
				n = n->parent;
				depth--;
				break;
			}
			if (n != top && n->iterater == Mancala::nHouses) {
				//cout << "Expanded all, moving up" << endl;
				if (n->parent->getPlayer() == p && n->parent->getAlpha() < n->getBeta()) { //MAX
					n->parent->setAlpha(n->getBeta());
				} else if (n->parent->getBeta() > n->getAlpha()) { //MIN
					n->parent->setBeta(n->getAlpha());
				}
				n = n->parent;
				depth--;
				break;
			}
			if (h[n->iterater] > 0) {
				//cout << "Expanding child" << endl;
				Node* newNode= new Node(*n->getState(), n->getNextPlayer(), n->iterater);
				newNode->setAlpha(n->getAlpha());
				newNode->setBeta(n->getBeta());
				newNode->parent = n;
				n->children.push_back(newNode);
				n->iterater++;
				depth++;

				if (depth == DEPTH) {
					//cout << "Generating base" << endl;
					newNode->generateAlphaBeta(p);
					if (n->getPlayer() == p && n->getAlpha() < newNode->getAlpha()) { //MAX 
						n->setAlpha(newNode->getAlpha());
					} else if (n->getBeta() > newNode->getBeta()) { //MIN
						n->setBeta(newNode->getBeta());
					}
					depth--;
					break;
				}
				n = newNode;
				break;
			}
			n->iterater++;
		} while(true);
	} while(top->iterater < Mancala::nHouses);

	int minValue = INT_MIN;
	int move = -1;
	for (int i = 0; i < top->children.size(); i++) {
		if (top->children[i]->getAlpha() > minValue) {
			minValue = top->children[i]->getAlpha();
			move = top->children[i]->getMove();
		}
	}
	cout << "Moving house " << move + 1 << endl;
	//std::cin.get();
	return move;
}

