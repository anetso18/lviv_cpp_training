#include "Teacher.h"
#include <string>
#include <sstream>
#include <memory>

int Teacher::getId() const
{
	return id;
}
std::string Teacher::getName() const
{
	return name;
}

Teacher::Teacher(int id, std::string name)
	:id( id ), name{ std::move( name ) }
{
}

std::string  Teacher::getFormatted() const
{
	std::ostringstream stream;
	stream << getId() << "," << getName() << std::endl;

	return stream.str();
}
