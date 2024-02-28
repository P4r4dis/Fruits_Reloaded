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