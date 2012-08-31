// jigsaw.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PictureElement.h"
#include "PictureElementSet.h"
#include "PicturePuzzle.h"

int main(int argc, char* argv[])
{
    PictureElementSet *elementSet = new PictureElementSet();
    int ret = 0;
    cout << "argc: "<<argc<<endl;
    char *fileName = NULL;
    if (argc <= 1)
    {
        fileName = "d:\\test\\jigsaw_data.txt";
    }
    else
    {
        fileName = argv[1];
    }
    ret = elementSet->initialize(fileName);
    if (ret != 0)
    {    
        cout << "open file "<<fileName<<" error"<<endl;
        return -1;
    }
    PicturePuzzle* puzzle = new PicturePuzzle();
    //elementSet->dump();
    int loopCount = 0;
    int elementIndex = 0;
    
    PictureElement *element;
    //while(elementSet->getLeftCount() > 0)
    while(1)
    {
        loopCount++;
        //cout << "Loop count: " <<loopCount <<endl;
        element = elementSet->getUnusedElement(elementIndex);
        if (element == NULL)
        {
            elementIndex = puzzle->pop();
            if (elementIndex < 0)
            {
                cout << "jigsaw finished" <<endl;
                cout << "Loop count: " <<loopCount <<endl;
                //puzzle->dump();
                break;
            }
            elementSet->returnElement(elementIndex);
            //element = elementSet->getElement(elementIndex);
            element = (*elementSet)[elementIndex];
            puzzle->unJigsaw(element);
            elementIndex++;
            continue;
        }
        ret = puzzle->jigsaw(element);
        if (ret != 0)
        {
            elementSet->returnElement(elementIndex);
            elementIndex++;
            continue;
        }
        puzzle->push(elementIndex);
        if (puzzle->getJigsawCount() == 21)
        {
            cout << "Loop count: " <<loopCount <<endl;
            puzzle->dump();
        }
        puzzle->updateIndex();
        elementIndex = 0;
    }

    delete elementSet;
    delete puzzle;
	return 0;
}

