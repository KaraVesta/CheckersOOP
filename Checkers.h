

#ifndef UNTITLED17_CHECKERS_H
#define UNTITLED17_CHECKERS_H
#include <utility>
using Pos=std::pair <int, int>;

class Checkers;

class Checkers {
public:
    enum class Cell {w=1, b=-1, e=0};
	explicit Checkers(Cell col, Pos t) : colour(col), pos(t), titul(false) {}
	Checkers():titul(false) {};
	~Checkers() {};
    int GetColour() {return static_cast<int>(colour);}
    void SetColour(Cell st){colour=st;}
    Pos GetPos(){ return pos; }
    void SetPos(Pos position){ pos=position; }
	bool GetTitul() { return titul; }
	void BecomDraftsLady() { titul = true; }
private:
     Cell colour;//true - white
     Pos pos;
	 bool titul;
};
//если только приведение будет с мотором. Дикое, но симпатишное

#endif //UNTITLED17_CHECKERS_H
