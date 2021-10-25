#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>

#include "Board.h"
#include "TurnManager.h"
#include "ConsoleInterface.h"

using namespace std;

int main()
{
    Board board;
    TurnManager turnManager;
    board.choose_difficulty();
    board.start();
    board.generateBombs(board.getBombCount());
    board.generateWaterAndNumbers();
    board.printBoard(1,1,'0');
    board.checkIfWin();
    while(board.get_isEnd()!=true)
    {
        turnManager.performTurn(board.getXSize(),board.getYSize());
        system("CLS");
        board.printBoard(turnManager.getCurrentX(),turnManager.getCurrentY(),turnManager.getOperation());
        board.checkIfWin();
    }
    char character;
    cout<<endl<<"Press any button to close the game";
    character=_getch();
    return 0;
}
