#pragma once

#include <iostream>
#include <exception>
//using namespace std;

class ExBadLenght : public std::exception
{
public:
	virtual const char* what() const noexcept override;
};

class ExBadCreation : public std::exception
{
public:
	virtual const char* what() const noexcept override;
};

class ExBadInteger : public std::exception
{
public:
	virtual const char* what() const noexcept override;
};

class ExBadIndex : public std::exception
{
public:
	virtual const char* what() const noexcept override;
};