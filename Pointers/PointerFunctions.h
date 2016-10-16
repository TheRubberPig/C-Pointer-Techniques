#pragma once
class PointerFunctions
{
public:
	PointerFunctions();
	int Addition(int a, int b);
	int Subtraction(int a, int b);
	int Operation(int x, int y, int(*functocall) (int, int));
};