#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

class ProductManager {
private:
    vector<string> Name;
    vector<int> Pid;
    vector<string> Description;
    vector<string> Manufacturer;
    vector<float> Price;
    vector<int> Quantity;
    vector<string> Location;

public:

    //function for adding new product;
    void addNewProduct() {
        string name, description, manufacturer, location;
        int pid, quantity;
        float price;

        cout << "Enter the name of product: " << '\n';
        getline(cin, name);

        cout << "Enter the product id of product: " << '\n';
        cin >> pid;
        cin.ignore();

        cout << "Enter product description: " << '\n';
        getline(cin, description);

        cout << "Enter product manufacturer: " << '\n';
        getline(cin, manufacturer);

        cout << "Enter the price: " << '\n';
        cin >> price;

        cout << "Enter the quantity: " << '\n';
        cin >> quantity;
        cin.ignore();

        cout << "Enter the location: " << '\n';
        getline(cin, location);

        Name.push_back(name);
        Pid.push_back(pid);
        Description.push_back(description);
        Manufacturer.push_back(manufacturer);
        Price.push_back(price);
        Quantity.push_back(quantity);
        Location.push_back(location);

        cout << "Product added successfully." << '\n';
    }

    // function for dispaly the product details ;
    void displayProducts() {
        cout << "Products in shop:" << endl;
        for (size_t i = 0; i < Name.size(); ++i) {
            cout << "Name: " << Name[i] << ", PID: " << Pid[i] << ", Description: " << Description[i] << ", Manufacturer: " << Manufacturer[i] << ", Price: " << Price[i] << ", Quantity: " << Quantity[i] << ", Location: " << Location[i] << '\n';
        }
    }

    // function for searching product in tally of products ;

    void searchProduct(string product) {

        bool found = false;
        cout << "Search Result:" << endl;
        for (size_t i = 0; i < Name.size(); ++i) {
            if (Name[i] == product) {
                cout << "Name: " << Name[i] << ", PID: " << Pid[i] << ", Description: " << Description[i] << ", Manufacturer: " << Manufacturer[i] << ", Price: " << Price[i] << ", Quantity: " << Quantity[i] << ", Location: " << Location[i] << '\n';
                found = true;
            }
        }
        if (!found) {
            cout << "Product not found." << '\n';
        }
    }

    // function for updating an product details in tally;

    void updateproductdetails(string productname) {
        bool found = false;
        for (size_t i = 0; i < Name.size(); ++i) {
            if (Name[i] == productname) {
                string  description, manufacturer, location;
                float price;
                int   quantity;

                cout << "Enter new description: " << '\n';
                getline(cin, description);
                Description[i] = description;

                cout << "Enter new manufacturer: " << '\n';
                getline(cin, manufacturer);
                Manufacturer[i] = manufacturer;

                cout << "Enter new price: " << '\n';
                cin >> price;
                Price[i] = price;

                cout << "Enter new quantity: " << '\n';
                cin >> quantity;
                Quantity[i] = quantity;
                cin.ignore();

                cout << "Enter new location: " << '\n';
                getline(cin, location);
                Location[i] = location;

                cout << "Product information updated successfully." << '\n';
                found = true;
            }
        }
        if (!found) {
            cout << "Product not found." << '\n';
        }
    }

    // Function for delete a product by  their name from tally;

    void deleteProduct(string product) {
        auto it = find(Name.begin(), Name.end(), product);
        if (it != Name.end()) {
            size_t index = distance(Name.begin(), it);
            Name.erase(Name.begin() + index);
            Pid.erase(Pid.begin() + index);
            Description.erase(Description.begin() + index);
            Manufacturer.erase(Manufacturer.begin() + index);
            Price.erase(Price.begin() + index);
            Quantity.erase(Quantity.begin() + index);
            Location.erase(Location.begin() + index);
            cout << "Product '" << product << "' deleted successfully." << '\n';
        }
        else {
            cout << "Product not found." << '\n';
        }
    }

    // Function for sort products by their name from tally;

    void sortProduct() {
        vector<pair<string, size_t>> sortedProducts;
        for (size_t i = 0; i < Name.size(); ++i) {
            sortedProducts.push_back({ Name[i], i });
        }
        sort(sortedProducts.begin(), sortedProducts.end());

        cout << "Sorted Products by Name:" << '\n';
        for (const auto& product : sortedProducts) {
            size_t index = product.second;
            cout << "Name: " << Name[index] << ", PID: " << Pid[index] << ", Description: " << Description[index] << ", Manufacturer: " << Manufacturer[index] << ", Price: " << Price[index] << ", Quantity: " << Quantity[index] << ", Location: " << Location[index] << '\n';
        }
    }

};

int main() {
    ProductManager shop;
    int choice;
    // menu driven program banaya hai  ;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add New Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Product\n";
        cout << "5. Delete Product\n";
        cout << "6. Sort Product\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            shop.addNewProduct();
            break;
        }
        case 2: {
            shop.displayProducts();
            break;
        }
        case 3: {
            string product;
            cout << "Enter the name of the product you want to search: ";
            getline(cin, product);
            shop.searchProduct(product);
            break;
        }
        case 4: {
            string product;
            cout << "Enter the name of the product you want to update: ";
            getline(cin, product);
            shop.updateproductdetails(product);
            break;
        }
        case 5: {
            string product;
            cout << "Enter the name of product you want to delete: ";
            getline(cin, product);
            shop.deleteProduct(product);
            break;
        }

        case 6: {
            shop.sortProduct();
            break;
        }

        case 7: {
            cout << "Exiting program.\n";
            break;
        }

        default: {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } while (choice != 5);
    return 0;
}