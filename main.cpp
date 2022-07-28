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
   Point(const Point& point):
   x{point.x},
   y{point.y}
   {}

   int GetX() const{
       return x;
   }

   int GetY() const{
       return y;
   }

   void print() const{
       std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
   }

   const Point* GetThis() const{
       return this;
   }

   void non_const_print(){
       std::cout<<"x: "<<x<<" y: "<<y<<std::endl;
   }
private:
    const int x;
    const int y;
};

//Inheritance
class Point3D: public Point{
public:
    Point3D(): z{0}{}

    Point3D(int x, int y, int z):
    Point{x, y},
    z{z}
    {}

    Point3D(const Point3D& point):
    Point{point.GetX(), point.GetY()},
    z{point.z}
    {}

private:
    const int z;
};

/*
public:
public -> public
protected -> protected
private -> no access

private:
public -> private
protected -> private
private -> no access

protected:
public -> protected
protecte -> protected
private -> no access
*/

class DynamicArray{
public:
    DynamicArray();
    explicit DynamicArray(size_t size); //constructor-converter
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
    std::cout<<"DynamicArray(size_t size)"<<std::endl;
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

void fuzz(const DynamicArray& array){}

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

    std::cout<<"&p1="<<&p1<<"="<<p1.GetThis()<<std::endl;
    std::cout<<"&p2="<<p2<<"="<<p2->GetThis()<<std::endl;

    const Point* arg=p1.GetThis();
    //arg->non_const_print();
    arg->print();

    Point3D point3d1(3, 4, 5);
    point3d1.print();

    size_t size1 = 1;
    fuzz(size1); //fuzz(DynamicArray(size));

    return 0;
}
