#ifndef LIST_H_
#define LIST_H_
#include <string>
#include <iostream>
#include "node.h"
#include "order.h"

class List
{
private:
    Node *head;

public:
    List() : head(nullptr) {}
    void addOrder(const Order &order);
    Order *findOrderByRasSchPlatl(const std::string &ras_sch_plat);
    void printOrders() const;

    ~List()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

#endif