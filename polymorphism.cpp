// Polymorphism is a concept in which a variable or function can take many forms. 
// It is the capability of an object to take on various forms. 
// It is the capability of a method to do different things based on the object it is acting upon.

/* In C++ there are two types of polymorphism: compile time polymorphism and runtime polymorphism.
	Compile time is static binding, and runtime is dynamic binding. */

// Static Binding 
/* Performed at compile time and achieved through method overloading.
	If there are severl methods with the same name but different parameters, it is called method overloading.
	The compiler decides which method is to be invoked depending on the number of parameters and its order. 
	This is decided at compile time. */

// Dynamic binding
/* it is achieved through method overriding. When a method in a subclass has the same name and signature as
	a method in a parent class, then the method in the derived class overrides the method in the parent class.
	When an overridden method is called through a parent class reference, C++ determines which version of the
	method to call based on the object type being referred to at the time the call occurs. Because method
	overriding depends on the invoking object, it is called runtime polymorphism or dynamic binding. */

// Abstract base class
/* A class that is designed to be used for the parent class. It contains at least one pure virtual function.
	A pure virtual function is suitable when we have a method that we want to place in the parent class, but
	only the sub classes know what it should return. Abstract classes cannot be instanitated directly. 
*/


// Redfining Functions beginning with an example from the previous module
#include <string>
#include <iostream>
using namespace std;

// Base class
class Student
{
	protected:
	int rollNo;
	string name;
	
	public:
	Student(){} // Default constructor
	Studemt(int rollNo, string name) { // Parameterized constructor
		this->rollNo = rollNo;
		this->name = name;
	}
	
	void display() { // Method with the same name and signature
		cout <<"Roll No" << rollNo << endl;
		cout << "Name" << name << endl;
	}
};


// Derived class
class Hosteller:public Student
{
	private:
	int roomNo;
	string foodType;
	
	public: 
	Hosteller(){} // Default constructor
	// Parameterized constructor
	Hosteller(int rollNo, string name, int roomNo, string foodType):Student(rollNo, name)
	{
		this->roomNo = roomNo;
		this-> foodType = foodType;
	}
	
	void display() // Method with the same name and signature
	{
		cout << "Room No" << roomNo << endl;
		cout << "Food Type" << foodType << endl;
	}
};

int main()
{
	Hosteller obj(1, "Eliza", 23, "Veg"); // Created an object named Hosteller for the child class
	obj.display(); // When invoking display, there is confusion as to which method to choose (parent or child)
	// The compiler will usually choose the method that is in the derived class. So how can we work around
	// this problem?
}

// To ensure that the correct function gets called from the object, we include a virtual keyword to the base
// class method. This helps to identify that we have two methods with the same name. To ensure proper execution
// we declare a pointer reference to the base class. The pointer can reference the objects of both classes. 
// 

// Base class
class Student
{
	protected:
	int rollNo;
	string name;
	
	public:
	Student(){} // Default constructor
	Studemt(int rollNo, string name) { // Parameterized constructor
		this->rollNo = rollNo;
		this->name = name;
	}
	
	virtual void display() { // Method with the same name and signature
		cout <<"Roll No" << rollNo << endl;
		cout << "Name" << name << endl;
	}
};


// Derived class
class Hosteller:public Student
{
	private:
	int roomNo;
	string foodType;
	
	public: 
	Hosteller(){} // Default constructor
	// Parameterized constructor
	Hosteller(int rollNo, string name, int roomNo, string foodType):Student(rollNo, name)
	{
		this->roomNo = roomNo;
		this-> foodType = foodType;
	}
	
	void display() // Method with the same name and signature
	{
		cout << "Room No" << roomNo << endl;
		cout << "Food Type" << foodType << endl;
	}
};

int main() {
	Student *ptr; // reference the base class and points to the base and derived class
	Student obj(1, "Eliza");
	ptr=&obj1;
	ptr->display(); // Helps to execute the display method in the Student class
	
	Hosteller obj2(1, "Eliza", 23, "Veg");
	ptr= &obj2;
	ptr->display(); // Helps to execute the display method in the Hosteller class
	
	// This style of method indication is known as method overriding
	return 0;
}
	
// Pointer to objects
/* C++ allows you to assign the address of the derived class object to the base class pointer.
	Now if you try to access the member of the derived class using the base class pointer, it will not
	allow you to access the member of the derived class. 
	
	To overcome this problem, declare a pointer of the derived class and then assign the address of the 
	derived class object to this pointer. 
	
	Hosteller *ptr; // derived class
	Hosteller obj (1, "Eliza", 23, "Veg");
	ptr = obj; // Pointer reference of the derived class and address of derived class */

// Virtual Function

/* A virtual function is another way of implementing runtime polymorphism in C++.
	
	A virtual function is a member functio that is declared within a base class and is redefined or overwritten
	by a derived class. 
	
	When you refer to a subclass object using a pointer, you can:
	Call a virtual function for that object. 
	Execute the version of the function of that subclass.
	
	A class that declares or inherits a virtual function is called a polymorphic class. */

// Vrtual Function Rules

/* Virtual functions cannot be static or cannot be a friend function of another class.
	
	Virtual functions should be accessed using pointer or reference of base class type to
	achieve runtime polymorphism. 
	
	The prototype of virtual functions should be the same in both the base class and derived class. 
	
	They are always defined in a base class and overridden in a derived class. 
	
	It is not mandatory for a derived class to override or redefine a virtual function. 
	
	A class can have a virtual destructor, but it cannot have a virtual constructor. */
	
