// Student: Salah S.
// Topic:   Copy constructor, more on polymorphism, and memory management in C++.
// Class:   Week 6 - Section 3 - 1:00 P.M - 3:00 P.M.
// Prof.:   Akrem El-Ghazal
// Program: PROG71020 - Object Oriented Programming

#include <iostream>

using namespace std;

class Mark
{
	// When creating variable pointers, these need to be cleared on a separate function.
	// C++ allows us to do this using destrucy.

	int p;
	int w;

public:
	Mark()
	{
		cout << "Mark() Create the object." << endl;
		p = 0;
		w = 0;
	}

	Mark(int p, int w)
	{
		cout << "Mark(int p, int w) Create the object." << endl;
		this->p = p;
		this->w = w;
	}

	void print()    // Do NOT do this!! This is because we need to overload the cout operator.
		// Use "friend ostream[...]" to overload cout operator.
	{
		cout << p << ", " << w << endl;
	}


	// The destructor function, distinguished by the '~' symbol.
	// This destructor is called automatically.
	~Mark()
	{
		cout << "~Mark() destroy the object." << endl;
	}
};


int main(void)
{
	cout << "Start..." << endl;

	// Creating in the stack;
	// The destructor will be called at the end of the scope of what is inside these two brackets.
	// The stack is managed by the language, the heap is not, as we will see.
	/*{
		Mark p(1, 2);
	}*/


	// Creating in the heap:
	// This results in the destructor not being called. The stack is managed by C++.
	// The heap is self-managed memory. It needs to be called using the "delete" function.

	Mark* p = new Mark(2, 3);

	delete p;
	system("pause");
	return 0;
}