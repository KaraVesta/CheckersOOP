

#ifndef UNTITLED17_GAMEHANDLER_H
#define UNTITLED17_GAMEHANDLER_H

#include "IO.h"
//class IO;
//class Checkers;
//class Board;

class Game {
private:
    enum Player: int {Nobody=0, White=1, Black=-1};
    Player Current;
    unsigned int wscore;
    unsigned int bscore;
    Board GameBoard;
    IO GameIO;
	Player GetWin(bool I) const;
public:
    Game():wscore(0),bscore(0), Current(White){};
	~Game() {};
    void Start();
    int GetCurrentPlayer() {return Current;}

};


#endif //UNTITLED17_GAMEHANDLER_H
