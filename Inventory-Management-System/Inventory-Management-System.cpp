#include <iostream>
#include <limits>
#include "Inventory.h"

void pause() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Inventory inv;
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n=== Inventory Menu ===\n";
        std::cout << "1. Add product\n";
        std::cout << "2. Update product\n";
        std::cout << "3. Delete product\n";
        std::cout << "4. Search by ID\n";
        std::cout << "5. Search by Name\n";
        std::cout << "6. Display all\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            choice = -1;
            continue;
        }

        if (choice == 1) {
            std::cin.ignore(); // clear newline
            std::string name;
            double price;
            int qty, sid;
            std::cout << "Name: "; std::getline(std::cin, name);
            std::cout << "Price: "; std::cin >> price;
            std::cout << "Quantity: "; std::cin >> qty;
            std::cout << "Supplier ID: "; std::cin >> sid;
            inv.addProduct(name, price, qty, sid);
            std::cout << "Added.\n";
            pause();
        }
        else if (choice == 2) {
            int id;
            std::cout << "Enter Product ID to update: "; std::cin >> id;
            Product* p = inv.searchByID(id);
            if (!p) {
                std::cout << "Not found.\n";
                pause();
                continue;
            }
            std::cin.ignore();
            std::string name;
            double price;
            int qty;
            std::cout << "New Name: "; std::getline(std::cin, name);
            std::cout << "New Price: "; std::cin >> price;
            std::cout << "New Quantity: "; std::cin >> qty;
            if (inv.updateProduct(id, name, price, qty))
                std::cout << "Updated.\n";
            else
                std::cout << "Update failed.\n";
            pause();
        }
        else if (choice == 3) {
            int id;
            std::cout << "Enter Product ID to delete: "; std::cin >> id;
            if (inv.deleteProduct(id))
                std::cout << "Deleted.\n";
            else
                std::cout << "Not found.\n";
            pause();
        }
        else if (choice == 4) {
            int id;
            std::cout << "Enter Product ID: "; std::cin >> id;
            Product* p = inv.searchByID(id);
            if (p) p->display(); else std::cout << "Not found.\n";
            pause();
        }
        else if (choice == 5) {
            std::cin.ignore();
            std::string name;
            std::cout << "Enter Product Name: "; std::getline(std::cin, name);
            Product* p = inv.searchByName(name);
            if (p) p->display(); else std::cout << "Not found.\n";
            pause();
        }
        else if (choice == 6) {
            inv.displayAll();
            pause();
        }
    }

    std::cout << "Exiting...\n";
    return 0;
}
