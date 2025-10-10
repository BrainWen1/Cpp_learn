// 定义抽象数据类型
#include <iostream>
#include "chapter_7/Sales_data.h"

using std::cin;
using std::cout;
using std::endl;

int main(void) {

    // 7.1.1
    // 7.1
    /*typedef struct My_Sales_data {
        std::string bookID;
        double price{0.0};
        unsigned units_sold{0};
        double revenue{0.0};
        std::string bookSort;
    }My_Sales_data;
    
    My_Sales_data total;
    if(cin >> total.bookID && cin >> total.units_sold && cin >> total.price) {
        total.revenue = total.units_sold * total.price;
        My_Sales_data trans;

        while(cin >> total.bookID && cin >> total.units_sold && cin >> total.price) {
            if(total.bookID == trans.bookID) {
                total.revenue = (total.units_sold * total.price) + (trans.units_sold * trans.price);
                total.price = total.revenue / (total.units_sold + trans.units_sold);
                total.units_sold += trans.units_sold;
            } else {
                cout << total.bookID << " " << total.units_sold << " " << total.price << endl;
                total.bookID = trans.bookID;
                total.units_sold = trans.units_sold;
                total.price = trans.price;
                total.revenue = trans.revenue;
            }
        }
        cout << total.bookID << " " << total.units_sold << " " << total.price << endl;
    } else {
        std::cerr << "No data?" << endl;
        return -1;
    }*/

    // 定义改进的Sales_data类
    // 7.1.2
    // 7.2
    Sales_data total;
    if(read(cin, total)) {
        Sales_data trans;

        while(read(cin, trans)) {
            if(trans.isbn() == total.isbn()) {
                total.combine(trans);
            } else {
                print(cout, total) << endl;
                total = trans;
            }
        }
        print(cout, total);
    } else {
        std::cerr << "No data?!" << endl;
    }

    // 构造函数
    // 7.1.4
    // 7.11

    return 0;
}