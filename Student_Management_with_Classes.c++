#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    string name;
    int age;
    float gpa;

public:
    Student(string name, int age, float gpa) {
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    void display() {
        cout << "Name: " << name << ", Age: " << age << ", GPA: " << gpa << endl;
    }
};

int main() {
    vector<Student> students;
    int n;

    cout << "Enter the number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int age;
        float gpa;

        cout << "Enter details for student " << i + 1 << " (Name, Age, GPA): ";
        cin >> name >> age >> gpa;

        students.push_back(Student(name, age, gpa));
    }

    cout << "\nList of Students:\n";
    for (auto &student : students) {
        student.display();
    }

    return 0;
}
