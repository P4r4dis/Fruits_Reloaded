#ifndef             __LITTLEHAND_HPP__
    #define         __LITTLEHAND_HPP__

    #include "FruitBox.hpp"

    class LittleHand
    {
        public:
            LittleHand(void);
            ~LittleHand(void);

            static void         sortFruitbox(FruitBox& unsorted, FruitBox& lemons,
                                            FruitBox& bananas, FruitBox& limes);
    };

#endif //           !__LITTLEHAND_HPP__S