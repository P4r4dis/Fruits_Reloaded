#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../include/Lemon.hpp"

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