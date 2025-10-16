#pragma once
#include <vector>
#include <string>
#include "Product.h"

class Inventory {
private:
    std::vector<Product> products;

public:
    // Add
    void addProduct(const Product& p);
    void addProduct(const std::string& name, double price, int quantity, int supplierID);

    // Search
    Product* searchByID(int id);
    Product* searchByName(const std::string& name); // returns first match

    // Update
    bool updateProduct(int id, const std::string& newName, double newPrice, int newQuantity);

    // Delete
    bool deleteProduct(int id);

    // Display
    void displayAll() const;
};
