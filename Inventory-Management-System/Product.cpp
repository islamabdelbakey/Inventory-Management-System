#include "Product.h"
#include <iostream>

int Product::nextID = 1;

Product::Product(const std::string& name_, double price_, int quantity_, int supplierID_)
    : name(name_), price(price_), quantity(quantity_), supplierID(supplierID_) {
    id = nextID++;
}

int Product::getID() const { return id; }
std::string Product::getName() const { return name; }
int Product::getQuantity() const { return quantity; }
double Product::getPrice() const { return price; }
int Product::getSupplierID() const { return supplierID; }

void Product::setName(const std::string& newName) { name = newName; }
void Product::setPrice(double newPrice) { price = newPrice; }
void Product::setQuantity(int newQuantity) { quantity = newQuantity; }
void Product::setSupplierID(int newSupplierID) { supplierID = newSupplierID; }

void Product::display() const {
    std::cout << "Product ID: " << id
        << " | Name: " << name
        << " | Price: " << price
        << " | Qty: " << quantity
        << " | SupplierID: " << supplierID
        << std::endl;
}
