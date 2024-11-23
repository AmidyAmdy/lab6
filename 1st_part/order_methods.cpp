using namespace std;
#include <string>
#include <iostream>
#include "order.h"

std::ostream &operator<<(std::ostream &out, const Order &order)
{
    out << "Плательщик: " << order.getRas_sch_plat() << ", "
        << "Получатель: " << order.getRas_sch_pol() << ", "
        << "Сумма: " << order.getSum();
    return out;
}

std::istream &operator>>(std::istream &in, Order &order)
{
    std::cout << "Введите расчетный счет плательщика: ";
    in >> order.ras_sch_plat;
    std::cout << "Введите расчетный счет получателя: ";
    in >> order.ras_sch_pol;
    std::cout << "Введите сумму: ";
    in >> order.sum;
    return in;
}