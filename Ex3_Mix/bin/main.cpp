#include "../include/FruitBox.hpp"
#include "../include/Lemon.hpp"
#include "../include/Banana.hpp"
#include "../include/Lime.hpp"
#include "../include/LittleHand.hpp"
#include "../include/Coconut.hpp"
#include "../include/Mixer.hpp"

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
   Coconut test;
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



   const int numCoconuts = 25; // Adjust the number of coconuts as needed
   // Dynamically create an array of Coconut pointers
   Coconut** coconuts = new Coconut*[numCoconuts + 1]; // +1 for the nullptr

   for (int i = 0; i < numCoconuts; ++i) {
      coconuts[i] = new Coconut();
   }

   // Terminate the array with nullptr
   coconuts[numCoconuts] = nullptr;

   // Coconut* coconuts[25] = new Coconut*[25];
   FruitBox* const* fruitBoxes = LittleHand::organizeCoconut(coconuts);

   // Add further processing or printing logic as needed
   // Don't forget to free the allocated memory to avoid memory leaks
   for (int i = 0; fruitBoxes[i] != nullptr; ++i) {
      fruitBoxes[i]->displayList(fruitBoxes[i]->head());
      delete fruitBoxes[i];
   }
   delete[] fruitBoxes;



   Mixer mixer;

   Lemon l11;
   Lemon l22;
   Lemon l33;
   Lemon l44;
   Lemon l55;
   Lemon l66;

   FruitBox lemonFruitBox(6);

   lemonFruitBox.putFruit(&l11);
   lemonFruitBox.putFruit(&l22);
   lemonFruitBox.putFruit(&l33);
   lemonFruitBox.putFruit(&l44);
   lemonFruitBox.putFruit(&l55);
   lemonFruitBox.putFruit(&l66);

   mixer.getConnect();
   little.plugMixer(mixer);
   std::cout << "Vitamins numbers after mix: " << mixer.mix(lemonFruitBox) << std::endl;
   little.unplugMixer(mixer);
   mixer.mix(lemonFruitBox); 
   return 0;
}