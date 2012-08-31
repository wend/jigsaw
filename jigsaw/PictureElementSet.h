#ifndef PICTURE_ELEMENT_SET_H_
#define PICTURE_ELEMENT_SET_H_
class PictureElement;

class PictureElementSet
{
public:
    PictureElementSet();
    ~PictureElementSet();
    int initialize(const char* fileName);
    void addElement(PictureElement *);
    PictureElement* getUnusedElement(int&);
    PictureElement* getElement(int);
    void returnElement(int);
    PictureElement* operator[](int);
    //void removeElement(PictureElement *);
    int getLeftCount()
    {
        return m_leftCount;
    };
    int getElementCount()
    {
        return m_vElements.size();
    }
    void dump();

private:
    int m_leftCount;
    std::vector<PictureElement*> m_vElements;
};
#endif // PICTURE_ELEMENT_SET_H_

