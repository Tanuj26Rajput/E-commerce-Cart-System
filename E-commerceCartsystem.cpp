#include <iostream>
#include <vector>
using namespace std;

class Product{
public:
    int id;
    string name;
    int price;
};

void DisplayProducts(vector<Product> &products){
    cout << "Available Products: " << endl << endl;
    cout << "ID\tName\tPrice" << endl;
    for(int i = 0;i<products.size();i++){
        cout << products[i].id << "\t" << products[i].name << "\t" << products[i].price << endl;
    }
    cout << "-------------------------------------------------" << endl;
    cout << endl;
}

class Cart{
public:
    Product product;
    int quantity;
};

void AddtoCart(vector<Product> &products, vector<Cart> &cart){
    int productID, quantity;
    cout << "Enter ID of product you want to add: ";
    cin >> productID;
    cout << "Enter quantity: ";
    cin >> quantity;
    for(int i = 0;i <products.size();i++){
        if(products[i].id == productID){
            Cart cartItem;
            cartItem.product = products[i];
            cartItem.quantity = quantity;
            cart.push_back(cartItem);
            cout << "Product added" << endl;
            cout << "---------------------------------------" << endl << endl;
            return;
        }
    }
}

void ViewCart(vector<Cart> &cart){
    cout << "Cart Items: "<<endl;
    cout << "ID\tName\tPrice\tQuantity" << endl;
    for(int i = 0;i<cart.size();i++){
        cout << cart[i].product.id << "\t" << cart[i].product.name << "\t" << cart[i].product.price << "\t" << cart[i].quantity << endl;
    }   
    cout << endl;
}

void Bill(vector<Cart> &cart){
    int total_amt = 0;
    cout << "BILL: " << endl;
    cout << "ID\tName\tPrice\tQuantity" << endl;
    for(int i = 0;i<cart.size();i++){
        cout << cart[i].product.id << "\t" << cart[i].product.name << "\t" << cart[i].product.price << "\t" << cart[i].quantity << endl;
        total_amt+=cart[i].product.price * cart[i].quantity;
    }   
    cout << "------------------------------------------------------------------" << endl;
    cout << "Total Amount : " << total_amt << endl << "------------------------------------------------------------------" << endl;
}

int main(){
    cout << "Welcome to E-commerce Cart System" << endl;
    vector<Product> products = {
        {1, "Laptop", 50000},
        {2, "Smartphone", 20000},
        {3, "Headphones", 1500},
        {4, "Keyboard", 800},
        {5, "Mouse", 400}
    };
    vector<Cart> cart;
    while(true){
        cout << "Choices: " << endl;
        cout << "1. View Available Products.\n2. Add items to cart.\n3. View your cart items.\n4. View bill." << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1: {
                DisplayProducts(products);
                break;
            }
            case 2: {
                AddtoCart(products, cart);
                break;
            }
            case 3: {
                ViewCart(cart);
                break;
            }
            case 4: {
                Bill(cart);
                break;
            }
            default:{
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
}
