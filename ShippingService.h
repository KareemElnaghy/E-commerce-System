//
// Created by Kareem Elnaghy on 05/07/2025.
//

#ifndef SHIPPINGSERVICE_H
#define SHIPPINGSERVICE_H

#include "Product.h"
#include <vector>
using namespace std;


class ShippingService {
    int shippingCostPerKg;
public:
    ShippingService();
    void calculateShippingCost(vector<pair<Product,int>> *shippedProducts, double* totalWeight, double* cost) const;
};



#endif //SHIPPINGSERVICE_H
