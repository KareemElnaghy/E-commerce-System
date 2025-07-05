//
// Created by Kareem Elnaghy on 05/07/2025.
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Product.h"
#include <unordered_map>
#include <vector>
using namespace std;

class Customer {
    unordered_map<string, int> cartItems; // Product and its quantity
    double balance;

public:
    Customer();
    void add(string productName, int quantity);
    void checkout(vector<Product> products, double* subtotal, vector<pair<Product, int>>* shippedProducts) const;
    const unordered_map<string, int>& getCart() const;
    bool updateBalance(int amount);
    double getBalance() const;
};

#endif //CUSTOMER_H