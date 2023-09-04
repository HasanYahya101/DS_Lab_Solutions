#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	string name;
	int studentID;

public:
	Student()
	{
		this->name = "";
		this->studentID = 0;
	}

	Student(string name, int studentID)
	{
		this->name = name;
		this->studentID = studentID;
	}

	string getName()
	{
		return this->name;
	}
	int getStudentId() const
	{
		return this->studentID;
	}
};

class Course
{
private:
	string courseName;
	Student *students;
	int size;
	int capacity;

public:
	Course(string courseName)
	{
		this->courseName = courseName;
		this->size = 0;
		this->capacity = 2;
		this->students = new Student[this->capacity];
	}

	void addStudent(Student *student)
	{
		if (this->size == this->capacity)
		{
			this->capacity *= 2;
			Student *newStudents = new Student[this->capacity];
			for (int i = 0; i < this->size; i++)
			{
				newStudents[i] = this->students[i];
			}
			delete[] this->students;
			this->students = newStudents;
		}
		this->students[this->size] = *student;
		this->size++;
	}

	void displayStudents()
	{
		for (int i = 0; i < this->size; i++)
		{
			cout << i + 1 << ", " << this->students[i].getName() << ", " << this->students[i].getStudentId() << endl;
		}
	}

	~Course()
	{
		delete[] this->students;
	}
};

int main()
{
	Student student1("John Smith", 12345);
	Student student2("Jane Doe", 54321);
	Course mathCourse("Mathematics");
	mathCourse.addStudent(&student1);
	mathCourse.addStudent(&student2);
	mathCourse.displayStudents();
	return 0;
}
