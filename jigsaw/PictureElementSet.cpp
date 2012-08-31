#include "StdAfx.h"
#include "PictureElement.h"
#include "PictureElementSet.h"


PictureElementSet::PictureElementSet()
    : m_leftCount(0)
{
}

PictureElementSet::~PictureElementSet()
{
    vector<PictureElement*>::iterator it;
    for (it = m_vElements.begin(); it != m_vElements.end(); it++)
    {
        PictureElement *element = *it;
        delete element;
    }
    m_vElements.clear();
}

// read from file to init the picture elements
int PictureElementSet::initialize(const char* fileName)
{
    std::ifstream file;
    //char *fileName = "d:\\test\\jigsaw_data.txt";
    file.open(fileName, std::ios::in);
    if (!file.is_open())
    {
        cout << "Error opening: " << fileName << endl;
        return -1;
    }
    char *tmp = new char[255];
    while(!file.eof())
    {
        file.getline(tmp, 254);
        if (strlen(tmp) == 0)
        {
            continue;
        }
        else if (tmp[strlen(tmp)-1] == '\r')
        {
            tmp[strlen(tmp)-1] = '\0';
        }

        std::string line(tmp);
        std::string::size_type pos;
        pos = line.find(',');
        if (pos == std::string::npos)
        {
            cout << "Data error" << tmp << endl;
            return -1;
        }
        PictureElement *element = new PictureElement();
        element->row = atoi(line.substr(0, pos).c_str());
        element->colume = atoi(line.substr(pos+1).c_str());
        element->malloc();
        int i = 0;
        while(i < element->row && !file.eof())
        {
            file.getline(tmp, 254);
            if (strlen(tmp) == 0)
            {
                continue;
            }
            else if (tmp[strlen(tmp)-1] == '\r')
            {
                tmp[strlen(tmp)-1] = '\0';
            }
            line = tmp;
            for (int j = 0; j < element->colume; j++)
            {
                element->values[i][j] = atoi(line.c_str());
                pos = line.find(',');
                if (pos != string::npos)
                    line = line.substr(pos+1);
            }
            i++;
        }
        for (int j = 0; element->colume; j++)
        {
            if (element->values[0][j] != -1)
            {
                break;
            }
            else
            {
                element->columeOffset++;
            }
        }
        for (int i = 0; element->row; i++)
        {
            if (element->values[i][0] != -1)
            {
                break;
            }
            else
            {
                element->rowOffset++;
            }
        }
        addElement(element);
    }
    delete tmp;
    return 0;
}

void PictureElementSet::dump()
{
    vector<PictureElement*>::iterator it;
    for (it = m_vElements.begin(); it != m_vElements.end(); it++)
    {
        (*it)->dump();
    }
}

void PictureElementSet::addElement(PictureElement * element)
{
    m_vElements.push_back(element);
    m_leftCount++;
}

PictureElement* PictureElementSet::getUnusedElement(int& index)
{
    while(index < m_vElements.size() && m_vElements[index]->isUsed)
    {
        index++;
    }
    if (index >= m_vElements.size())
    {
        return NULL;
    }
    m_leftCount--;
    m_vElements[index]->isUsed = true;
    return m_vElements[index];
}

PictureElement* PictureElementSet::getElement(int index)
{
    return m_vElements[index];
}

PictureElement* PictureElementSet::operator[](int index)
{
    return m_vElements[index];
}

void PictureElementSet::returnElement(int index)
{
    m_leftCount++;
    m_vElements[index]->isUsed = false;
}
