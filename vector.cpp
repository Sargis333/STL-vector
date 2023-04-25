#include <iostream>
using namespace std;

class MyVector {
public:

    MyVector() {
        size = 0;
        capacity = 10;
        array = new int[capacity];
    }
     
    MyVector(const MyVector& other) {
        size = other.size;
        capacity = other.capacity;
        array = new int[capacity];
        for (int i = 0; i < size; i++) {
            array[i] = other.array[i];
        }
    }


    MyVector& operator=(const MyVector& other) {
        if (this != &other) {
            delete[] array;
            size = other.size;
            capacity = other.capacity;
            array = new int[capacity];
            for (int i = 0; i < size; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }


    ~MyVector() {
        delete[] array;
    }


    

 
    void push_back(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* newArray = new int[capacity];
            for (int i = 0; i < size; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        array[size++] = value;
    }

    void push_front(int value) {
        if (size == capacity) {
            capacity *= 2;
            int* newArray = new int[capacity];
            for (int i = size - 1; i >= 0; i--) {
                newArray[i + 1] = array[i];
            }
            delete[] array;
            array = newArray;
        } else {
            for (int i = size - 1; i >= 0; i--) {
                array[i + 1] = array[i];
            }
        }
        array[0] = value;
        size++;
    }

    
    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    int temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
    }

    void erase(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                array[i] = array[i + 1];
            }
            size--;
        }
    }

    void print(){
        for(int i=0; i<size; i++){
            cout<<" "<<array[i];
        }
        cout<<endl;
    }

private:
    int* array;
    int size;
    int capacity;
};

int main() {
    MyVector myVector;

    myVector.push_back(3);
    myVector.push_back(7);
    myVector.push_back(1);
    myVector.push_back(8);

    myVector.push_front(5);
    myVector.push_front(9);
    myVector.sort();
    myVector.print();
   
}
