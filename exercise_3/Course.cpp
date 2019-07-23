#include "Course.h"
#include <string>
#include <sstream>

int Course::getId() const
{
	return id;
}

Course::Course(int id, std::string name, int teacherId)
	:id( id ), name{ name }, teacherId{ teacherId }
{
}

std::string  Course::getFormatted() const  
{
	std::ostringstream stream;
	stream << getId() << "," << name << "," << teacherId << std::endl;
	
	return stream.str();
}
