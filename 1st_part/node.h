#ifndef NODE_H_
#define NODE_H_
#include "order.h"

class Node
{
private:
    Order order;
    Node *next;

    Node(const Order &order) : order(order), next(nullptr) {}
};

#endif