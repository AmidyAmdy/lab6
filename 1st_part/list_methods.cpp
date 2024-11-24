#include "list.h"
#include "node.h"
#include <iostream>

void List::addOrder(const Order &order) {
    Node* newNode = new Node(order);
    
    if (!head || head->getOrder().getRas_sch_plat() > order.getRas_sch_plat()) {
        newNode->setNext(head);
        head = newNode;
    } else {
        Node* current = head;
        while (current->getNext() && current->getNext()->getOrder().getRas_sch_plat() < order.getRas_sch_plat()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }
}

void List::findSumByRasSchPlatl(const std::string &ras_sch_plat) {
    Node* current = head;
    while (current) {
        if (current->getOrder().getRas_sch_plat() == ras_sch_plat) {
            std::cout << current->getOrder().getSum() << std::endl;
            return;
        }
        current = current->getNext();
    }
    std::cout << "Found nothing! There is no such rascetniy schet((" << std::endl;
}

void List::printOrders() const {
    Node* current = head;
    int i = 1;
    while (current) {
        std::cout << i << " " << current->getOrder() << std::endl;
        current = current->getNext();
        i++;
    }
}

void List::deleteOrder(int num) {
    if (!head) {
        std::cout << "Nothing to delete" << std::endl;
        return;
    }

    int i = 1;
    Node* current = head;
    Node* previous = nullptr;

    if (num == 1) {
        head = current->getNext();  
        delete current; 
        std::cout << "Order " << num << " deleted" << std::endl;
        return;
    }

    while (current) {
        if (num == i) {
            if (previous) {
                previous->setNext(current->getNext()); 
            }
            delete current;  
            std::cout << "Order " << num << " deleted" << std::endl;
            return;
        }
        i++;
        previous = current;
        current = current->getNext();
    }

    std::cout << "Order " << num << " not found" << std::endl;
}


void List::editOrder(int num) {
    Node* current = head;
    string line;
    double dbl;
    int choice;
    int i = 1;
    while(current) {
        if (i == num) {
            while(1){
                std::cout << "Choose what to edit:\n1 - payer's current account\n2 - beneficiary's current account\n3 - amount" << endl;
                std::cin >> choice;
                if (choice == 1) {
                    std::cout << "Enter new payer's current account: ";
                    cin >> line;
                    current->getOrder().setRas_sch_plat(line);
                    break;
                }
                else if (choice == 2) {
                    std::cout << "Enter new beneficiary's current account: ";
                    cin >> line;
                    current->getOrder().setRas_sch_pol(line);
                    break;
                }
                else if (choice == 3) {
                    std::cout << "Enter new amount: ";
                    cin >> dbl;
                    current->getOrder().setSum(dbl);
                    break;
                }
                else {
                    std::cout << "There is no option " << choice << ". Try again" << endl; 
                }
            }
            break;
        }
        
        i++;
        current = current->getNext();
    }
}