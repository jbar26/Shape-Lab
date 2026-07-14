#include <iostream>
#include <vector>

using namespace std;	

class Shape
{
private:
public:
	Shape() {}
	// virtual double getArea() { return 0; } // Virtual function with default implementation
	// virtual double getPerimeter() { return 0; } // Virtual function with default implementation	

	virtual double getArea() = 0; 
	virtual double getPerimeter() = 0; 
	virtual void printName()
	{
		cout << "I am a generic shape." << endl;
	}

	void printAreaToScreen(Shape* shapePtr)
	{
		shapePtr->printName();
		cout << "My Area is: " << shapePtr->getArea() << endl;
	}
};

class Circle : public Shape
{
private:
	double radius;
public:
	Circle(double r)
	{
		radius = r;
	}
	double getArea() 
	{ 
		return 3.14 * radius * radius; 
	} 
	double getPerimeter()
	{ 
		return 2 * 3.14 * radius; 
	} 
	void printName()
	{
		cout << "I am a Circle." << endl;
	}
};

class Rectangle : public Shape
{
private:
	double width;
	double height;
public:	
	Rectangle(double w, double h) 
	{
		width = w;
		height = h;
	}
	double getArea() 
	{ 
		return width * height; 
	} 
	double getPerimeter() 
	{ 
		return 2 * (width + height); 
	}
	void printName()
	{
		cout << "I am a Rectangle." << endl;
	}
};

class Square : public Rectangle
{
public:
	Square(double s) : Rectangle(s, s)
	{
	}
	// Do not need to overwrite get_Area and get_Perimeter.  
	void printName()
	{
		cout << "I am a Square." << endl;
	}
};

class RightTriangle : public Shape
{
private:
	double base;
	double height;
public:
	RightTriangle(double b, double h) 
	{
		base = b;
		height = h;
	}
	double getArea()
	{ 
		return 0.5 * base * height; 
	}

	double getPerimeter() 
	{ 
		return base + height + sqrt(base * base + height * height); 
	} 
	void printName()
	{
		cout << "I am a Right Triangle." << endl;
	}

};

class IsoscelesRightTriangle : public RightTriangle
{
private: 

public: 
	IsoscelesRightTriangle(double s) : RightTriangle(s, s)
	{
	}
	// Do not need to overwrite area and perim methods
	void printName()
	{
		cout << "I am a Isosceles Right Triangle." << endl;
	}
};



int main()
{
	//Shape s = Shape();
	//cout << "Shape Area: " << s.getArea() << endl;

	Circle c = Circle(5);
	cout << "Circle Area: " << c.getArea() << endl;
	cout << "Circle Perimeter: " << c.getPerimeter() << endl;

	Rectangle r = Rectangle(4, 6);
	cout << "Rectangle Area: " << r.getArea() << endl;
	cout << "Rectangle Perimeter: " << r.getPerimeter() << endl;

	RightTriangle t = RightTriangle(3, 4);
	cout << "Right Triangle Area: " << t.getArea() << endl;
	cout << "Right Triangle Perimeter: " << t.getPerimeter() << endl;

	Shape* shapePtr = &c; // Pointer to Shape, pointing to Circle
	Shape* shapePtr2 = &r; // Pointer to Shape, pointing to Rectangle
	Shape* shapePtr3 = &t; // Pointer to Shape, pointing to RightTriangle

	cout << shapePtr->getArea() << endl; // Calls Circle's getArea()
	cout << shapePtr2->getArea() << endl; // Calls Rectangle's getArea()	
	cout << shapePtr3->getArea() << endl; // Calls RightTriangle's getArea()

	Square sq = Square(3);
	cout << sq.getArea() << endl;
	cout << sq.getPerimeter() << endl;
	Shape* shapePtr4 = &sq;
	cout << shapePtr4->getArea() << endl;


	IsoscelesRightTriangle ri = IsoscelesRightTriangle(6);
	cout << ri.getArea() << endl;
	cout << ri.getPerimeter() << endl;
	Shape* shapePtr5 = &ri;
	cout << shapePtr5->getArea() << endl;

	cout << "\n\n\n";

	vector<Shape*> listOfShapes;
	listOfShapes.push_back(shapePtr);
	listOfShapes.push_back(shapePtr2);
	listOfShapes.push_back(shapePtr3);
	listOfShapes.push_back(shapePtr4);
	listOfShapes.push_back(shapePtr5);

	for (Shape* s : listOfShapes)
	{
		s->printAreaToScreen(s);
	}
	

}