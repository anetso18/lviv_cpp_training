#include "Exam.h"
#include <iostream>
#include <sstream>

Exam::Exam(int id, int courseId, int studentId, int result) : id( id ), courseId{ courseId },
studentId{ studentId },result{ result } 
{ 
}

int Exam::getId() const
{
	return id;
}

std::string Exam::getFormatted() const 
{
	std::ostringstream stream;
	stream << getId() << "," << courseId << "," << studentId << "," << result << std::endl;

	return stream.str();
}