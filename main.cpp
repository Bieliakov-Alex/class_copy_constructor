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
    DynamicArray(const& DynamicArray some_array);
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

DynamicArray::DynamicArray(const& DynamicArray some_array){
    array_pointer = some_array.array_pointer;
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
    return 0;
}