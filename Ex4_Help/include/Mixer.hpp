#ifndef             __MIXER_HPP__
    #define         __MIXER_HPP__

#include "MixerBase.hpp"

class Mixer :   public MixerBase
{
    public:
        Mixer(void);
        ~Mixer(void);

        static int mixF(FruitBox& fruitBox);
        bool        getConnect(void) const;
        void        Connect(void);
        void        disconnect(void);
};

#endif //           !__MIXER_HPP__