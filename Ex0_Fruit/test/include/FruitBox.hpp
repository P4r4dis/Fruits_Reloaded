#ifndef             __FRUITBOX_HPP__
    #define         __FRUITBOX_HPP__

    // #include "Fruit.hpp"

    class           FruitBox
    {
        public:
            FruitBox(int size);
            ~FruitBox(void);

            int     getSizeBox(void) const;
        private:
            int     _sizeBox;
    };

#endif //           !__FRUITBOX_HPP__