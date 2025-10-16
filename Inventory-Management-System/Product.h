#pragma once
#include <string>

class Product {
private:
    int id;
    std::string name;
    int quantity;
    double price;
    int supplierID;
    static int nextID;

public:
    Product() = default; // default constructor (مهم لبعض الاستخدامات)
    Product(const std::string& name_, double price_, int quantity_, int supplierID_);

    // getters
    int getID() const;
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
    int getSupplierID() const;

    // setters
    void setName(const std::string& newName);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);
    void setSupplierID(int newSupplierID);

    void display() const;
};
