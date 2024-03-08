#include "../include/MixerBase.hpp"

MixerBase::MixerBase() : _plugged(false), _mixfunc(nullptr)
{
}

int MixerBase::mix(FruitBox& fruits) const {
    if (_plugged && _mixfunc)
        return _mixfunc(fruits);
    else
        return 0;
}