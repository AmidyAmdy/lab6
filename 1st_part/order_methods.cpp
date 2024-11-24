using namespace std;
#include <string>
#include <iostream>
#include "order.h"

std::ostream &operator<<(std::ostream &out, const Order &order)
{
    out << "Payer: " << order.getRas_sch_plat() << ", "
        << "Beneficiary: " << order.getRas_sch_pol() << ", "
        << "Amount: " << order.getSum();
    return out;
}

std::istream &operator>>(std::istream &in, Order &order)
{
    std::cout << "Enter the payer's current account: ";
    in >> order.ras_sch_plat;
    std::cout << "Enter the beneficiary's current account: ";
    in >> order.ras_sch_pol;
    std::cout << "Enter the amount in rubles: ";
    in >> order.sum;
    return in;
}