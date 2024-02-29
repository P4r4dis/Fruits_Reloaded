#ifndef                 __FRUITBOX_HPP__
    #define             __FRUITBOX_HPP__

    #include "Fruit.hpp"

    struct              FruitNode
    {
        FruitNode       *next;
        Fruit           *fruit;    // data
    };
    
    class               FruitBox
    {
        public:
            FruitBox(int size);
            ~FruitBox(void);

            int         getSizeBox(void) const;
            int         nbFruits(void) const;
            FruitNode   *head(void) const;
            void        displayList(FruitNode *node);

            bool        putFruit(Fruit *f);
        private:
            int         _sizeBox;
            int         _nbFruits;
            FruitNode   *_headFruitNode;
    };

#endif //           !__FRUITBOX_HPP__