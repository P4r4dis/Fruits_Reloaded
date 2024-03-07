#ifndef                 __FRUITBOX_HPP__
    #define             __FRUITBOX_HPP__

    #include "FruitNode.hpp"
    #include "Coconut.hpp"

    
    class               FruitBox
    {
        public:
            FruitBox(int size);
            FruitBox(const FruitBox& rhs) = delete;
            ~FruitBox(void);

            FruitBox    &operator=(const FruitBox &rhs) = delete;

            int         getSizeBox(void) const;
            int         nbFruits(void) const;
            FruitNode   *head(void) const;
            
            bool        putFruit(Fruit* const f);
            Fruit       *pickFruit(void);

            void        displayList(FruitNode *node);

            void        setHead(FruitNode *fruitNode);
            bool        addCoconut(const Coconut* c);
        private:
            int         _sizeBox;
            int         _nbFruits;
            FruitNode   *_headFruitNode;
    };

#endif //           !__FRUITBOX_HPP__