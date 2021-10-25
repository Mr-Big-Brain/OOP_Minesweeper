#ifndef ABSTRACTPLAYERTURN_H
#define ABSTRACTPLAYERTURN_H

class AbstractPlayerTurn
{
    protected:
    int currentX=1, currentY=1;
    char operation;
    public:
    virtual void performTurn(int maxColumn, int maxLine)
    {
        cout<<"I am basic player turn function";
    }
    virtual int getCurrentX()
    {
        return currentX;
    }
    virtual int getCurrentY()
    {
        return currentY;
    }
    virtual char getOperation()
    {
        return operation;
    }
};

#endif // ABSTRACTPLAYERTURN_H
