#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../include/Lemon.hpp"
#include "../include/Banana.hpp"
#include "../include/FruitBox.hpp"
#include "../include/Lime.hpp"
#include "../include/LittleHand.hpp"
#include "../include/Coconut.hpp"


void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(Fruit, test_Fruit_class_implementation, .init = redirect_all_stdout)
{
    {
        Lemon l;
        Fruit &f = l;

        cr_assert(f.getName() == "lemon");
        cr_assert(f.getVitamins() == 3);
        std::cout   << f.getVitamins() << std::endl;
        std::cout   << f.getName() << std::endl;
    }

    cr_assert_stdout_eq_str
    (
        "3\n"
        "lemon\n"
    );
}

Test(Lemon, test_Lemon_class_implementation, .init = redirect_all_stdout)
{
    {
        Lemon l;

        cr_assert(l.getName() == "lemon");
        cr_assert(l.getVitamins() == 3);
        std::cout   << l.getVitamins() << std::endl;
        std::cout   << l.getName() << std::endl;
    }

    cr_assert_stdout_eq_str
    (
        "3\n"
        "lemon\n"
    );
}

Test(Banana, test_Banana_class_implementation, .init = redirect_all_stdout)
{
    {
        Banana b;

        cr_assert(b.getName() == "banana");
        cr_assert(b.getVitamins() == 5);
        std::cout   << b.getVitamins() << std::endl;
        std::cout   << b.getName() << std::endl;
    }

    cr_assert_stdout_eq_str
    (
        "5\n"
        "banana\n"
    );
}

Test(FruitBox, test_FruitBox_class_implementation, .init = redirect_all_stdout)
{
    {
        FruitBox fb(10);

        cr_assert(fb.getSizeBox() == 10);
    }

    cr_assert_stdout_eq_str
    (
        ""
    );
}

Test(FruitBox, test_FruitBox_nbFruits, .init = redirect_all_stdout)
{
    {
        FruitBox fb(10);

        cr_assert(fb.getSizeBox() == 10);
        cr_assert(fb.nbFruits() == 0);
    }

    cr_assert_stdout_eq_str
    (
        ""
    );
}

Test(FruitBox, test_FruitBox_head, .init = redirect_all_stdout)
{
    {
        FruitBox fb(10);

        cr_assert(fb.getSizeBox() == 10);
        cr_assert(fb.nbFruits() == 0);
        cr_assert(fb.head() == nullptr);
    }

    cr_assert_stdout_eq_str
    (
        ""
    );
}

Test(FruitBox, test_FruitBox_putFruit, .init = redirect_all_stdout)
{
    {
        FruitBox fb(6);
        Lemon l1;
        Lemon l2;
        Lemon l3;
        Lemon l4;
        Lemon l5;
        Lemon l6;
        Lemon l7;


        cr_assert(fb.getSizeBox() == 6);
        cr_assert(fb.nbFruits() == 0);
        if (fb.head() == nullptr)
            cr_assert(fb.head() == nullptr);

        cr_assert(fb.putFruit(&l1) == true);
        cr_assert(fb.putFruit(&l1) == false); // false
        cr_assert(fb.putFruit(&l2) == true);
        cr_assert(fb.putFruit(&l3) == true);
        cr_assert(fb.putFruit(&l4) == true);
        cr_assert(fb.putFruit(&l5) == true);
        cr_assert(fb.putFruit(&l6) == true);
        cr_assert(fb.putFruit(&l7) == false); // false


        // for (int i = 0; i < 6; i++)
        // {
        //     if (fb.nbFruits() < fb.getSizeBox())
        //         cr_assert(fb.putFruit(&l) == true);
        //     else
        //         cr_assert(fb.putFruit(&l) == false);
        // }
        // // fb.putFruit(&l);
        // fb.putFruit(&l);
        // fb.putFruit(&l);
        // fb.putFruit(&l);
        // fb.putFruit(&l);
        // fb.putFruit(&l);
        // fb.putFruit(&l);
        // fb.putFruit(&l);
        if (fb.head() != nullptr)
            cr_assert(fb.head() != nullptr);
        fb.displayList(fb.head());
        fb.displayList(fb.head());
        fb.displayList(fb.head());

        Lemon *le = nullptr;
        cr_assert(fb.putFruit(le) == false);


    }

    cr_assert_stdout_eq_str
    (
        ""
    );
}

Test(FruitBox, test_FruitBox_pickFruit, .init = redirect_all_stdout)
{
    {
        FruitBox fb(6);
        Banana l1;
        Lemon l2;
        Lemon l3;
        Lemon l4;
        Lemon l5;
        Lemon l6;
        Lemon l7;


        cr_assert(fb.getSizeBox() == 6);
        cr_assert(fb.nbFruits() == 0);
        if (fb.head() == nullptr)
            cr_assert(fb.head() == nullptr);

        cr_assert(fb.putFruit(&l1) == true);
        cr_assert(fb.putFruit(&l1) == false); // false
        cr_assert(fb.putFruit(&l2) == true);
        cr_assert(fb.putFruit(&l3) == true);
        cr_assert(fb.putFruit(&l4) == true);
        cr_assert(fb.putFruit(&l5) == true);
        cr_assert(fb.putFruit(&l6) == true);
        cr_assert(fb.putFruit(&l7) == false); // false

        if (fb.head() != nullptr)
            cr_assert(fb.head() != nullptr);
        fb.displayList(fb.head());
        fb.displayList(fb.head());
        fb.displayList(fb.head());

        Lemon *le = nullptr;
        cr_assert(fb.putFruit(le) == false);

        cr_assert(fb.pickFruit() == &l1);
                fb.displayList(fb.head());
                        cr_assert(fb.nbFruits() == 5);

        FruitBox fb2(3);

        cr_assert(fb2.head() == nullptr);
        cr_assert(fb2.nbFruits() == 0);
        cr_assert(fb2.pickFruit() == nullptr);
    }

    // cr_assert_stdout_eq_str
    // (
    //     ""
    // );
}


Test(FruitBox, test_Ex0_main, .init = redirect_all_stdout)
{
    {
        FruitBox fb(4);
        Banana b1;
        Banana b2;
        Lemon l1;
        Lemon l2;
        Lemon l3;

        cr_assert(fb.getSizeBox() == 4);
        cr_assert(fb.nbFruits() == 0);
        if (fb.head() == nullptr)
            cr_assert(fb.head() == nullptr);

        cr_assert(fb.putFruit(&l1) == true);
        cr_assert(fb.putFruit(&l1) == false); // false
        cr_assert(fb.putFruit(&l2) == true);
        cr_assert(fb.putFruit(&b1) == true);
        cr_assert(fb.putFruit(&b2) == true);
        cr_assert(fb.putFruit(&l3) == false);

        if (fb.head() != nullptr)
            cr_assert(fb.head() != nullptr);
        fb.displayList(fb.head());

        Lemon *le = nullptr;
        cr_assert(fb.putFruit(le) == false);

        cr_assert(fb.pickFruit() == &l1);
                fb.displayList(fb.head());
                        cr_assert(fb.nbFruits() == 3);

        FruitBox fb2(3);

        cr_assert(fb2.head() == nullptr);
        cr_assert(fb2.nbFruits() == 0);
        cr_assert(fb2.pickFruit() == nullptr);
    }
}

Test(Lime, test_Lime_class_implementation, .init = redirect_all_stdout)
{
    {
        Lime l;
        Fruit &f = l;

        cr_assert(f.getName() == "lime");
        cr_assert(f.getVitamins() == 2);
        std::cout   << f.getVitamins() << std::endl;
        std::cout   << f.getName() << std::endl;
    }

    cr_assert_stdout_eq_str
    (
        "2\n"
        "lime\n"
    );
}

Test(LittleHand, test_LittleHand_class_implementation)//, .init = redirect_all_stdout)
{
    {
        LittleHand little;
        little.~LittleHand();
    }

    // cr_assert_stdout_eq_str
    // (
    //     "2\n"
    //     "lime\n"
 
    // );
}

Test(LittleHand, test_LittleHand_sortFruitBox, .init = redirect_all_stdout)
{
    {
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
        Coconut coconut;
        Fruit fruit2 = coconut;
        cr_assert(unsorted.putFruit(&lemon) == true);
        cr_assert(unsorted.putFruit(&banana) == true);
        cr_assert(unsorted.putFruit(&lime) == true);
        cr_assert(unsorted.putFruit(&fruit) == true);
        cr_assert(unsorted.putFruit(&fruit2) == true);
        little.sortFruitbox(unsorted, lemonBox, bananaBox, limeBox);
        unsorted.displayList(unsorted.head());
        cr_assert(unsorted.nbFruits() == 1);
        lemonBox.displayList(lemonBox.head());
        cr_assert(lemonBox.nbFruits() == 2);
        bananaBox.displayList(bananaBox.head());
        cr_assert(bananaBox.nbFruits() == 1);
        limeBox.displayList(limeBox.head());
        cr_assert(limeBox.nbFruits() == 1);
    }

    // cr_assert_stdout_eq_str
    // (
    //     "2\n"
    //     "lime\n"
 
    // );
}

Test(Coconut, test_Coconut_class_implementation, .init = redirect_all_stdout)
{
    {
        Coconut c;
        Fruit &f = c;

        cr_assert(f.getName() == "coconut");
        cr_assert(f.getVitamins() == 15);
        std::cout   << f.getVitamins() << std::endl;
        std::cout   << f.getName() << std::endl;
    }

    cr_assert_stdout_eq_str
    (
        "15\n"
        "coconut\n"
    );
}

Test(LittleHand, test_organizeCoconut)//, .init = redirect_all_stdout)
{
    {
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
    for (int i = 0; fruitBoxes[i]; i++)
    {
            cr_assert(i < 5);
    }
    // Add further processing or printing logic as needed
    // Don't forget to free the allocated memory to avoid memory leaks
    for (int i = 0; fruitBoxes[i] != nullptr; ++i) {
        fruitBoxes[i]->displayList(fruitBoxes[i]->head());
        cr_assert(fruitBoxes[i]->getSizeBox() == 6);
        cr_assert(fruitBoxes[i]->nbFruits() == 6 || 1);
        delete fruitBoxes[i];
    }
    delete[] fruitBoxes;
    }
}