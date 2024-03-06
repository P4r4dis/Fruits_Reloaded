#include "../include/FruitBox.hpp"
#include "../include/Lemon.hpp"
#include "../include/Banana.hpp"
#include "../include/Lime.hpp"
#include "../include/LittleHand.hpp"
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


      LittleHand little;
      FruitBox unsorted(6);
      FruitBox lemonBox(4);
      FruitBox bananaBox(4);
      FruitBox limeBox(4);

      Lemon lemon;
      Lemon lemon2;

      Banana banana;
      Lime lime;
      Fruit &fruit = lemon2;
      Lime2 test;
      Fruit &fruit2 = test;
      unsorted.putFruit(&lemon);
      unsorted.putFruit(&banana);
      unsorted.putFruit(&lime);
      unsorted.putFruit(&fruit);
      unsorted.putFruit(&fruit2);
      little.sortFruitbox(unsorted, lemonBox, bananaBox, limeBox);
      unsorted.displayList(unsorted.head());
      lemonBox.displayList(lemonBox.head());
      bananaBox.displayList(bananaBox.head());
      limeBox.displayList(limeBox.head());

       return 0;
}