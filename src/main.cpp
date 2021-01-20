// Copyright 2021 Ilya Tatsenko
#include<iostream>
#include <string>

#include "postfix.h"

int main() {
    std::string inf = "2 + 2";
    std::cout << infix2postfix(inf) << std::endl;
    //  std::string expected = "2 2 +";

    std::string inf1 = "2 + 6 * 3 / (4 - 2)";
    std:: cout << infix2postfix(inf1) << std::endl;
    //  std::string expected = "2 6 3 * 4 2 - / +";

    std::string inf3 = "(2 + 8.3) * (6 - 3.2)";
    std::cout << infix2postfix(inf3) << std:: endl;
    //  std::string expected = "2 8.3 + 6 3.2 - *";

    std::string inf33 = "(6 * (4 - 2) + 5) * (2.6 + 3 * 7) - 9";
    std::cout<< infix2postfix(inf33);
    //  std::string expected = "6 4 2 - * 5 + 2.6 3 7 * + * 9 -";
}
