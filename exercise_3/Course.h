#pragma once
#include "IRecord.h"
class Course :
	public IRecord
{
public:
	Course(int id, std::string name, int teacherId);
	int getId() const override;
	std::string getFormatted() const override;

private:
	int id;
	std::string name;
	int teacherId;
};

