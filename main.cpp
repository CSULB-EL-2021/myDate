#include <iostream>
#include "myDate.h"

int main()
{
    auto tmp = new myDate(10, 31, 2021);
    tmp->display();

    return 0;
}
