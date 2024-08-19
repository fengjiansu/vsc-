#include <bits/stdc++.h>
class Shape {
   public:
      virtual int area() = 0;
};

class Rectangle: public Shape {
   public:
      int area () { 
         std::cout << "Rectangle class area :"; 
         return (width * height); 
      }
    private:
        int width, height;
};

class Triangle: public Shape{
   public:
      int area () { 
         std::cout << "Triangle class area :"; 
         return (width * height / 2); 
      }
    private:
      int width, height;
};



int main()
{
Shape *shape;
   Rectangle rec;
   Triangle  tri;

   shape = &rec;
   shape->area();

   shape = &tri;
   shape->area();

   rec.area();
   tri.area();

   return 0;
}
