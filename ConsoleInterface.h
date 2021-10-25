#ifndef CONSOLEINTERFACE_H
#define CONSOLEINTERFACE_H

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

class ConsoleInterface
{
    public:
    void printGreetingText()
    {
        cout<<"Welcome to my minesweeper"<<endl;
        cout<<"Use WSAD keys to move                F key to fire                           and M key to mark"<<endl;
        cout<<"Press any button to continue :)";
        char a;
        a=_getch();
        system("CLS");
    }
    void printLoosingText()
    {
        string answer[7]={"IQ<10?","Better luck next time","Try one more time","Come on big brain","You lose","ERROR 403, not enough intelligence","This should be an easter egg losing text, but it is not"};
        int randomInteger = rand() % 7;
        cout<<endl<<answer[randomInteger];
    }
};

#endif // CONSOLEINTERFACE_H
