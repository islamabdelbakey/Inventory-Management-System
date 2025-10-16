#  Inventory Management System (C++)

##  Overview
This project is a simple **Inventory Management System** written in **C++**.  
It demonstrates the use of **Object-Oriented Programming (OOP)** concepts and **Data Structures** such as `vector` and `map` to manage products efficiently.

The system allows you to:
- ➕ Add new products  
- 🔍 Search products by ID or name  
- 📝 Update product details  
- ❌ Delete products  
- 📋 Display all available products  

---

## ⚙️ Features

### 1. **Product Class**
Represents a single product with:
- `id`
- `name`
- `price`
- `quantity`
- `supplierID`

Each product object is created from the `Product` class blueprint.

### 2. **Inventory Class**
Handles operations on all products using a **data structure** (`vector<Product>`):
- Add new product  
- Update existing product  
- Delete product by ID  
- Search product by name or ID  
- Display all products  

---

##  Project Structure

Inventory-Management/
│
├── include/
│ ├── Product.h
│ └── Inventory.h
│
├── src/
│ ├── Product.cpp
│ └── Inventory.cpp
│
├── main.cpp
│
└── README.md


---

##  Conceptual Design

| Concept | Description |
|----------|--------------|
| **Class** | Blueprint for an entity (e.g., `Product`) |
| **Object** | Actual instance of the class |
| **Data Structure** | Tool to store and manage multiple objects (e.g., `vector`, `map`) |

 **OOP** defines what a single product is.  
 **Data Structure** manages how multiple products are stored and accessed.

---

## 🧾 Example Code

```cpp
#include "Product.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<Product> inventory;

    // Add a product
    Product p1("Chocolate Jar", 25.5, 50, 1001);
    inventory.push_back(p1);

    // Display all products
    for (const Product& p : inventory) {
        p.display();
    }

    return 0;
}

 Technologies Used

C++

STL Containers: vector, map

OOP Concepts: Classes, Objects, Encapsulation

 Future Enhancements

File-based storage (save/load inventory)

Search optimization with map<int, Product>

Sorting products by price or quantity

Simple command-line user interface

 Author

Islam Mohamed Abdelbakey
Inventory Management Project — 2025
Made with ❤️ for learning and improvement.
