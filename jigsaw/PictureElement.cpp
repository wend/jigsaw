#include "StdAfx.h"
#include "PictureElement.h"


PictureElement::PictureElement()
{
    row = 0;
    colume = 0;
    values = NULL;
    columeOffset = 0;
    rowOffset = 0;
    isUsed = false;
    rowIndex = 0;
    columeIndex = 0;
}
PictureElement::~PictureElement()
{
    if(values != NULL)
    {
        for (int i = 0; i < row; i++)
            delete values[i];
        delete values;
    }
}
int PictureElement::malloc()
{
    if (row > 0 && colume > 0)
    {
        values = new char*[row];
        for( int i = 0; i < row; i++)
        {
            values[i] = new char[colume];
            memset(values[i], -1, colume);
        }
        return 0;
    }
    return -1;
}

void PictureElement::dump()
{
    cout << row << "," << colume <<endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colume; j++)
        {
            cout << (int)values[i][j];
            if (j + 1 <= colume)
                cout << ",";
        }
        cout<<endl;
    }
    cout << rowOffset <<", "<< columeOffset<< endl;
    cout <<endl;
}
