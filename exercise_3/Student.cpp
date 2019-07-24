#include "Student.h"
#include <iostream>
#include <sstream>
#include <memory>

Student::Student(int id, std::string name)
	:id{ id }, name{ std::move(name) }
{
}

int Student::getId() const
{
	return id;
}

std::string Student::getName() const
{
	return name;
}

std::string  Student::getFormatted() const
{
	std::ostringstream stream;
	stream << getId() << "," << getName() << std::endl;

	return stream.str();
}