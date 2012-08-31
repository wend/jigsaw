#ifndef PICTURE_PUZZLE_H_
#define PICTURE_PUZZLE_H_


#define PUZZLE_ROW 8 // the puzzle total row
#define PUZZLE_COLUME 8 // the puzzle total colume

class PictureElement;
class PictureElementSet;
class PicturePuzzle
{
public:
    PicturePuzzle(void);
    ~PicturePuzzle(void);
    int jigsaw(PictureElement *);
    void unJigsaw(PictureElement *);
    //void reJigsaw();
    //int verify(PictureElement *);
    void updateIndex();
    void push(int elementIndex);
    int pop();
    void dump();
    int getJigsawCount()
    {
        return m_vElements.size();
    }

private:
    vector<int> m_vElements;
    char **m_puzzle;
    int m_rowIndex;
    int m_columeIndex;
};

#endif //PICTURE_PUZZLE_H_
