#include "stdafx.h"
#include "VoidPointers.h"
#include <stdlib.h>

VoidPointers::VoidPointers()
{
}

void VoidPointers::Increase(void * data, int size)
{
	// we can use sizeof here as for non dynamic data types the value is always consistent
	// E.G: sizeof(char) will allways be 1 as the size of a char is always 1 byte
	if (size == sizeof(char))
	{
		char* pChar = (char*)data;
		++(*pChar);
	}
	else if (size == sizeof(int))
	{
		int* pInt = (int*)data;
		++(*pInt);
	}
}
