// #include <iostream>
// #include <string>
// using namespace std;
// int main() {
//     int N;
//     char fill_char;
//     cin >> N >> fill_char;
//     cin.ignore();
    
//     string s;
//     getline(cin, s);
    
//     int len = s.length();
    
//     if (N > len) {
//         for (int i = 0; i < N - len; i++) {
//             cout << fill_char;
//         }
//         cout << s << endl;
//     }
//     else {
//         for (int i = len - N; i < len; i++) {
//             cout << s[i];
//         }
//         cout << endl;
//     }
    
//     return 0;
// }

// #include <iostream>
// #include <string>
// #include <set>
// using namespace std;
// int  main() {
//     int y, n;
//     cin >> y >> n;

//     int age = 0;
//     int year = y;  

//     while(1) {
//         string s1 = to_string(year);
//         while (s1.length() < 4) {
//             s1 = "0" + s1;
//         }
//         set<char> a1;
//         for(char c : s1) {
//             a1.insert(c);
//         }
//         if(a1.size() == n) {
//             break;
//         }
//         year++;
//         age++;
//     }
//     cout << age << " ";
//     printf("%04d\n", year);
    
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int N;
//     cin >> N;

//     vector<int> count(1001, 0);
    
//     for(int i = 0; i < N; i++) {
//         int K;
//         cin >> K;
        
//         for(int j = 0; j < K; j++) {
//             int a;
//             cin >> a;
//             count[a]++;
//         }
//     }

//     int max_count = 0;
//     int max_a = 0;
    
//     for(int i = 1; i <= 1000; i++) {
//         if(count[i] >= max_count) {
//             max_count = count[i];
//             max_a = i;
//         }
//     }

//     cout << max_a << " " << max_count << endl;
    
//     return 0;
// }

// #include <iostream>
// #include <iomanip>
// using namespace std;

// int main() {
//     int A, B;
//     cin >> A >> B;
    
//     if(B == 0) {
//         cout << A << "/0=Error" << endl;
//     }
//     else if(B < 0) {
//         double result = (double)A / B;
//         cout << A << "/(" << B << ")=" << fixed << setprecision(2) << result << endl;
//     }
//     else {
//         double result = (double)A / B;
//         cout << A << "/" << B << "=" << fixed << setprecision(2) << result << endl;
//     }
    
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main () {
    vector<string> names;
    string name;
    
    while (1) {
        cin >> name;
        if(name == ".") {
            break;
        }
        names.push_back(name);
    }
    
    int count = names.size();

    if(count >= 14) {
        cout << names[1] << " and " << names[13] << " are inviting you to dinner..." << endl;
    }
    else if (count >= 2) {
        cout << names[1] << " is the only one for you..." << endl;
    }
    else {
        cout << "Momo... No one is for you ..." << endl;
    }
    
    return 0;
}
