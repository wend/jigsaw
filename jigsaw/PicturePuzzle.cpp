#include "stdafx.h"
#include "PicturePuzzle.h"
#include "PictureElement.h"
#include "PictureElementSet.h"

PicturePuzzle::PicturePuzzle()
    : m_rowIndex(0)
    , m_columeIndex(0)
{
    m_puzzle  = new char*[PUZZLE_ROW];
    for (int i = 0; i < PUZZLE_ROW; i++)
    {
        m_puzzle[i] = new char[PUZZLE_COLUME];
        memset(m_puzzle[i], -1, PUZZLE_COLUME);
    }
}

PicturePuzzle::~PicturePuzzle()
{
    for (int i = 0; i < PUZZLE_ROW; i++)
    {
        delete m_puzzle[i];
    }
    delete m_puzzle;
}

int PicturePuzzle::jigsaw(PictureElement* element)
{
    int columeOffset = element->columeOffset;
    int rowOffset = element->rowOffset;
    int status = m_vElements.size()%2;
    status == 0 ? rowOffset = 0:columeOffset = 0;

    // row or colume over the bound
    if (m_columeIndex + element->colume - columeOffset > PUZZLE_COLUME || 
        m_rowIndex + element->row - rowOffset > PUZZLE_ROW || 
        m_columeIndex < columeOffset || 
        m_rowIndex < rowOffset)
    {
        return -1;
    }
    for (int i = 0; i < element->row; i++)
    {
        for (int j = 0; j < element->colume; j++)
        {
            // can't jigsaw this element as the picture is not match
            if (m_puzzle[m_rowIndex+i - rowOffset][m_columeIndex+j - columeOffset] != -1 && element->values[i][j] != -1)
            {
                return -1;
            }
            // can't jigsaw this element as the value is not macth value[i][j] = value[j][i]
            else if (element->values[i][j] != -1
                && m_puzzle[m_columeIndex+j - columeOffset][m_rowIndex+i - rowOffset] != -1
                && element->values[i][j] != m_puzzle[m_columeIndex+j - columeOffset][m_rowIndex+i - rowOffset])
            {
                return -1;
            }
        }
    }
    for (int i = 0; i < element->row; i++)
    {
        for (int j = 0; j < element->colume; j++)
        {
            if (element->values[i][j] != -1)
            {
                m_puzzle[m_rowIndex+i - rowOffset][m_columeIndex+j - columeOffset] = element->values[i][j];
            }
        }
    }
    element->rowIndex = m_rowIndex - rowOffset;
    element->columeIndex = m_columeIndex - columeOffset;
    return 0;
}

void PicturePuzzle::unJigsaw(PictureElement *element)
{
    for (int i = 0; i < element->row; i++)
    {
        for (int j = 0; j < element->colume; j++)
        {
            if(element->values[i][j] != -1)
            {
                m_puzzle[element->rowIndex + i][element->columeIndex + j] = -1;
            }
        }
    }
    int columeOffset = element->columeOffset;
    int rowOffset = element->rowOffset;
    int status = m_vElements.size()%2;
    status == 0 ? rowOffset = 0:columeOffset = 0;
    m_rowIndex = element->rowIndex + rowOffset;
    m_columeIndex = element->columeIndex + columeOffset;
}

void PicturePuzzle::updateIndex()
{
    if (m_vElements.size()%2 > 0)
    {
        for (int j = 0; j < PUZZLE_COLUME; j++)
        {
            for(int i = 0; i < PUZZLE_ROW; i++)
            {
                if(m_puzzle[i][j] == -1)
                {
                    m_rowIndex = i;
                    m_columeIndex = j;
                    return;
                }
            }
        }
    }
    else
    {
        for(int i = 0; i < PUZZLE_ROW; i++)
        {
            for (int j = 0; j < PUZZLE_COLUME; j++)
            {
                if(m_puzzle[i][j] == -1)
                {
                    m_rowIndex = i;
                    m_columeIndex = j;
                    return;
                }
            }
        }
    }
}

void PicturePuzzle::push(int elementIndex)
{
    m_vElements.push_back(elementIndex);
}

int PicturePuzzle::pop()
{
    if(m_vElements.size() == 0)
        return -1;
    int elementIndex = m_vElements[m_vElements.size()-1];
    m_vElements.pop_back();
    return elementIndex;
}

void PicturePuzzle::dump()
{
    cout << "Elements size: " << m_vElements.size() << endl;
    for (unsigned int i=0; i< m_vElements.size(); i++)
    {
        cout<<m_vElements[i]<<" ";
    }
    cout << endl;
    for(int i = 0; i < PUZZLE_ROW; i++)
    {
        for (int j = 0; j < PUZZLE_COLUME; j++)
        {
            cout << (int)m_puzzle[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
