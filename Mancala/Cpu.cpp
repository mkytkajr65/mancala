#include "cpu.h"
#include <cstdlib>

int CPU::takeTurn(player p, Mancala& game) {

	return rand() % 6;
}