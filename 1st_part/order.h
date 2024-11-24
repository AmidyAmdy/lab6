#ifndef ORDER_H_
#define ORDER_H_
#include <string>
#include <iostream>

using namespace std;

class Order
{
private:
    string ras_sch_plat;
    string ras_sch_pol;
    double sum;

public:
    explicit Order(const string &ras_sch_plat, const string &ras_sch_pol, double sum)
        : ras_sch_plat(ras_sch_plat), ras_sch_pol(ras_sch_pol), sum(sum) 
    {
        std::cout << "Order constructor called with parameters: "
                  << "payer's account = " << ras_sch_plat << ", "
                  << "beneficiary's account = " << ras_sch_pol << ", "
                  << "amount = " << sum << std::endl;
    }

    Order(const Order &other) : ras_sch_plat(other.ras_sch_plat), ras_sch_pol(other.ras_sch_pol), sum(other.sum)
    {
        std::cout << "Order copy constructor called for Order: " << other << std::endl;
    }

    Order() : ras_sch_plat("Unknown"), ras_sch_pol("Unknown"), sum(0)
    {
        std::cout << "Order default constructor called" << std::endl;
    }

    ~Order() 
    {
        std::cout << "Order destructor called for Order: " << *this << std::endl;
    }

    string getRas_sch_plat() const { return ras_sch_plat; }
    void setRas_sch_plat(string newRas_sch_plat) { ras_sch_plat = newRas_sch_plat; }
    string getRas_sch_pol() const { return ras_sch_pol; }
    void setRas_sch_pol(string newRas_sch_pol) { ras_sch_pol = newRas_sch_pol; }
    double getSum() const { return sum; }
    void setSum(int newSum) { sum = newSum; }

    friend std::ostream &operator<<(std::ostream &out, const Order &order);

    friend std::istream &operator>>(std::istream &in, Order &order);
};

#endif