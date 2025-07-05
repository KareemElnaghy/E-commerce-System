#include "Shop.h"
#include <iostream>
using namespace std;

int main() {
    Shop shop;
    string productName;
    int quantity;
    char choice;

    cout << "Welcome to the Shop!" << endl;

    while (true) {
        cout << "\nAvailable products:" << endl;
        for (const auto& product : shop.getProductCatalog()) {
            cout << "- " << product.getName() << " (" << product.getPrice() << ")" << endl;
        }

        cout << "\nEnter the name of the product you want to add to your cart: ";
        getline(cin, productName);
        cout << "Enter the quantity: ";
        cin >> quantity;

        try {
            shop.addToCart(productName, quantity);
            cout << quantity << "x " << productName << " added to your cart." << endl;
        } catch (const logic_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << "\nDo you want to add more items? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            break;
        }
    }

    cout << "\nProceeding to checkout..." << endl;

    try {
        shop.checkout();
        cout << "Checkout successful! Remaining balance: " << shop.getCustomerBalance() << endl;
    } catch (const logic_error& e) {
        cout << "Error during checkout: " << e.what() << endl;
    }

    return 0;
}