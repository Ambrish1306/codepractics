
#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Teacher {
public:
    Teacher(string name) : name(move(name)) {}

    const string& getName() const {
        return name;
    }

private:
    string name;
};

class Student {
public:
    Student(string name, weak_ptr<Teacher> teacher)
        : name(move(name)), teacher(move(teacher)) {}

    void showTeacher() const {
        if (auto teacherPtr = teacher.lock()) {
            cout << name << " is learning from " << teacherPtr->getName() << endl;
        } else {
            cout << name << " has no teacher now because the teacher was destroyed." << endl;
        }
    }

private:
    string name;
    weak_ptr<Teacher> teacher;
};

int main() {
    auto teacher = make_shared<Teacher>("Mr. Sharma");
    auto student1 = make_shared<Student>("Amit", teacher);
    auto student2 = make_shared<Student>("Neha", teacher);

    cout << "Before teacher is destroyed:" << endl;
    student1->showTeacher();
    student2->showTeacher();

    cout << "\nTeacher goes out of scope..." << endl;
    teacher.reset();

    cout << "After teacher is destroyed:" << endl;
    student1->showTeacher();
    student2->showTeacher();

    return 0;
}
