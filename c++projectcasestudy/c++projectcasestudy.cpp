#include <iostream>
#include <vector>
#include <string>
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

        cout << "Enter the name of product: "<<'\n';
        getline(cin, name);

        cout << "Enter the product id of product: "<<'\n';
        cin >> pid;
        cin.ignore(); 

        cout << "Enter product description: "<<'\n';
        getline(cin, description);

        cout << "Enter product manufacturer: "<<'\n';
        getline(cin, manufacturer);

        cout << "Enter the price: "<<'\n';
        cin >> price;

        cout << "Enter the quantity: "<<'\n';
        cin >> quantity;
        cin.ignore(); 

        cout << "Enter the location: "<<'\n';
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
                cout << "Name: " << Name[i] << ", PID: " << Pid[i] << ", Description: " << Description[i]<< ", Manufacturer: " << Manufacturer[i] << ", Price: " << Price[i] << ", Quantity: " << Quantity[i]<< ", Location: " << Location[i] << '\n';
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
                
                cout << "Enter new description: "<<'\n';
                getline(cin, description);
                Description[i] = description;

                cout << "Enter new manufacturer: "<<'\n';
                getline(cin, manufacturer);
                Manufacturer[i] = manufacturer;

                cout << "Enter new price: "<<'\n';
                cin >> price;
                Price[i] = price;

                cout << "Enter new quantity: "<<'\n';
                cin >> quantity;
                Quantity[i] = quantity;
                cin.ignore(); 

                cout << "Enter new location: "<<'\n';
                getline(cin, location);
                Location[i] = location;

                cout << "Product information updated successfully." <<'\n';
                found = true;
            }
        }
        if (!found) {
            cout << "Product not found." <<'\n';
        }
    }
  
};

int main() {
    ProductManager shop;
    int choice;
     // menu driven program banaya ;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add New Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Update Product\n";
        cout << "5. Exit\n";
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
            cout << "Exiting program.\n";
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    } 
    while (choice != 5);
    return 0;
}
