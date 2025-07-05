# Shop Management Application

## Overview
This is a simple C++ console-based application that simulates a shopping experience. Users can browse a catalog of products, add items to their cart, and proceed to checkout. The application calculates the total cost, including shipping, and deducts the amount from the user's balance. It also handles various error scenarios, such as insufficient balance, expired products, or unavailable stock.

## Features
- **Product Catalog**: Displays a list of available products with their prices.
- **Cart Management**: Allows users to add products to their cart with specified quantities.
- **Checkout Process**: Calculates the total cost (including shipping) and deducts it from the user's balance.
- **Error Handling**: Handles errors like insufficient balance, expired products, and empty carts.

## Design
The application is designed using the following classes:
1. **`Product`**: Represents a product with attributes like name, price, weight, and shipping requirements.
2. **`Stock`**: Represents the currently available products in stock and their quantities.
3. **`Customer`**: Manages the user's cart, balance, and checkout process.
4. **`Shop`**: Manages the product catalog, stock, and overall shopping process.
5. **`ShippingService`**: Calculates shipping costs based on product weight.

## Assumptions
- The initial customer balance is set to 3000 just for example.
- Products have attributes like price, weight, and expiration date.
- Shipping costs are calculated based on the weight of the products requiring shipping.
- Expired products cannot be added to the cart.
- The product catalog is predefined in the `Shop` class.

