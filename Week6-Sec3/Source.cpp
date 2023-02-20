// Student: Salah S.
// Topic:   Polymorphism and function overriding in C++.
// Class:   Week 6 - Section 3 - 2:00-3:00 P.M.
// Prof.:   Akrem El-Ghazal
// Program: PROG71020 - Object Oriented Programming

#include <iostream>

using namespace std;

// Function overriding refers to have the same function
// on a different class.

class Shape {
public:

	// The keyword "virtual" means that if a pointer is created,
	// it is going to go to the subclass specified by the pointer.

	// It basically says "Ok, ignore my existence, go straight to subclass".

	virtual void print()
	{
		cout << "Shape::Base class" << endl;
	}

	// A pure virtual function is a function initialized to 0.
	// If the class has a method that does not have value, it is called pure virtual function.
	// A class with a pure virtual function, is called an abstract class.
	// virtual void print() = 0;

};
class Rectangle : public Shape
{
public:
	void print()
	{
		cout << "Rectangle::Derived class" << endl;
		cout << "************************" << endl;
		cout << "**                    **" << endl;
		cout << "************************" << endl;
	}
};

class Circle : public Shape
{
public:
	void print()
	{
		cout << "Cirlce::Derived class" << endl;
		cout << "*************" << endl;
		cout << "**         **" << endl;
		cout << "*************" << endl;
	}
};


// This function prints the shape passed to it.
// Because shape is the parent class, you are able
// to pass it a derived class object, and it should
// be able to print it.

// It is also able to print it because the type "virtual"
// is used at the base (parent) class.

void disply(Shape& o)
{
	// ........... Some setting.
	//             Complex thing.
	//             Complex thing.


	// The '&' symbol (which is the reference symbol), is 
	// used as a "handler", which will allow the function call
	// from main to pass it any shape from the inherited class
	// and print it to the screen. Without the reference, it just
	// goes to the parent class.

	o.print();
}

int main(void)
{
	cout << "Start..." << endl;

	Shape shapeNoPointer;
	Circle circ;
	Rectangle rect;
	shapeNoPointer.print();
	circ.print();
	rect.print();
	cout << endl;
	cout << endl;


	//This same object is then initialized as a pointer object instead.;
	Shape* shape;
	

	// The "shape" pointer object is now pointing to a rectangle.
	// Can also be used to point to other objects.
	shape = &rect;


	// Even though it is pointing to circle, it still prints 
	// base, since it goes to base first. The keyword "virtual"
	// is needed to print the object being pointed to.
	shape->print();
	cout << endl;
	cout << endl;


	// Thanks to polymorphism, the "dsply" function can use any
	// object to print, and not just print, but perform different
	// actions. This is what is at the core of polymorphism.

	disply(circ);
	cout << endl;
	cout << endl;

	system("pause");
	return 0;

}