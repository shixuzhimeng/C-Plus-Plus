#include <iostream>
#include <fstream>
using namespace std;

int main () {
    ofstream d1;
    d1.open("test.txt");
    d1 << "renlei" << endl;
    d1 << "19" << endl;
    d1 << "wasd" << endl;
    d1.close();

    ifstream d2;
    d2.open("test.txt", ios::in);
    if(!d2.is_open()) {
        cout << "打开失败" << endl;
        return 0;
    }

    //法一
    //char buf[1024] = {0};
    // while(d2 >> buf) {
    //     cout << buf << endl;
    // }
    
    //法二
    // while(d2.getline(buf, sizeof(buf))) {
    //     cout << buf << endl;
    // }
    
    //法三
    // string buf;
    // while(getline(d2,buf)) {
    //     cout << buf << endl;
    // }

    //法四
    char c;
    while((c = d2.get()) != EOF) {
        cout << c << endl;
    }

    d2.close();
    return 0;
}