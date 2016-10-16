#include "stdafx.h"
#include "ConstPointers.h"
#include <stdlib.h>
#include <iostream>

ConstPointers::ConstPointers()
{

}

void ConstPointers::IncrementAll(int * start, int * stop)
{
	int* current = start;
	while (current != stop)
	{
		++(*current); //increment value pointed
		++current; //increment pointer
	}
}

void ConstPointers::PrintAll(const int * start, const int * stop)
{
	const int* current = start;
	while (current != stop)
	{
		std::cout << *current << std::endl;
		++current; //increment pointer
		// ^^ The pointers point to a constant value but the pointers aren't
		// constant themselves so they can be modified.
	}
}





