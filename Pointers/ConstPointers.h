#pragma once
class ConstPointers
{
public:
	ConstPointers();
	void IncrementAll(int* start, int* stop);
	void PrintAll(const int* start, const int* stop);
};