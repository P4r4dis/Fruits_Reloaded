#include "FruitBox.hpp"

FruitBox::FruitBox(int size)    :   _sizeBox(size)
{}

FruitBox::~FruitBox(void)
{}

int             FruitBox::getSizeBox(void) const
{
    return _sizeBox;
}