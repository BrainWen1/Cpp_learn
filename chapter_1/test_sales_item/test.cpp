#include <iostream>
#include "Sales_item.h"

int main(void) {

    // 1.5.1
    // 1.20
    Sales_item book;
    for(int i = 0; i < 3; ++i) {
        std::cin >> book;

        std::cout << book << std::endl;
    }
    std::cout << std::endl;

    // 1.21
    Sales_item item1, item2;
    std::cin >> item1 >> item2;

    std::cout << item1 + item2 << std::endl << std::endl;

    // 1.22
    Sales_item items, item;
    std::cin >> items;
    for(int i = 0; i < 2; ++i) {
        std::cin >> item;

        items += item;
    }
    std::cout << items << std::endl << std::endl;

    // 1.5.2
    // 1.23
    int cnt = 1;
    std::cin >> items;
    while(std::cin >> item) {

        if(items.isbn == item.isbn) {
            items += item;
            cnt++;
        } else {
            std::cout << items.isbn << " occurs " << cnt << " times" << std::endl;
            std::cout << items << std::endl;

            cnt = 1;
            items = item;
        }
    }
    std::cout << items.isbn << " occurs " << cnt << " times" << std::endl;
    std::cout << items << std::endl << std::endl;

    return 0;
}