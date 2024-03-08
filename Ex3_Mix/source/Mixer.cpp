#include "../include/Mixer.hpp"

Mixer::Mixer(void) : MixerBase()
{
    _plugged = false;
    _mixfunc = &mixF;
}

Mixer::~Mixer(void)
{}

bool        Mixer::getConnect(void) const
{
    return _plugged;
}

int         Mixer::mixF(FruitBox& fruitBox)
{
    int result = 0;
    FruitNode *temp = fruitBox.head();
    if (temp != nullptr)
    {
        while (temp != nullptr)
        {
            result += fruitBox.head()->fruit->getVitamins();
            fruitBox.pickFruit();
            temp = temp->next;
        }
    }
    delete temp;
    return result;

}

void        Mixer::Connect(void)
{
    _plugged = true;
}

void        Mixer::disconnect(void)
{
    _plugged = false;
}