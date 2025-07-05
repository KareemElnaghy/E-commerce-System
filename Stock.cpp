//
// Created by Kareem Elnaghy on 05/07/2025.
//

#include "Stock.h"

Stock::Stock(const vector<Product> &products) {
    stockItems[products[0].getName()] = 10;
    stockItems[products[1].getName()] = 20;
    stockItems[products[2].getName()] = 30;
    stockItems[products[3].getName()] = 5;
    stockItems[products[4].getName()] = 100;
}
void Stock::addProduct(const Product product, int stockQty) {
    stockItems[product.getName()] = stockQty;
}

void Stock::updateStock(string &productName, int qty) { // checks if product is available and the amount is sufficient, updates the stock
    if (stockItems.contains(productName)) {
        reduceStock(productName, qty);
        return;
    }
    throw logic_error("Product not found in stock.");
}

void Stock::reduceStock(string prodName, int quantity) {
    if (stockItems[prodName] < quantity) {
        throw logic_error("Insufficient stock for product");
    }
    stockItems[prodName] -= quantity;
}
