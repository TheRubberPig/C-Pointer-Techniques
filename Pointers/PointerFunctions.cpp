#include "stdafx.h"
#include "PointerFunctions.h"
#include <stdlib.h>

PointerFunctions::PointerFunctions()
{
}

int PointerFunctions::Addition(int a, int b) {return (a + b);}

int PointerFunctions::Subtraction(int a, int b) {return (a-b);}

int PointerFunctions::Operation(int x, int y, int(*functocall)(int, int))
{
	int g = (*functocall) (x, y);
	return (g);
}
