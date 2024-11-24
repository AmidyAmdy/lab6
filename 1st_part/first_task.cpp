#include <iostream>
#include <conio.h>
#include <string>
#include "list.h"
#include "node.h"
#include "order.h"

using namespace std;

void first_task()
{
    List order_list;
    Order order;
    string line1;
    string line2;
    double dbl;
    int num;

    cout << "1 - Create an order" << endl;
    cout << "2 - Edit an order" << endl;
    cout << "3 - Delete an order" << endl;
    cout << "4 - Print orders" << endl;
    cout << "5 - Print a sum" << endl;
    cout << "0 - Quit first task" << endl;

    while (1)
    {
        switch (_getch())
        {
        case '1':
            cin >> order;
            order_list.addOrder(order);
            break;

        case '2':
            cout << "Enter the number of the order which you want to edit: ";
            cin >> num;
            order_list.editOrder(num);
            break;

        case '3':
            cout << "Enter the number of the order which you want to delete: ";
            cin >> num;
            order_list.deleteOrder(num);
            break;

        case '4':
            order_list.printOrders();
            break;

        case '5':
            cout << "Enter the payer's current account: ";
            cin >> line1;
            order_list.findSumByRasSchPlatl(line1);
            break;

        case '0':
            return;
            break;

        default:
            cout << "\nYou pressed a wrong button. Try again" << endl;
            break;
        }
    }
}
