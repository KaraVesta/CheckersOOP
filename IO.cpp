

#include "IO.h"
#include <iostream>
#include <string>


std::string lit={"ABCDEFGH"};
//std::cout << static_cast<int>(color); // результатом будет 1


bool IO::TakeCommand(Pos& start, Pos& fin) {
    std::string l;
    bool ret=false;
/*    Pos start;
    Pos fin;*/
    for (int i=0; i<2; i++) {
        getline(std::cin, l);
        if (l=="pass")
        {
            ret=true;
			Endofgame();
            return ret;
        }
        size_t pos = lit.find(l[0]);
        if (pos == std::string::npos)//ошибка
        {
            std::cout<<"Wrong values of cell";
            return false;

        }
        l = l[1];
        int t = atoi(l.c_str()) - 1;
        if (0 <= t && t < 8) {
            if (i==0) {
				Pos tmp = Pos(t, pos);
                start = std::move(tmp);
            }
            else {
                fin = std::move(Pos(t, pos));
            }
        }
        else{
            std::cout<<"Wrong values of cell";
            return false;

        }//ошибка
    }
    return true;
}

void IO::DrawBoard(Checkers (Bboard)[BoardS][BoardS]) {

  //  std::cout<<"   A  B  C  D  E  F  G  H"<<std::endl;
    std::cout<<"  A B C D E F G H"<<std::endl;
    for (int i=0; i<8; i++)//заменить на лямбда
    {
        std::cout<<i+1;
        for (int j=0; j<8; j++)//заменить на лямбда
        {
            std::cout<<"|";
            int n;
             n = Bboard[i][j].GetColour();
			 if (!Bboard[i][j].GetTitul())
			 {
				 switch (n) {
				 case 1: {
					 std::cout << "w";
					 break;
				 }
				 case -1: {
					 std::cout << "b";
					 break;
				 }
				 case 0: {
					 std::cout << "*";
					 break;
				 }
				 }
			 }
			 else
			 {
				 switch (n) {
				 case 1: {
					 std::cout << "W";
					 break;
				 }
				 case -1: {
					 std::cout << "B";
					 break;
				 }
				 }
			 }
        }
        std::cout<<"|"<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
}

IO::IO(){
    pass=false;
}
