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
        setCGPA(gpa);
        for (const auto& course : courseList) {
            addCourse(course);
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
        std::cout << "Roll Number: " << rollNumber << "\n";
        std::cout << "CGPA       : " << cgpa << "\n";
        std::cout << "Courses    : ";
        for (const auto& course : courses) {
            std::cout << course << " ";
        }
        std::cout << "\n----------------------------\n";
    }

    int getRollNumber() const {
        return rollNumber;
    }
};

class StudentManagementSystem {
private:
    std::vector<Student> students;

public:
    void addStudent(const Student& student) {
        for (const auto& s : students) {
            if (s.getRollNumber() == student.getRollNumber()) {
                std::cout << "Error: Student with roll number " << student.getRollNumber() << " already exists.\n";
                return;
            }
        }
        students.push_back(student);
        std::cout << "Student added successfully.\n";
    }

    Student* searchStudent(int rollNumber) {
        for (auto& student : students) {
            if (student.getRollNumber() == rollNumber) {
                return &student;
            }
        }
        std::cout << "Student with roll number " << rollNumber << " not found.\n";
        return nullptr;
    }

    void displayAllStudents() {
        if (students.empty()) {
            std::cout << "No student records available.\n";
            return;
        }
        for (const auto& student : students) {
            student.display();
        }
    }
};

int main() {
    StudentManagementSystem system;

    Student s1("Alice", 101, 8.7, {"Math", "Physics"});
    Student s2("Bob", 102, 9.1, {"Chemistry"});

    system.addStudent(s1);
    system.addStudent(s2);

    Student duplicate("Charlie", 101, 7.5, {"English"});
    system.addStudent(duplicate);

    Student* found = system.searchStudent(102);
    if (found) {
        found->addCourse("Biology");
        found->setCGPA(9.5);
        found->display();
    }

    system.displayAllStudents();

    return 0;
}
