#include <iostream>
using namespace std;

class Vector
{
public:
    Vector(){capacity=0, size=0, arr=new int[capacity];}
    ~Vector(){cout<<arr[0];}
public:
void push_front(int i) {
    Arr *arr = new Arr(i);
    arr->setNext(Head);
    Head = arr;
}
    void push_back(int elem){if( size==capacity)
    {
        capacity*=2;
        int* tmp=new int[capacity];
        for(int i=0; i<size;++i)
            {
                tmp[i]=arr[i];   
            }
        delete[]arr;
        arr=tmp;
    }
    arr[size]=elem;
    size=size+1;
}
private:
    int capacity;
    int size;
    int* arr;    
};

int main(){
    Vector o;
    o.push_back(100);
}