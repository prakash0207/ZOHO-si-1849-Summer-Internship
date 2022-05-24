#include <iostream>
#include <exception>
#include <vector>
using namespace std;

class AgeNotWithinRangeException: public exception
{
  virtual const char* what() const throw()
  {
    return "Age not within range exception";
  }
};

class NameNotValidException: public exception
{
  virtual const char* what() const throw()
  {
    return "Name not valid exception";
  }
};

class InvalidCoursesException: public exception
{
  virtual const char* what() const throw()
  {
    return "Invalid courses exception";
  }
};

class Student
{
    int rollNo, age;
    string name, course;
public:
    Student(int rn, int ag, string nm, string cr)
    {
        rollNo = rn;
        age = ag;
        name = nm;
        course = cr;
    }
    void getStudentInfo()
    {
        cout<<"Roll no.: "<<rollNo<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Course: "<<course<<endl;
    }
};

int main ()
{
    int age,rollNo;
    string name,course;
    bool containsSpecialChar,containsDigit;
    try
    {
        int noOfStuObj;
        cout<<"For how many students you have to make entry: ";
        cin>>noOfStuObj;
        if(noOfStuObj>1)
        {
            throw 20;
        }

        try
        {
            cout<<"Enter the age: ";
            cin>>age;
            if(age<15 or age>21)
            {
                throw AgeNotWithinRangeException();
            }
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }

        try
        {
            cout<<"Enter the Name: ";
            cin>>name;
            containsDigit = false;
            containsSpecialChar = false;
            for(auto c:name)
            {
                if(ispunct(c))
                {
                    containsSpecialChar = true;
                }
                if(isdigit(c))
                {
                    containsDigit = true;
                }
            }
            if(containsSpecialChar || containsDigit)
            {
                throw NameNotValidException();
            }
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }


        try
        {
            bool courseAvailable = false;
            cout<<"Enter Course Name(C,Java,Python,Swift,Javascript): ";
            cin>>course;
            for(int i=0;i<course.length();i++)
            {
                if(isupper(course[i]))
                {
                    course[i] = tolower(course[i]);
                }
            }
            vector<string> courseNames;
            courseNames.push_back("c");
            courseNames.push_back("java");
            courseNames.push_back("python");
            courseNames.push_back("swift");
            courseNames.push_back("javascript");
            int vSize = courseNames.size();
            for(int i=0;i<vSize;i++)
            {
                if(courseNames[i] == course)
                {
                    courseAvailable = true;
                }
            }
            if(courseAvailable == false)
            {
                throw InvalidCoursesException();
            }
        }
        catch (exception& e)
        {
            cout << e.what() << endl;
        }
        cout<<"Enter roll no: ";
        cin>>rollNo;

        Student s1(rollNo,age,name,course);
        s1.getStudentInfo();
    }
    catch(...)
    {
        cout<<"Exception: Cannot create more than one student object";
    }
    return 0;
}
