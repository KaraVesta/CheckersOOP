

#include "Boarder.h"
#include <cmath>
#include <algorithm>
#include <vector>

void Board::Rbord()
{
/*    for (int i=0; i<BoardSize; i++)
		for (int j = 0; j < BoardSize; j++)
    {
        Checkers::Cell tmpst;
        if ((i>=0&&i<3) && ((i%2==0 && j%2==1) || (i%2==1 && j%2==0)))
            tmpst= Checkers::Cell::b;
        else  if (4<i && i<8 && ((i%2==1 && j%2==0) || (i%2==0 && j%2==1)))
            tmpst= Checkers::Cell::w;
        else tmpst= Checkers::Cell::e;
		Pos p = Pos(i, j);
        Checkers tmp(tmpst, p);
        board[i][j]=std::move(tmp);
    }*/

	for (int i = 0; i < BoardSize; i++)
		for (int j = 0; j < BoardSize; j++)
		{
			Checkers::Cell tmpst;
			if (i==1 && j==2 || i == 1 && j == 4 || i == 2 && j == 3)
				tmpst = Checkers::Cell::b;
			else  if (i == 1 && j == 6)
				tmpst = Checkers::Cell::w;
			else tmpst = Checkers::Cell::e;
			Pos p = Pos(i, j);
			Checkers tmp(tmpst, p);
			board[i][j] = std::move(tmp);
		}
}

int Board::PseudoServant(Checkers figure, const Pos& fin)
{
	int  score = 0;
	if (figure.GetTitul())
		Check2(figure, fin, score);
	else Check1(figure, fin, score);

	return score;
}





bool Board::Check1(Checkers figure, const Pos &fin, int& flag)//1 right 0  left
{

    bool ret=false;
	flag = -1;
    Checkers::Cell visavi;
    switch(figure.GetColour()) {
        case 1: {
            visavi = Checkers::Cell::b;
            break;
        }
        case -1: {
            visavi = Checkers::Cell::w;
            break;
        }
		default:
			return ret;
    }
    const Pos start= figure.GetPos();
	Checkers::Cell colour = Checkers::Cell(figure.GetColour());
    const int x=start.first-fin.first;
    const int y=start.second-fin.second;

    if (0<=fin.first && fin.first<=7 && 0<=fin.second && fin.second<=7){

        if (this->board[fin.first][fin.second].GetColour()==0) {
            Pos mid= Pos((start.first+fin.first)/2,(start.second+fin.second)/2);
            if (fabs(x)==2 && fabs(y)==2)//бита свободно ли место и стоит на битом месте вражья шашка рамки доски ещё
            {
                if (this->board[mid.first][mid.second].GetColour()==static_cast<int>(visavi)) {
                    ret = true;
                    flag=1;
					this->board[mid.first][mid.second].~Checkers();
					this->board[mid.first][mid.second]=Checkers(Checkers::Cell::e, mid);
					this->board[start.first][start.second].SetColour(Checkers::Cell::e);
					this->board[fin.first][fin.second].SetColour((Checkers::Cell)figure.GetColour());
                }

            } else if (fabs(x)==1 && fabs(y)==1)//не бита аналогишшшно
            {
                if (this->board[fin.first][fin.second].GetColour()==0){
                    ret=true;
					flag = 0;
					this->board[start.first][start.second].SetColour(Checkers::Cell::e);
					this->board[fin.first][fin.second].SetColour(colour);
                }
            }
			if (static_cast<int>(colour) == 1 && fin.first == 0) {
				board[fin.first][fin.second].BecomDraftsLady();
			}
			else if (static_cast<int>(colour) == -1 && fin.first == 7) {
				board[fin.first][fin.second].BecomDraftsLady();
			}
        }
    }
    return ret;


}


bool Board::Check2(Checkers figure, const Pos& fin, int& score)
{

	bool ret = false;
	score = -1;
	Checkers::Cell visavi;
	switch (figure.GetColour()) {
	case 1: {
		visavi = Checkers::Cell::b;
		break;
	}
	case -1: {
		visavi = Checkers::Cell::w;
		break;
	}
	default:
		return ret;
	}
	const Pos start = figure.GetPos();
	Checkers::Cell colour = (Checkers::Cell)figure.GetColour();
	const int x = start.first - fin.first;
	const int y = start.second - fin.second;
	std::vector <Pos> VisaviCells;
	if (fabs(x) == fabs(y) && board[fin.first][fin.second].GetColour()==0) {
		int ymin = start.second;
		int delx;
		int dely;
		if (y < 0)
		{
			if (x < 0) {
				delx = 1;
				dely = 1;
			}
			else//!
			{
				delx = -1;
				dely = 1;
			}
		}
		else {
			if (x < 0)//проверено
			{
				delx = 1;
				dely = -1;
			}
			else//!
			{
				delx = -1;
				dely = -1;
			}
		}
		bool prev=false;

		for (int i = start.first; i != fin.first; i += delx)
		{
			if (board[i][ymin].GetColour() == static_cast<int>(colour))
			{
				if (start.first == i && start.second == ymin)
				{
					prev = true;//начальная позиция, 
				}
				else return ret;
			}
			else
			if (board[i][ymin].GetColour() == static_cast<int>(visavi) && !prev) return ret;
			else if (board[i][ymin].GetColour() == static_cast<int>(visavi) && prev)
			{
				VisaviCells.push_back(board[i][ymin].GetPos());//едим
				prev = false;
			}
			else if (board[i][ymin].GetColour() == 0) prev = true;
			ymin+=dely;
		}
		score = 0;

		Checkers c=Checkers(Checkers::Cell::e, start);
		board[fin.first][fin.second]=std::move(board[start.first][start.second]);
		board[start.first][start.second]=std::move(c);

		for (auto i : VisaviCells)
		{
			score++;
			this->board[i.first][i.second].SetColour(Checkers::Cell::e);
		}
	}

	return ret;


}

Board::Board()
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			Checkers m=Checkers(Checkers::Cell::e, Pos(i,j));
			board[i][j]=m;
		}
}





