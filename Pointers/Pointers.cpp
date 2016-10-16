/*
Pointers practise and definitions
See http://www.cplusplus.com/doc/tutorial/pointers/ for more
*/

#include "stdafx.h"
#include "ConstPointers.h"
#include "VoidPointers.h"
#include "PointerFunctions.h"
#include <stdlib.h>
#include <iostream>
using namespace std; //<-- using this as this is only a basic program and wont use multiple namespaces

void BasicPointers();
void SettingInts();
void ArraysAndPointers();
void Initialization();
void PointerMaths();
void CPointers();
void StringPointers();
void PointersToPointers();
void VPointers();
void InvalidandNull();
//void PtoF();

int main()
{
	BasicPointers();
	SettingInts();
	ArraysAndPointers();
	Initialization();
	PointerMaths();
	CPointers();
	StringPointers();
	PointersToPointers();
	VPointers();
	InvalidandNull();
	//PtoF(); Currently doesn't work, using old syntax
    return 0;
}

void BasicPointers()
{
	//& is the address of pointer
	int val1 = 20;
	//Stores the address of val1 into myAdd, an * is needed after an in as we are using pointers.
	//a variable which stores the address of another variable is called a pointer.
	//can also be written as int* var, int * var or int *var
	int* myAdd = &val1;
	//Prints the address of val1
	cout << "##### Basic use of pointers #####" << endl;
	cout << myAdd << std::endl;
	//Pointers can be used to access the variable they point to directly by using the dereference operator (*)
	//Can be read as the value pointed to by...
	int baz_20 = *myAdd;
	cout << baz_20 << " = Using * on the previous pointer/address" << std::endl;
	int* baz_add = myAdd;
	cout << baz_add << " = Without * on the same pointer as above" << std::endl;
	cout << endl;
	/*
	^^ shows that above from the same pointer you can get the memory address of the pointer and what is stored there

	& is the address-of operator, and can be read simply as "address of"
	* is the dereference operator, and can be read as "value pointed to by"

	*/
}

void SettingInts()
{
	//You can set the value of ints through pointers (below)
	int firstValue, secondValue;
	int* pointer;
	pointer = &firstValue;
	*pointer = 10;
	pointer = &secondValue;
	*pointer = 20;
	cout << "##### Setting the values of ints through pointers #####" << endl;
	cout << "First value = " << firstValue << endl;
	cout << "Second value = " << secondValue << endl;
	cout << endl;
}

void ArraysAndPointers()
{
	// You can mix pointers and arrays as they can work the same way (below)
	int numbers[5];
	int* p;
	p = numbers;
	/*int ten = 10;
	for (int i = 0; i < 5; i++)
	{
	*p = ten;
	ten = ten + 10;
	p++;
	^^ This all works well but to show other ways pointers and arrays can be used
	this will be commented out
	}*/
	*p = 10;
	p++;
	*p = 20;
	p = &numbers[2];
	*p = 30;
	p = numbers + 3;
	*p = 40;
	p = numbers;
	*(p + 4) = 50;
	cout << "##### Using Pointers and arrays #####" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << numbers[i] << ", ";
	}
	cout << endl;
	cout << endl;
	/*
	The main difference being that pointers can be assigned new addresses, while arrays cannot.
	You can use the same operators for an array on a pointer e.g.:
	a[5] = 0;
	*(a+5) = 0;
	*/
}

void Initialization()
{
	//Pointers can be initalized the moment they are defined
	int myVar = 25;
	int* myPtr = &myVar;
	// ^^ is the same as...
	int myVar2 = 50;
	int* myPtr2;
	myPtr2 = &myVar2;
	/*
	When pointers are initialized, what is initialized is the address they point to (i.e., myptr), 
	never the value being pointed (i.e., *myptr). Therefore, the code above shall not be confused with:
	*myPtr2 = &myVar2; (This is invalid)
	*/
	int myVar3 = 100;
	int* foo = &myVar3;
	int* bar = foo;
	cout << "##### Initialization of pointers #####" << endl;
	cout << myPtr << " method 1" << endl;
	cout << myPtr2 << " method 2" << endl;
	cout << bar << " Pointer to a pointer" << endl;
	cout << endl;
}

void PointerMaths()
{
	// Only addition and subtraction are allowed and depend on the size of the
	// data they point to
	char char1 = 'a';
	short short1 = 1;
	long long1 = 99842123;

	char* charP = &char1;
	short* shortP = &short1;
	long* longP =  &long1;

	cout << "##### Pointer Maths #####" << endl;
	cout << charP << " address of char a" << endl;
	cout << shortP << " adress of short 1" << endl;
	cout << longP << " adress of long 998421233486424234" << endl;
	cout << endl;

	++charP;
	++shortP;
	++longP;
	
	cout << charP << " char pointer +1 (increase start of mem addddress by 1)" <<endl;
	cout << shortP << " short pointer +1 (increase mem addrress by 2)"<< endl;
	cout << longP << " long pointer +1 (increase of mem address by 4)"<<endl;
	cout << endl;

	/* ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
	Shows what happens to the memory address of different pointers when incremented by 1,
	depending on the pointer they are increased through memory by different amounts
	*/

	shortP = &short1;

	*shortP++; // same as *(p++): increment pointer, and dereference unincremented address
	cout << shortP << " Address of short pointer after *shortP++" << endl;
	cout << *shortP << " Value of short pointer after *shortP++" << endl;
	cout << endl;
	shortP = &short1;

	*++shortP; // same as *(++p): increment pointer, and dereference incremented address
	cout << shortP << " Address of short pointer after *++shortP" << endl;
	cout << *shortP << " Value of short pointer after *++shortP" << endl;
	cout << endl;
	shortP = &short1;

	++*shortP; // same as ++(*p): dereference pointer, and increment the value it points to
	cout << shortP << " Address of short pointer after ++*shortP" << endl;
	cout << *shortP << " Value of short pointer after ++*shortP" << endl;
	cout << endl;
	short1 = 1;
	shortP = &short1;

	(*shortP)++; // dereference pointer, and post-increment the value it points to 
	cout << shortP << " Address of short pointer after (*shortP)++" << endl;
	cout << *shortP << " Value of short pointer after (*shortP)++" << endl;
	shortP = &short1;

	/* ^^^^^^^^^^^^^^
	This shows how precedences and prefixes can affect how a pointer is modified and how some don't matter.
	*/
	cout << endl;
}

void CPointers()
{
	ConstPointers CPointers;
	int numbers[] = { 10, 20 ,30 };
	cout << "##### Constant Pointers #####" << endl;
	CPointers.IncrementAll(numbers, numbers + 3);
	CPointers.PrintAll(numbers, numbers + 3);
	cout << endl;
	/*
	Can have const pointers and vary what they can point to
	int x = 2;
	int* p1 = &x; --- non-const pointer to non const int
	const int* p2 = &x; --- non-const pointer to a const int 
	int* const p3 = &x; --- const pointer to a non const int
	const int* const p4 = &x; --- const pointer to a const int
	*/
}

void StringPointers()
{
	const char* string = "Hello";
	cout << "##### String Pointers #####" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << string[i]; // can use *(string + 2) to access different elements 
	}
	cout << endl;
	cout << endl;
}

void PointersToPointers()
{
	char a = 'z';
	char* b = &a;
	char** c = &b; // each * indicates another level I.E: to point to c you need ***d = &c
	cout << "##### Pointers to pointers ######" << endl;
	cout << c << " = top level pointer (c)" << endl;
	cout << *c << " = middle pointer (*c)" << endl;
	cout << **c << " = value stored (**c)" << endl;
	cout << endl;
}

void VPointers()
{
	char a = 'x';
	int b = 1602;
	VoidPointers VP;
	VP.Increase(&a, sizeof(a));
	VP.Increase(&b, sizeof(b));
	cout << "##### Void Pointers #####" << endl;
	cout << a << ", " << b << endl;
	cout << endl;
}

void InvalidandNull()
{
	int* p;
	int myarray[10];
	int* q = myarray + 20;
	// ^^^ these are invalid pointers and are working pointers but they point to no meaningful value

	int* n = 0;
	int* o = nullptr;
	int* r = NULL;
	// ^^^^ These are null pointers and point to a null value, they are different to invalid pointers as they do point
	// to a specific value (null)
	cout << "##### Invalid and Null #####" << endl;
	cout << q << " = a invalid pointer" << endl;
	cout << r << " = a null pointer" << endl;
	cout << endl;
}

/*void PtoF()
{
	PointerFunctions PF;
	int m, n;
	int(*minus) (int, int) = PF.Subtraction;

	m = PF.Operation(7, 5, &PF.Addition);
	n = PF.Operation(20, m, minus);
	cout << "##### Pointers to Functions #####" << endl;
	cout << m << endl;
	cout << n << endl;
	cout << endl;
}*/
