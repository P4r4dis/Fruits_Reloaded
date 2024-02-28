#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../include/Fruit.hpp"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

class Orange : public Fruit
{
    public:
        Orange(void) : Fruit()
        {
            setName("Orange");
            setVitamins(10);
        };
        ~Orange(void) {};
};

Test(Fruit, test_Fruit_class_implementation, .init = redirect_all_stdout)
{
    {
        Orange orange;
        Fruit &f = orange;

        cr_assert(f.getName() == "Orange");
        cr_assert(f.getVitamins() == 10);
    }

    cr_assert_stdout_eq_str("");
}