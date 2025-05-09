#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Student {
private:
    std::string name;
    int rollNumber;
    float cgpa;
    std::vector<std::string> courses;

public:
    Student() : name(""), rollNumber(0), cgpa(0.0f) {
        std::cout << "Default constructor called.\n";
    }

    Student(const std::string& n, int roll, float gpa, const std::vector<std::string>& courseList)
        : name(n), rollNumber(roll), cgpa(0.0f) {
        std::cout << "Parameterized constructor called.\n";
        setCGPA(gpa);  // Use setter for validation
        for (const auto& course : courseList) {
            addCourse(course);  // Use method to validate and add courses
        }
    }

    Student(const Student& other)
        : name(other.name), rollNumber(other.rollNumber), cgpa(other.cgpa), courses(other.courses) {
        std::cout << "Copy constructor called.\n";
    }

    ~Student() {
        std::cout << "Destructor called for student: " << name << std::endl;
    }

    void addCourse(const std::string& course) {
        // Check for duplicates
        if (std::find(courses.begin(), courses.end(), course) == courses.end()) {
            courses.push_back(course);
            std::cout << "Course '" << course << "' added.\n";
        } else {
            std::cout << "Course '" << course << "' is already enrolled.\n";
        }
    }

    void setCGPA(float newCGPA) {
        if (newCGPA >= 0.0f && newCGPA <= 10.0f) {
            cgpa = newCGPA;
            std::cout << "CGPA updated to " << cgpa << ".\n";
        } else {
            std::cout << "Invalid CGPA. Must be between 0.0 and 10.0.\n";
        }
    }

    void display() const {
        std::cout << "\n--- Student Information ---\n";
        std::cout << "Name       : " << name << "\n";
        std::cout << "Roll No    : " << rollNumber << "\n";
        std::cout << "CGPA       : " << cgpa << "\n";
        std::cout << "Courses    : ";
        for (const auto& course : courses) {
            std::cout << course << " ";
        }
        std::cout << "\n---------------------------\n";
    }
};