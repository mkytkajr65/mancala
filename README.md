Mancala
=======

Running the program brings up a menu that allows you to choose a game type.

Player vs CPU : User input as the first player, AI as the second
CPU vs Player: User input as the second player, AI as the first
Player vs Player: Both players are user input
CPU vs CPU: Both players use AI control

When a CPU is chosen, the program will ask for an AI level, this is a number greater than 0 that defines how good the AI will be (the depth of the MinMax tree). Numbers over ~12 will take a long time.

Board setup
  X6  X5  X4  X3  X2  X1
X			 Y
  Y1  Y2  Y3  Y4  Y5  Y6

Where X is player two, and Y is player one, numbered places are the houses, and on the ends are the two stores.