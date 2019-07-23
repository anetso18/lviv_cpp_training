#include "IRecord.h"

IRecord::IRecord(int id) : id{id}
{
}

IRecord::IRecord() {}

int IRecord::getId() const {

	return id;
}