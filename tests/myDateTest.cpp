//  Name Emile LEPETIT
//  Class (CECS 282-01)
//  Project Name (Prog 2 – myDate)
//  Due Date (09/27/2021)
//  I certify that this program is my own original work. I did not copy any part of this program from
//  any other source. I further certify that I typed each and every line of code in this program.


#include <string.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include "../myDate.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(myDate, constructor_default) {
    myDate tmp;

    cr_assert(tmp.getDay() == 11);
    cr_assert(tmp.getMonth() == 5);
    cr_assert(tmp.getYear() == 1959);
}

Test(myDate, constructor_set) {
    auto tmp = new myDate(9, 28, 2000);

    cr_assert(tmp->getDay() == 28);
    cr_assert(tmp->getMonth() == 9);
    cr_assert(tmp->getYear() == 2000);
}


/*Test(myDate, display, .init=redirect_all_stdout) {
    auto tmp = new myDate(3, 3, 2000);

    tmp->display();

    cr_assert_stdout_eq_str("March 3, 2000");
}*/

Test(myDate, increaseDate) {
    auto tmp = new myDate(9, 28, 2000);

    tmp->increaseDate(1);
    cr_assert(tmp->getDay() == 29);
    cr_assert(tmp->getMonth() == 9);
    cr_assert(tmp->getYear() == 2000);
}

Test(myDate, decreaseDate) {
    auto tmp = new myDate(9, 28, 2000);

    tmp->decreaseDate(1);
    cr_assert(tmp->getDay() == 27);
    cr_assert(tmp->getMonth() == 9);
    cr_assert(tmp->getYear() == 2000);
}

Test(myDate, daysBetween_neg) {
    auto tmp = new myDate(9, 28, 2000);
    auto tmp2 = new myDate(9, 10, 2000);

    cr_assert(tmp->daysBetween(*tmp2) == -18);
}

Test(myDate, daysBetween_pos) {
    auto tmp = new myDate(9, 28, 2000);
    auto tmp2 = new myDate(9, 30, 2000);

    cr_assert(tmp->daysBetween(*tmp2) == 2);
}

Test(myDate, dayOfYear) {
    auto tmp = new myDate(1, 28, 2021);

    cr_assert(tmp->dayOfYear() == 28);
}

Test(myDate, dayName) {
    auto tmp = new myDate(3, 3, 2000);

    cr_assert(tmp->dayName() == "Friday");
}

Test(myDate, invalid_month) {
    auto tmp = new myDate(23, 3, 2000);

    cr_assert(tmp->getDay() == 11);
    cr_assert(tmp->getMonth() == 5);
    cr_assert(tmp->getYear() == 1959);
}

Test(myDate, invalid_day) {
    auto tmp = new myDate(9, 31, 2021);

    cr_assert(tmp->getDay() == 11);
    cr_assert(tmp->getMonth() == 5);
    cr_assert(tmp->getYear() == 1959);
}
