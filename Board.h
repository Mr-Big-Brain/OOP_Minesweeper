#ifndef BOARD_H
#define BOARD_H

#include "ConsoleInterface.h"
#include "DifficultySelect.h"
#include "BasicMinesweeperVariables.h"

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>

class Board : public BasicMinesweeperVariables
{
private:
    char visibleCell[1000][1000];
    char invisibleCell[1000][1000];
    bool isEnd=false;
    DifficultySelect selectDifficulty;
public:
    void choose_difficulty()
    {
        selectDifficulty.enter_size();
        xSize = selectDifficulty.getXSize();
        ySize = selectDifficulty.getYSize();
        bombCount = selectDifficulty.getBombCount();
    }
    void start()
    {
        for(int x=1;x<=xSize;x++)
        {
            for(int y=1;y<=ySize;y++)
            {
                visibleCell[x][y]='.';
                invisibleCell[x][y]='0';
            }
        }
    }
    void printBoard(int mouseX,int mouseY,char operation)
    {
        if(operation=='0')
        {
            for(int x=1;x<=xSize;x++)
            {
                for(int y=1;y<=ySize;y++)
                {
                    if(x==mouseX&&y==mouseY)
                    {
                        cout<<"+";
                    }
                    else
                    cout<<visibleCell[x][y];
                }
                cout<<endl;
            }
            cout<<endl<<endl<<"Bombs left:"<<bombCount-getMarkedFieldsCount();
        }
        if(operation=='f'&&invisibleCell[mouseX][mouseY]<'9'&&invisibleCell[mouseX][mouseY]>'0')
        {
            visibleCell[mouseX][mouseY]=invisibleCell[mouseX][mouseY];
            printBoard(mouseX,mouseY,'0');
        }
        else if(operation=='f'&&invisibleCell[mouseX][mouseY]=='0')
        {
            PerformNullRecursion(mouseX,mouseY);
            visibleCell[mouseX][mouseY]='0';
            printBoard(mouseX,mouseY,'0');
        }
        else if(operation=='f'&&invisibleCell[mouseX][mouseY]=='9')
        {
            showLoosing();
        }
        else if(operation=='m'&&visibleCell[mouseX][mouseY]=='.')
        {
            visibleCell[mouseX][mouseY]='X';
            printBoard(mouseX,mouseY,'0');
        }
        else if(operation=='m'&&visibleCell[mouseX][mouseY]!='.')
        {
            printBoard(mouseX,mouseY,'0');
        }
    }
    void checkIfWin()
    {
        int markcount=getMarkedFieldsCount();
        if(markcount==bombCount)
        {
            isEnd=true;
            for(int x=1;x<=xSize;x++)
                {
                    for(int y=1;y<=ySize;y++)
                    {
                        if(visibleCell[x][y]=='X'&&invisibleCell[x][y]!='9')
                        {
                            isEnd=false;
                            break;
                        }
                    }
                }
                if(isEnd==true)
                {
                    cout<<endl<<endl<<"You win :)";
                }
        }

    }
    int getMarkedFieldsCount()
    {
        int markcount=0;
        for(int x=1;x<=xSize;x++)
        {
            for(int y=1;y<=ySize;y++)
            {
                if(visibleCell[x][y]=='X')
                {
                    markcount++;
                }
            }
        }
        return(markcount);
    }
    void showLoosing()
    {
        ConsoleInterface consoleInterface;
        showInvisibleFields();
        consoleInterface.printLoosingText();
        isEnd=true;
    }

    void PerformNullRecursion(int x,int y)
    {
        if(invisibleCell[x][y]=='0'&&visibleCell[x][y]=='.'&&x>0&&y>0&&x<=xSize&&y<=ySize)
        {
            visibleCell[x][y]=invisibleCell[x][y];
            PerformNullRecursion(x+1,y);
            PerformNullRecursion(x,y+1);
            PerformNullRecursion(x-1,y);
            PerformNullRecursion(x,y-1);
            PerformNullRecursion(x+1,y+1);
            PerformNullRecursion(x+1,y-1);
            PerformNullRecursion(x-1,y+1);
            PerformNullRecursion(x-1,y-1);
        }
        else if(invisibleCell[x][y]!='0')
        visibleCell[x][y]=invisibleCell[x][y];
    }
    void generateBombs(int bombCount)
    {
        srand(time(NULL));
        int x,y;
        for(int i=0;i<bombCount;i++)
        {
            x=rand()%xSize+1;
            y=rand()%ySize+1;
            if(invisibleCell[x][y]=='9')
            {
                bombCount++;
            }
            else
            invisibleCell[x][y]='9';
        }
    }
    void generateWaterAndNumbers()
    {
        int k=0;
        for(int x=1;x<=xSize;x++)
        {
            for(int y=1;y<=ySize;y++)
            {
                if(invisibleCell[x][y]!='9')
                {
                    if(invisibleCell[x+1][y]=='9')
                        k++;
                    if(invisibleCell[x][y+1]=='9')
                        k++;
                    if(invisibleCell[x-1][y]=='9')
                        k++;
                    if(invisibleCell[x][y-1]=='9')
                        k++;
                    if(invisibleCell[x+1][y+1]=='9')
                        k++;
                    if(invisibleCell[x+1][y-1]=='9')
                        k++;
                    if(invisibleCell[x-1][y-1]=='9')
                        k++;
                    if(invisibleCell[x-1][y+1]=='9')
                        k++;
                    invisibleCell[x][y]='0'+k;
                    k=0;
                }
            }
        }
    }
    void showInvisibleFields()
    {
        for(int x=1;x<=xSize;x++)
        {
            for(int y=1;y<=ySize;y++)
            {
                cout<<invisibleCell[x][y];
            }
            cout<<endl;
        }
    }
    int getYSize()
    {
        return ySize;
    }
    int getXSize()
    {
        return xSize;
    }
    bool get_isEnd()
    {
        return isEnd;
    }
    int getBombCount()
    {
        return bombCount;
    }
};

#endif // BOARD_H
