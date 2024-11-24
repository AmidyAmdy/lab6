#ifndef NODE_H_
#define NODE_H_
#include "order.h"

class Node
{
private:
    Order order;
    Node *next;
public:
    Node(const Order &order) : order(order), next(nullptr) {
        std::cout << "Node constructor called for Order: " << order << std::endl;
    }
    Order& getOrder() { return order; }
    Node* getNext() const { return next; }
    void setNext(Node* nextNode) { next = nextNode; }
};

#endif