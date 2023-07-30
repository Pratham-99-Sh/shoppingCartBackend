#include <iostream>
#include <vector>
#include "dataModel.h"

using namespace std;

vector<Product> allProducts = {
    Product(1, "Apple", 100),
    Product(2, "Banana", 50),
    Product(3, "Orange", 80),
    Product(4, "Mango", 150),
    Product(5, "Pineapple", 200),
    Product(6, "Grapes", 120),
    Product(7, "Watermelon", 80),
    Product(8, "Kiwi", 100),
    Product(9, "Papaya", 70),
    Product(10, "Guava", 60)
};

Product* chooseProduct(){
    string productList;
    for(auto pd : allProducts)
        productList.append(pd.getDisplayName());

    cout << productList << endl;
    cout << "......................" << endl;
    string choice;
    cin >> choice;

    for(int i=0; i<allProducts.size(); i++)
        if(allProducts[i].getShortName() == choice)
            return &(allProducts[i]);

    cout << "Product not found!" << endl;
    return NULL;
}

bool checkout(Cart &cart)
{
    if(cart.isEmpty()){
        cout << "Cart is empty!" << endl;
        return false;
    }

    int total = cart.getTotalPrice();
    cout << "Total: Rs." << total << endl;
    cout << "Pay in Cash : Rs. ";
    int paid; cin >> paid;
    
    if(paid < total){
        cout << "Insufficient amount!" << endl;
        return false;
    }
    else{
        int change = paid - total;
        if(change) cout<< "Change: Rs." << change << endl;
        cout << "Thank you for shopping with us!" << endl;
        return true;
    }
}

int main(){
    char action;
    Cart cart;
    while(true){
       cout << "Choose action: (a)dd item,  (v)iew cart,  (c)heckout,  (e)xit" << endl;
       cin >> action;
       if(action == 'a'){
            Product* pd = chooseProduct();
            if(pd!=NULL){
                cout << "Product added to cart : " + pd->getDisplayName() << endl;
                cart.addProduct(*pd);
            }
       }
       else if(action == 'v'){
        cout << "......................" << endl;
        cout << cart.viewCart() << endl;
        cout << "......................" << endl;
       }
       else if(action == 'e'){
           break;
       }
       else{
            if(checkout(cart))
                break;
       }
    }
    return 0;
}