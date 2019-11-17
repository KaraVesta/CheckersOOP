
#ifndef UNTITLED17_BOARDER_H
#define UNTITLED17_BOARDER_H

#include "Checkers.h"
#include "DraftsLady.h"


class Board
{
private:
    static const size_t BoardSize=8;
	Checkers board[BoardSize][BoardSize];
	bool Check1(Checkers figure, const Pos& fin, int& flag);
	bool Check2(Checkers figure, const Pos& fin, int& score);

public:
    static Board & get_instance()
    {
        static Board instance;
        return instance;
    }
	//Checkers board[BoardSize][BoardSize];
    void Rbord(/*Checkers (&board)[8][8]*/);
	int PseudoServant(Checkers figure, const Pos& fin);
    auto GetBoard () { return board; }
    size_t GetBoardSize(){ return BoardSize;}
	Board();
	~Board() {};
};

#endif //UNTITLED17_BOARDER_H
