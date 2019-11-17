

#ifndef UNTITLED17_DRAFTSLADY_H
#define UNTITLED17_DRAFTSLADY_H
#include "Checkers.h"

class DraftsLady:public Checkers {
public:
	//enum class Cell { w = 1, b = -1};
	explicit DraftsLady(Checkers::Cell col, Pos p) : colour(col), pos(p) {};
	DraftsLady() {};
	~DraftsLady() {};
	bool GetTitul() { return true; }
private:
	Cell colour;
	Pos pos;
};


#endif //UNTITLED17_DRAFTSLADY_H
