#include<iostream>
using namespace std;

class Cart {
private:
    int* cart;
    int size;
    int capacity;
public:

    Cart() {
        size = 0;
        capacity = 10;
        cart = new int[capacity];
    }

    void add(int item) {
        if (size == capacity) {
            int* temp = new int[capacity * 2];
            for (int i = 0; i < size; i++) {
                temp[i] = cart[i];
            }
            delete[] cart;
            cart = temp;
            capacity *= 2;
        }
        cart[size] = item;
        size++;
    }

    void remove(int item) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (cart[i] == item) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Item not found" << endl;
            return;
        }
        for (int i = index; i < size - 1; i++) {
            cart[i] = cart[i + 1];
        }
        size--;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << cart[i] << " ";
        }
        cout << endl;
    }

    ~Cart() {
        delete[] cart;
    }
};

int main() {
    Cart c;
    c.add(1);
    c.add(2);
    c.add(3);
    c.add(4);
    c.add(5);
    c.add(6);
    c.add(7);
    c.add(8);
    c.add(9);
    c.add(10);
    c.add(11);
    c.print();
    c.remove(5);
    c.print();
    c.remove(11);
    c.print();
    c.remove(1);
    c.print();
    c.remove(11);
    c.print();
    return 0;
}