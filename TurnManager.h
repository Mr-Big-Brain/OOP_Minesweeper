#ifndef TURNMANAGER_H
#define TURNMANAGER_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>

#include "AbstractPlayerTurn.h"

class TurnManager : public AbstractPlayerTurn
{
public:
    void performTurn(int maxColumn, int maxLine) override
    {
        char step;
        step=_getch();
        if(step=='w'&&currentX>1)
        {
            currentX--;
            operation='0';
        }
        else if(step=='d'&&currentY<maxLine)
        {
            currentY++;
            operation='0';
        }
        else if(step=='s'&&currentX<maxColumn)
        {
            currentX++;
            operation='0';
        }
        else if(step=='a'&&currentY>1)
        {
            currentY--;
            operation='0';
        }
        else if(step=='f')
        {
            operation='f';
        }
        else if(step=='m')
        {
            operation='m';
        }
    }
};

#endif // TURNMANAGER_H
