//
// Created by Kareem Elnaghy on 05/07/2025.
//

#include "Shop.h"

Shop::Shop() : productCatalog({
    Product("Cheese", 5.0, true, true, 200, 2025, 8),
    Product("Bread", 2.0, true, true, 500, 2025, 9),
    Product("Book", 10.0, false, true, 300, 0, 0),
    Product("Laptop", 1000.0, false, true, 2500, 0, 0),
    Product("Scratch Card", 1.0, false, false, 10, 0, 0)
}), stock(productCatalog) {}

void Shop::addProductToStock(const Product& product, int stockQty) {
    stock.addProduct(product, stockQty);
}

void Shop::addToCart(string productName, int quantity) {
    auto it = find_if(productCatalog.begin(), productCatalog.end(), [&](const Product& p) { return p.getName() == productName; });
    if (it == productCatalog.end()) {
        throw logic_error("Product not found in catalog");
    }
    if (it->isExpired()) {
        throw logic_error("Product is expired and cannot be added to cart" + it->getName());
    }
    stock.updateStock(productName, quantity);
    customer.add(productName, quantity);
}

void Shop::checkout() {

    double totalWeight = 0.0; // in grams
    double subtotal = 0.0;
    double shippingCost = 0.0;
    vector<pair<Product,int>> shippedProducts;

    customer.checkout(productCatalog, &subtotal, &shippedProducts);
    shippingService.calculateShippingCost(&shippedProducts, &totalWeight, &shippingCost);


    cout<<"** Shipping notice **"<<endl;
    for (auto p : shippedProducts) {
        cout<<p.second << "x " << p.first.getName() <<"\t";
        if (p.first.getWeight() * p.second < 1000)
            cout<<p.first.getWeight() * p.second<<"g"<<endl;
        else
            cout<<(p.first.getWeight() * p.second)/1000<<"Kg"<<endl;
    }
    cout<< "Total package weight "<<(totalWeight)/1000<<"Kg"<<endl<<endl;

    cout<< "** Checkout Receipt **"<<endl;
    for (auto product: customer.getCart()) {
        auto it = find_if(productCatalog.begin(), productCatalog.end(), [&](const Product& p) { return p.getName() == product.first; });
        if (it != productCatalog.end()) {
            cout << product.second << "x " << it->getName() << "\t" << it->getPrice() * product.second << endl;
        }
    }
    cout << "----------------------------" << endl;
    cout << "Subtotal\t" << subtotal << endl;
    cout << "Shipping\t" << shippingCost << endl;
    cout << "Amount\t" << subtotal + shippingCost << endl;

    if (!customer.updateBalance(subtotal + shippingCost)) {
        throw logic_error("Insufficient balance to complete the purchase.");
    }

}

const vector<Product>& Shop::getProductCatalog() const {
    return productCatalog;
}

double Shop::getCustomerBalance() const {
    return customer.getBalance();
}