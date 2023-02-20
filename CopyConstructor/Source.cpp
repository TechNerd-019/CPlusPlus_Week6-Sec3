// Student: Salah S.
// Topic:   Copy constructor, more on polymorphism, and memory management in C++.
// Class:   Week 6 - Section 3 - 1:00 P.M - 3:00 P.M.
// Prof.:   Akrem El-Ghazal
// Program: PROG71020 - Object Oriented Programming

#include <iostream>
using namespace std;

class Person
{
	int* age;
public:
	Person(int age)
	{
		cout << "Person(int age) constructor is called " << endl;
		this->age = new int;
		*(this->age) = age;
	}
	int getAge()
	{
		return *age;
	}
	void setAge(int age)
	{
		*(this->age) = age;
	}
   // This is what the "copy" constructor looks like:
   //Person(Person& rhs)  // "rhs" referring to "right-hand side".
   //{
   //	cout << "Person(Person &rhs) COPY constructor is called." << endl;
   //	this->age = rhs.age;
   // 
   // THIS DOES NOT WORK WITH POINTERS!!
   // This default copy constructor is not concerned about pointers.
   // 
   //}

	Person(Person& rhs)
	{
		age = new int;
		*(this->age) = *rhs.age;
	}

	Person& operator=(Person& rhs)
	{
		cout << "Person operator=(Person&rhs) assignment operator is called." << endl;
		if (this != &rhs)         // This checks for the address of the objects being assigned.
			                      // If they are not the same, they are assigned, if they are, return.
		{
			*this->age = *rhs.age;
		}
		/*this->age = rhs.age;    Pointer to pointer.*/
		/*this->age = *rhs.age;   Value on address.*/
		return *this;
	}

	// This delete constructor CANNOT run without the copy and reassignment constructor.
	// This is the case if we are deleting both the ages for p1 and p2.
	// If we pass it a parameter for a single object, this could work without them.
	~Person()
	{
		delete age;
	}
	// The general rule is that if you are forced to do a reassignment,
	// always rewrite the copy constructor, and vice versa.
};

int main(void)
{
	cout << "Start... " << endl;

	Person p1(100);
	Person p2 = p1; // This line calls the "copy" constructor.
	                // It is told to assign this new object to be equal to the first object.
	                // A constructor can only be called once, the copying is executed here.
	p1.setAge(89);
	/*p2 = p1;      // As confusing as this is, this is NOT copying. */
	                // In here, the assignment operator is used, output is 89 for both.
	                // Regardless, this is NOT the same as copying.
	
	cout << p1.getAge() << endl;
	cout << p2.getAge() << endl;

	int x = 5;
	int y = x;
	x = 10;

	Person p3(100);
	Person p4(55);
	p3 = p4;        // This is another example of an assignment operator.
	                // Operator from line 42-47 is called.

	cout << p3.getAge() << endl;
	cout << p4.getAge() << endl;

	p4 = p4;       // It is still calling the assignment operator.

	system("pause");
	return 0;
}
