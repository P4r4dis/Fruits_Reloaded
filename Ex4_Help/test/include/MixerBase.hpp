#ifndef             __MIXERBASE_HPP__
    #define         __MIXERBASE_HPP__

#include "FruitBox.hpp"

class MixerBase
{
    public:
        MixerBase();

        int         mix(FruitBox& fruits) const;
    protected:
        bool        _plugged;
        int         (*_mixfunc) (FruitBox& fruits);
};

#endif //           !__MIXERBASE_HPP__