//
// Created by Kareem Elnaghy on 05/07/2025.
//

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product {
    string name;
    double price;
    bool expirable;
    bool requireShipping;
    double weight;
    int expYear;
    int expMonth;

public:
    Product(string name, double price, bool expirable, bool requireShipping, double weight, int expYear, int expMonth);

    string getName() const;
    double getPrice() const;
    double getWeight() const;
    bool isExpirable() const;
    bool requiresShipping() const;
    bool isExpired() const;
};



#endif //PRODUCT_H
