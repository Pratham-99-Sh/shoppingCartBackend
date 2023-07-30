#include <string>
#include <unordered_map>

using namespace std;

class Cart;
class Item;

class Product{
    int id;
    string name;
    int price;

    public:

    Product(){}
    Product(int u_id, string u_name, int price){
        id = u_id;
        name = u_name;
        this->price = price;
    }

    string getDisplayName(){
        return name + " : Rs. " + to_string(price);
    }

    string getShortName(){
        return name.substr(0, 1);
    }

    friend class Cart;
    friend class Item;
};

class Item{
    Product product;
    int quantity;

    public:

    Item() {}
    Item(Product product, int quantity){
        this->product = product;
        this->quantity = quantity;
    }

    int getItemPrice(){
        return product.price * quantity; 
    }

    string getItemInfo(){
        return to_string(quantity) + " x " +product.name + " : Rs. " + to_string(getItemPrice());
    }

    friend class Cart;
};

class Cart{
    unordered_map<int, Item> items;

    public:

    void addProduct(Product product){
        if(items.find(product.id) == items.end()){
            Item item(product, 1);
            items[product.id] = item;
        }
        else{
            items[product.id].quantity += 1;
        }
    }

    void removeProduct(Product product){
        if(items.find(product.id) != items.end()){
            items[product.id].quantity -= 1;
            if(items[product.id].quantity == 0){
                items.erase(product.id);
            }
        }
    }

    int getTotalPrice(){
        int total = 0;
        for(auto it = items.begin(); it != items.end(); it++){
            total += it->second.getItemPrice();
        }
        return total;
    }

    string viewCart(){
        string cartInfo = "";
        for(auto it = items.begin(); it != items.end(); it++){
            cartInfo += it->second.getItemInfo() + "\n";
        }

        return cartInfo + "Total Price : Rs. " + to_string(getTotalPrice());
    }

    bool isEmpty(){
        return items.size() == 0;
    }
};