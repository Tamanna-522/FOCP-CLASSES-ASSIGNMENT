#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    std::string name;
    int rollNumber;
    float cgpa;
    std::vector<std::string> courses;

public:
    Student() : name(""), rollNumber(0), cgpa(0.0) {
        std::cout << "Default constructor called." << std::endl;
    }

    Student(const std::string& n, int roll, float gpa, const std::vector<std::string>& courseList)
        : name(n), rollNumber(roll), cgpa(gpa), courses(courseList) {
        std::cout << "Parameterized constructor called." << std::endl;
    }

    Student(const Student& other)
        : name(other.name), rollNumber(other.rollNumber), cgpa(other.cgpa), courses(other.courses) {
        std::cout << "Copy constructor called." << std::endl;
    }

    ~Student() {
        std::cout << "Destructor called for student: " << name << std::endl;
    }

    void display() const {
        std::cout << "Name: " << name << "\nRoll Number: " << rollNumber
                  << "\nCGPA: " << cgpa << "\nCourses: ";
        for (const auto& course : courses) {
            std::cout << course << " ";
        }
        std::cout << std::endl;
    }
};