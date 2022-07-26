#include <iostream>

int square(int number){
    return number * number;
}

class Point
{
public:
   //Default constructor
   Point():
   x{0},
   y{0}{       
   }

   Point(int x, int y):
   x{x},
   y{y}{
   }

   //Copy constructor
   Point(const Point& point){
       x = point.x;
       y = point.y;
   }

   void print(){
       std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
   }
private:
    int x;
    int y;
};

class DynamicArray{
public:
    DynamicArray();
    DynamicArray(size_t size);
    DynamicArray(const DynamicArray& some_array);
    ~DynamicArray();
private:
    size_t size;
    int* array_pointer;
};

DynamicArray::DynamicArray():
size(0),
array_pointer(nullptr)
{
}

DynamicArray::DynamicArray(size_t size):
size(size)
{
    array_pointer = new int[size];
}

DynamicArray::DynamicArray(const DynamicArray& some_array):
size{some_array.size}
{
    array_pointer = new int[size];

    for(size_t i = 0; i < size; ++i){
        array_pointer[i] = some_array.array_pointer[i];
    }
}

DynamicArray::~DynamicArray(){
    
    if(array_pointer != nullptr)
    {
        delete[] array_pointer;
        array_pointer = nullptr;
    }
}

int main() 
{
    int result = square(2);
    //1. call square
    //2. get return value (4 in our case)
    //3. assign return value to result variable
    std::cout<<result<<std::endl;
    std::cout<<square(3)<<std::endl;
    Point p1(1, 2);
    //int x = p1.x;

    Point *p2 = new Point(3, 4);

    p1.print();
    p2->print();
    return 0;
}
