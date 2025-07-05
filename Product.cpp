//
// Created by Kareem Elnaghy on 05/07/2025.
//

#include "Product.h"
using namespace std;

Product::Product(string name, double price, bool expirable, bool requireShipping, double weight, int expYear, int expMonth)
    : name(name), price(price), expirable(expirable), requireShipping(requireShipping), weight(weight), expYear(expYear), expMonth(expMonth) {}

string Product::getName() const {
    return name;
}
double Product::getPrice() const {
    return price;
}
double Product::getWeight() const {
    return weight;
}
bool Product::isExpirable() const {
    return expirable;
}
bool Product::requiresShipping() const {
    return requireShipping;
}
bool Product::isExpired() const {
    if (!expirable) return false;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900 + ltm->tm_year;
    int currentMonth = 1 + ltm->tm_mon;

    if (currentYear > expYear || (currentYear == expYear && currentMonth > expMonth)) {
        return true;
    }
    return false;
}

