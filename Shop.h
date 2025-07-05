//
// Created by Kareem Elnaghy on 05/07/2025.
//

#ifndef SHOP_H
#define SHOP_H

#include "Product.h"
#include "Stock.h"
#include "Customer.h"
#include "ShippingService.h"
#include <iostream>
#include <vector>
using namespace std;

class Shop {
    vector<Product> productCatalog;
    Stock stock;
    Customer customer;
    ShippingService shippingService;

public:
    Shop();
    void addProductToStock(const Product& product, int stockQty);
    void addToCart(string productName, int quantity);
    void checkout();
    const vector<Product>& getProductCatalog() const;
    double getCustomerBalance() const;
};



#endif //SHOP_H
