#ifndef PICTURE_ELEMENT_H_
#define PICTURE_ELEMENT_H_

class PictureElement
{
public:
    PictureElement();
    ~PictureElement();
    int malloc();
    void dump();
public:
    int row;
    int colume;
    char **values;
    int columeOffset; // the first colume value which is not -1 
    int rowOffset;    // the first row value which is not -1
    bool isUsed;      // if the element is used
    int rowIndex;     // the row index in the puzzle when the element is jigsaw
    int columeIndex;  // the colume index in the puzzle when the element is jigsaw
};
#endif // PICTURE_ELEMENT_H_
