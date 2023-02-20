// Student: Salah S.
// Topic:   Copy constructor, more on polymorphism, and memory management in C++.
// Class:   Week 6 - Section 3 - 1:00 P.M - 3:00 P.M.
// Prof.:   Akrem El-Ghazal
// Program: PROG71020 - Object Oriented Programming

#include <iostream>

using namespace std;

class Mark 
{
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
};


int main(void)
{
	cout << "Start..." << endl;
	Mark p(2, 3);
	p.print();

	Mark *p2 = new Mark(1, 4);

	Mark* p3 = (Mark*)malloc(sizeof Mark);    // This is theb "C" style of allocating memory.

	delete p2;       // This does not actually delete the pointer, it only frees the memory. 
	                 // In line 46, it may still be used, keyword is misleading.
	p2 = new Mark(1, 6);

	

	//cout << p;   // This will NOT work! Overloading cout needs to be done.

	system("pause");
	return 0;
}