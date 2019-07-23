#pragma once
#include "IRecord.h"
#include "IPerson.h"

class Teacher :
	public IRecord, public IPerson
{
public:
	int getId() const override;
	std::string  getName() const override;
	std::string getFormatted() const override;
	Teacher(int id, std::string name);
	
private:
	int id;
    std::string name;
};

