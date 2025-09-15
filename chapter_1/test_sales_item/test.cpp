#include <iostream>
#include "sales_item.h"

int main(void) {

    // 1.5.1
    // 1.20
    Sales_item book;
    for(int i = 0; i < 3; ++i) {
        std::cin >> book;

        std::cout << book << std::endl;
    }

    // 1.21
    Sales_item item1, item2;
    std::cin >> item1 >> item2;

    std::cout << item1 + item2 << std::endl;

    // 1.22
    Sales_item items, item;
    std::cin >> items;
    for(int i = 0; i < 2; ++i) {
        std::cin >> item;

        items += item;
    }
    std::cout << items << std::endl;

    return 0;
}