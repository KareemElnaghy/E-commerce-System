//
// Created by Kareem Elnaghy on 05/07/2025.
//

#include "ShippingService.h"


ShippingService::ShippingService() : shippingCostPerKg(5) {}
void ShippingService::calculateShippingCost(vector<pair<Product,int>> *shippedProducts, double* totalWeight, double* cost) const {
    for (pair<Product,int> p: *shippedProducts) {
        if (p.first.requiresShipping()) {
            *totalWeight += (p.first.getWeight())* p.second;
        }
    }
    *cost = *totalWeight / 1000 * shippingCostPerKg;
}
