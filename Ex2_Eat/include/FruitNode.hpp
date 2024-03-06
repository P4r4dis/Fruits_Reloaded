#ifndef         __FRUITNODE_HPP__
    #define     __FRUITNODE_HPP__

    #include "Fruit.hpp"
    struct              FruitNode
    {
        FruitNode       *next;
        Fruit           *fruit;    // data
    };
#endif //       !__FRUITNODE_HPP__
    