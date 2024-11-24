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
    void findSumByRasSchPlatl(const std::string &ras_sch_plat);
    void printOrders() const;
    Node* getHead() const { return head; }
    void deleteOrder(int num);
    void editOrder(int num);

    ~List()
    {
        while (head)
        {
            Node *temp = head;
            head = head->getNext();
            delete temp;
        }
    }
};

#endif