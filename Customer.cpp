//
// Created by Kareem Elnaghy on 05/07/2025.
//

#include "Customer.h"

Customer::Customer() : balance(3000) {}

void Customer::add(string productName, int quantity) {
    cartItems[productName] = quantity;
}

void Customer::checkout(vector<Product> products, double* subtotal, vector<pair<Product, int>>* shippedProducts) const {
    if (cartItems.empty()) {
        throw logic_error("Cart is empty");
    }

    for (pair<string, int> item : cartItems) {
        auto it = find_if(products.begin(), products.end(), [&](const Product& product) { return product.getName() == item.first; });
        Product p = (it != products.end()) ? *it : throw logic_error("Product not found in catalog");
        if (p.requiresShipping()) {
            shippedProducts->push_back({p, item.second});
        }
    }

    for (pair<string, int> item : cartItems) {
        auto it = find_if(products.begin(), products.end(), [&](const Product& product) { return product.getName() == item.first; });
        Product p = (it != products.end()) ? *it : throw logic_error("Product not found in catalog");
        int qty = item.second;

        *subtotal += p.getPrice() * qty;
    }
}

const unordered_map<string, int>& Customer::getCart() const {
    return cartItems;
}

bool Customer::updateBalance(int amount) {
    if (balance > amount) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}

double Customer::getBalance() const {
    return balance;
}


