#ifndef             __LITTLEHAND_HPP__
    #define         __LITTLEHAND_HPP__

    #include "FruitBox.hpp"
    #include "Coconut.hpp"

    class LittleHand
    {
        public:
            LittleHand(void);
            ~LittleHand(void);

            static void                 sortFruitbox(FruitBox& unsorted, FruitBox& lemons,
                                                    FruitBox& bananas, FruitBox& limes);
            static FruitBox * const *   organizeCoconut(Coconut const * const * coconuts);
    };

#endif //           !__LITTLEHAND_HPP__S