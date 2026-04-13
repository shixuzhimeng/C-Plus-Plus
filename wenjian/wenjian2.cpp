#include <iostream>
#include <fstream>
using namespace std;

class Person{
public:
    char m_name[50];
    int m_Age;
};

int main() {
    // ofstream ofs("person.txt", ios::out | ios::binary);
    // Person p = {"renle", 19};
    // ofs.write((const char *)&p, sizeof(Person));
    // ofs.close();


    ifstream ifs("person.txt", ios::in | ios::binary);
    if (!ifs.is_open()) {
        cout << "failed" << endl;
        return 0;
    }
    Person p;
    ifs.read((char*)&p, sizeof(Person));   // 关键：读取数据
    cout << p.m_name << " " << p.m_Age << endl;
    ifs.close();
    return 0;
}