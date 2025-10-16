#include "Inventory.h"
#include <algorithm>
#include <iostream>

void Inventory::addProduct(const Product& p) {
    products.push_back(p); // copy the product object into the vector
}

void Inventory::addProduct(const std::string& name, double price, int quantity, int supplierID) {
    products.emplace_back(name, price, quantity, supplierID); // construct in-place
}

Product* Inventory::searchByID(int id) {
    for (auto& p : products) {
        if (p.getID() == id) return &p;
    }
    return nullptr;
}

Product* Inventory::searchByName(const std::string& name) {
    for (auto& p : products) {
        if (p.getName() == name) return &p;
    }
    return nullptr;
}

bool Inventory::updateProduct(int id, const std::string& newName, double newPrice, int newQuantity) {
    Product* p = searchByID(id);
    if (!p) return false;
    p->setName(newName);
    p->setPrice(newPrice);
    p->setQuantity(newQuantity);
    return true;
}

bool Inventory::deleteProduct(int id) {
    auto it = std::remove_if(products.begin(), products.end(),
        [id](const Product& p) { return p.getID() == id; });
    if (it == products.end()) return false;
    products.erase(it, products.end());
    return true;
}

void Inventory::displayAll() const {
    if (products.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }
    for (const auto& p : products) p.display();
}
