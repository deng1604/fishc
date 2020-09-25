#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
    char name[64];
    int age;
};

int main()
{
    // read
    fstream file;

    // 2.
    file.open("writeFILE.txt", ios::in | ios::binary);

    if (!file.is_open())
    {
        cout << "打开失败!!!" << endl;
        return 1;
    }

    Person p;
    file.read((char*)&p, sizeof(Person));

    cout << p.name << "   " << p.age << endl;

    file.close();
}