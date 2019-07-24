#pragma once
#include "IPerson.h"
#include "IRecord.h"

class Student:
	public IRecord, public IPerson
{
public:
	int getId() const override;
	std::string  getName() const override;
	std::string getFormatted() const override;
	Student(int id, std::string name);

private:
	int id;
	std::string name;
};
