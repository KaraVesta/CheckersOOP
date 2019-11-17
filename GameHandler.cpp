

#include "GameHandler.h"

Game::Player Game::GetWin(bool pass)const
{
    Player pers;
if (wscore==12)
    pers=White;
else if (bscore==12)
    pers=Black;
else if (pass)
{
    if (Current==White)
        pers=Black;
    if (Current==Black)
        pers=White;
}
else pers=Nobody;

return pers;
}

void Game::Start() {
    //отрисовка доски=> её нужно создать в базовой комплектации
    // берём команду, по умолчанию ходят белые
    // делаем ход
    // пока не соблюдены условия выхода из игры
    // обновить информацию о текущем игроке и счёте
	//this->GameBoard.get_instance();
    GameBoard=Board::get_instance();
    GameBoard.Rbord();
    while (GetWin(GameIO.Getpass())==Nobody)
    {
        GameIO.DrawBoard(GameBoard.GetBoard());
        Pos start=Pos(0,0);
        Pos fin= Pos(0, 0);
        while (!GameIO.TakeCommand(start, fin));
        if (GameIO.Getpass()==true)
        {
            continue;
        }
		int ate= GameBoard.PseudoServant(GameBoard.GetBoard()[start.first][start.second], fin);
        if (ate!=-1) {
            if (ate!=0) {
				Checkers cur = GameBoard.GetBoard()[fin.first][fin.second];
                switch (cur.GetColour()) {
                    case 1: {
                        bscore+=ate;
                    }
                    case -1: {
                        wscore+=ate;
                    }
                }
            }
            Current = Game::Player(GameBoard.GetBoard()[start.first][start.second].GetColour());



        }



    }



}
