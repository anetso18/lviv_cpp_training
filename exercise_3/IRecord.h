#pragma once
#include <string>
#include <map>

class IRecord
{
public:

	virtual int getId() const = 0;
	virtual std::string getFormatted() const = 0;
	IRecord( int id);
	IRecord();
	virtual ~IRecord() = default;

private:
	 int id;
};


