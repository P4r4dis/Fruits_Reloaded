#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../include/Lemon.hpp"
#include "../include/Banana.hpp"
#include "../include/FruitBox.hpp"


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