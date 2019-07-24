#include <iostream>
#include <vector>
#include "IRecord.h"
#include "Exam.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <memory>

	static std::unique_ptr<IRecord> create(const char recordType, std::stringstream& stream) {
		int id;
		std::string name;
		int courseId;
		int teacherId;
		int studentId;
		int result;
		
		switch (recordType) {
						
		case 'C':
			stream >> id >> name >> teacherId;
			return std::make_unique<Course>(id, name, teacherId);
			break;
		case 'E':
			stream >> id >> courseId >> studentId >> result;
			return std::make_unique<Exam>(id,courseId,studentId,result);
			break;
		case 'S':
			stream >> id >> name;
			return std::make_unique<Student>(id,name);
			break;
		case 'T':
			stream >> id >> name;
			return std::make_unique<Teacher>(id,name);
			break;
		default:
			throw std::invalid_argument("UnknownRecordType");
			break;
		}
	}

void moveToContainer( std::unique_ptr<IRecord> &&record , std::vector< std::unique_ptr<IRecord>> &container)
{
	container.emplace_back(std::move(record));
}

enum class LoadingResult {
	Ok,
	FileNotFound,
	UnknownRecordType
};

LoadingResult loadObjectsFromFile(const std::string& argv,
	                     std::vector< std::unique_ptr<IRecord>>& exams,
	                     std::vector< std::unique_ptr<IRecord>>& courses,
	                     std::vector< std::unique_ptr<IRecord>>& teachers,
	                     std::vector< std::unique_ptr<IRecord>>& students)
{
	std::ifstream in(argv);
	if (in.is_open())
	{
		std::string line;
		char separator = ' ';
		std::string substr;

		while (std::getline(in, line))
		{
			std::replace(line.begin(), line.end(), ',', separator);
			std::stringstream stream(line);
			std::getline(stream, substr, separator);
			stream >> substr;
			std::unique_ptr<IRecord> record= std::move(create(line[0], stream));
			switch(line[0])
			{
			case 'E':
				moveToContainer(std::move(record), exams); break;
				return	LoadingResult::Ok;
			case 'C':
				moveToContainer(std::move(record), courses); break;
				return	LoadingResult::Ok;
			case 'T':
				moveToContainer(std::move(record), teachers); break;
				return	LoadingResult::Ok;
			case 'S':
				moveToContainer(std::move(record), students); break;
			return	LoadingResult::Ok;
			default:
				std::cerr << "Unknown record type" << std::endl;
				return LoadingResult::UnknownRecordType;
            }
		}
	}
	else
	{
		std::cerr << "File not found" << std::endl;
		return LoadingResult::FileNotFound;
	}
}

bool compareRecordsById(const std::unique_ptr<IRecord>& a, const std::unique_ptr<IRecord>& b)
{
	return a->getId() < b->getId();
}

struct compareRecords
{
	inline bool operator()(const std::unique_ptr<IRecord>& a, const std::unique_ptr<IRecord>& b)
	{
		return a->getId() < b->getId();
	}
};

void writeObjectsToFile( std::string fileName, std::vector< std::unique_ptr<IRecord>>& container)
{
	std::ofstream output(fileName);
	if (output)
	{
		sort(container.begin(), container.end(), compareRecords());
		for (const auto& record: container) 
		{
			output << record->getFormatted()<< std::endl;
		}
	}
	else 
	{
		std::cerr << "Unable to create file." << std::endl;
	}

}

int main(int argc, char* argv[])
{
	std::vector< std::unique_ptr<IRecord>> exams;
	std::vector< std::unique_ptr<IRecord>> courses;
	std::vector< std::unique_ptr<IRecord>> teachers;
	std::vector< std::unique_ptr<IRecord>> students;

	loadObjectsFromFile(argv[1],exams, courses, teachers,students);
		
	writeObjectsToFile("./Exams.txt", exams);
	writeObjectsToFile("./Cources.txt", courses);
	writeObjectsToFile("./Students.txt", students);
	writeObjectsToFile("./Teachers.txt", teachers);
	
	return EXIT_SUCCESS;
}
