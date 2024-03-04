#include "../include/FruitBox.hpp"
#include "../include/Lemon.hpp"
#include "../include/Banana.hpp"

int main(void)
{
        FruitBox fb(4);
        Banana b1;
        Banana b2;
        Lemon l1;
        Lemon l2;
        Lemon l3;

       fb.getSizeBox();
       fb.nbFruits();
        if (fb.head() == nullptr)
           std::cout << "head node is nullptr" << std::endl;

       fb.putFruit(&l1);
       fb.putFruit(&l1);
       fb.putFruit(&l2);
       fb.putFruit(&b1);
       fb.putFruit(&b2);
       fb.putFruit(&l3);

        if (fb.head() != nullptr)
           std::cout << "head node is different of nullptr" << std::endl;
        fb.displayList(fb.head());

        Lemon *le = nullptr;
       fb.putFruit(le);

       fb.pickFruit();
                fb.displayList(fb.head());
                       fb.nbFruits();

        FruitBox fb2(3);

       fb2.head();
       fb2.nbFruits();
       fb2.pickFruit();

       return 0;
}