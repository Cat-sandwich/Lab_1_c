#pragma once
#include <iostream>

class Exception
{
public:
	Exception();
	virtual void print() const = 0;
};
class Invalid_Index : public Exception
{
private:
	int i, j, n, m;
public:
	Invalid_Index(int i, int j, int m, int n);
	void print() const override;
};

class Empty : public Exception
{
public:
	Empty();
	void print() const override;
};





