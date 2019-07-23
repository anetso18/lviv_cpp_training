// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
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

static std::shared_ptr<IRecord> create(const char recordType, std::stringstream& stream) 
{
	int id;
	std::string name;
	int courseId;
	int teacherId;
	int studentId;
	int result;
	switch (recordType)
	{
		case 'C':
			stream >> id >> name >> teacherId;
			return std::make_shared<Course>(id, name, teacherId); break;
		case 'E':
			stream >> id >> courseId >> studentId >> result;
			return std::make_shared<Exam>(id,courseId,studentId,result); break;
		case 'S':
			stream >> id >> name;
			return std::make_shared<Student>(id,name); break;
		case 'T':
			stream >> id >> name;
			return std::make_shared<Teacher>(id,name); break;
		default:
			throw std::invalid_argument("Invalid record type"); break;
	}
}

template<class T>
void moveToContainer(std::shared_ptr<IRecord> record , std::vector<std::pair<int, std::shared_ptr<IRecord>>> &container)
{
	container.emplace_back(record->getId(),std::move(record));
}

void loadObjectsFromFile(const std::string& argv, std::vector<std::pair<int, std::shared_ptr<IRecord>>> &exams,
			 std::vector<std::pair<int, std::shared_ptr<IRecord>>> &courses,
	                 std::vector<std::pair<int, std::shared_ptr<IRecord>>> &teachers,
                         std::vector<std::pair<int, std::shared_ptr<IRecord>>> &students)
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

			std::shared_ptr<IRecord> record = create(line[0], stream);

			switch(line[0])
			{
			case 'E':
				moveToContainer<Exam>(record, exams);	
				break;
			case 'C':
				moveToContainer<Course>(record, courses);
				break;
			case 'T':
				moveToContainer<Teacher>(record, teachers);
				break;
			case 'S':
				moveToContainer<Student>(record, students);
				break;
			default:
				throw std::invalid_argument("Invalid record type");
			}
		}
	}
	else
	{
		std::cerr << "Unable to open file";
		exit(1);
	}
}


void writeObjectsToFile( std::string fileName, std::vector<std::pair<int, std::shared_ptr<IRecord>>>& container)
{
	std::ofstream output(fileName);
	if (output)
	{
		for (auto &record: container) 
		{
			output <<record.second->getFormatted()<<std::endl;
		}
	}
	else 
	{
		std::cerr << "Unable to create file." << std::endl;
	}
}


int main(int argc, char* argv[])
{
	std::vector<std::pair<int, std::shared_ptr<IRecord>>> exams;
	std::vector<std::pair<int, std::shared_ptr<IRecord>>> courses;
	std::vector<std::pair<int, std::shared_ptr<IRecord>>> teachers;
	std::vector<std::pair<int, std::shared_ptr<IRecord>>> students;

	loadObjectsFromFile(argv[1],exams, courses, teachers,students);
		
	writeObjectsToFile("./Exams.txt", exams);
	writeObjectsToFile("./Cources.txt", courses);
	writeObjectsToFile("./Students.txt", students);
	writeObjectsToFile("./Teachers.txt", teachers);
}
