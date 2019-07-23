#pragma once
#include "IRecord.h"
class Exam :
	public IRecord
{
public:
	Exam(int   id, int courseId, int studentId, int result);
	std::string getFormatted() const override;
	int getId() const override;

private:
	int id;
	int courseId;
	int studentId;
	int result;
};

