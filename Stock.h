//
// Created by Kareem Elnaghy on 05/07/2025.
//

#ifndef STOCK_H
#define STOCK_H

#include "Product.h"
#include <unordered_map>
#include <vector>
using namespace std;

class Stock {
    unordered_map<string, int> stockItems; // Product and its stock amount

public:
    Stock(const vector<Product> &products);
    void addProduct(const Product product, int stockQty);
    void updateStock(string &productName, int qty);
    void reduceStock(string prodName, int quantity);
};



#endif //STOCK_H
