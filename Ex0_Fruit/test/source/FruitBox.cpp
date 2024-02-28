#include "FruitBox.hpp"

FruitBox::FruitBox(int size)    :   _sizeBox(size),
                                    _nbFruits(0)
{}

FruitBox::~FruitBox(void)
{}

int             FruitBox::getSizeBox(void) const
{
    return _sizeBox;
}

int             FruitBox::nbFruits(void) const
{
    return _nbFruits;
}