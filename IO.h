

#ifndef UNTITLED17_IO_H
#define UNTITLED17_IO_H
#include <string>
#include <iostream>
#include "Boarder.h"

class Checkers;
class Board;

using Pos=std::pair <int, int>;

class IO {
private:
    static const size_t BoardS=8;
    //Board B=Board::get_instance();
   // static Checkers board[BoardS][BoardS];
	/*static*/ bool pass;//изменила
	
    
public:
	IO();
	~IO() {};
	void Endofgame() { std::cout << "pass"; pass=true; }
    bool Getpass(){return pass;}
    bool TakeCommand(Pos& start, Pos& fin);
    static void DrawBoard(Checkers (Bboard)[BoardS][BoardS]);


};


#endif //UNTITLED17_IO_H