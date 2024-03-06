#include "../include/LittleHand.hpp"

LittleHand::LittleHand(void)
{}

LittleHand::~LittleHand(void)
{}

void            LittleHand::sortFruitbox(FruitBox& unsorted, FruitBox& lemons,
                                            FruitBox& bananas, FruitBox& limes)
{
    FruitNode *current = unsorted.head();
    
    while (current != nullptr)
    {
        Fruit* fruit = current->fruit;    
        bool added = false;

        if (fruit->getName() == "lemon") {
            added = lemons.putFruit(fruit);
            unsorted.pickFruit();
        }
        else if (fruit->getName() == "banana")
        {
            added = bananas.putFruit(fruit);
            unsorted.pickFruit();
        }
        else if (fruit->getName() == "lime"){
            added = limes.putFruit(fruit);
            unsorted.pickFruit();
        }
        if (!added)
            unsorted.putFruit(fruit);
        current = current->next;
    }
    // return;
}