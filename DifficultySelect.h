#ifndef DIFFICULTYSELECT_H
#define DIFFICULTYSELECT_H

#include "ConsoleInterface.h"
#include "BasicMinesweeperVariables.h"

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

class DifficultySelect : public BasicMinesweeperVariables
{
    private:
    int pointerPosition;
    public:
    int getPointerPosition()
    {
        return pointerPosition;
    }
    int getBombCount()
    {
        return bombCount;
    }
    int getXSize()
    {
        return xSize;
    }
    int getYSize()
    {
        return ySize;
    }
    void enter_size()
    {
        ConsoleInterface consoleInterface;
        consoleInterface.printGreetingText();
        pointerPosition = 1;
        char choice;
        //a=_getch();
        //system("CLS");
        cout<<endl<<"     <Easy>    "<<endl<<"     Medium     "<<endl<<"      Hard     "<<endl<<"     Custom      ";
        while(choice!='f')
        {
            cout<<"Choose difficulty level"<<endl;
            choice=_getch();
            if(choice=='w'&&pointerPosition>1)
            {
                pointerPosition--;
            }
            else if(choice=='s'&&pointerPosition<4)
            {
                pointerPosition++;
            }
            else if(choice=='f')
            {
                if(pointerPosition==1)
                {
                    ySize=10;
                    xSize=5;
                    bombCount=5;
                }
                else if(pointerPosition==2)
                {
                    ySize=15;
                    xSize=10;
                    bombCount=15;
                }
                else if(pointerPosition==3)
                {
                    ySize=30;
                    xSize=15;
                    bombCount=45;
                }
                else
                {
                    system("CLS");
                    cout<<"Enter column number"<<endl;
                    cin>>ySize;
                    cout<<"Enter row number"<<endl;
                    cin>>xSize;
                    do
                    {
                        cout<<"Enter bomb number:"<<endl;
                        cin>>bombCount;
                    }
                    while(xSize*ySize<bombCount);


                }
                system("CLS");
                break;

            }
            else
            {

            }
            system("CLS");
            if(pointerPosition==1)
            {
                cout<<endl<<"     <Easy>    "<<endl<<"     Medium     "<<endl<<"      Hard     "<<endl<<"     Custom      ";
            }
            if(pointerPosition==2)
            {
                cout<<endl<<"      Easy     "<<endl<<"    <Medium>    "<<endl<<"      Hard     "<<endl<<"     Custom      ";
            }
            if(pointerPosition==3)
            {
                cout<<endl<<"      Easy     "<<endl<<"     Medium     "<<endl<<"     <Hard>    "<<endl<<"     Custom      ";
            }
            if(pointerPosition==4)
            {
                cout<<endl<<"      Easy     "<<endl<<"     Medium     "<<endl<<"      Hard     "<<endl<<"    <Custom>     ";
            }
        }

    }
};

#endif // DIFFICULTYSELECT_H
