#include "node.h"
#include "order.h"
#include "list.h"
#include <string>
#include <iostream>

void List::addOrder(const Order &order)
{
    Node *newNode = new Node(order);
    if (!head || head->order.getRas_sch_plat() > order.getRas_sch_plat())
    {

        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *current = head;
        while (current->next && current->next->order.getRas_sch_plat() < order.getRas_sch_plat())
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

Order List::*findOrderByRasSchPlatl(const std::string &ras_sch_plat)
{
    Node *current = head;
    while (current)
    {
        if (current->order.getRas_sch_plat() == ras_sch_plat)
        {
            return &current->order;
        }
        current = current->next;
    }
    return nullptr;
}

void List::printOrders() const
{
    Node *current = head;
    while (current)
    {
        std::cout << current->order << std::endl;
        current = current->next;
    }
}