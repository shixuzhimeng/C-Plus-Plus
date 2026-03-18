// #include <iostream>
// int a1[26] = {1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3, 1,2,3,4, 1,2,3, 1,2,3,4};
// using namespace std;
// int main () {
//     string s1;
//     getline(cin, s1);
//     int sum = 0;
//     for(auto c : s1) {
//         if(c == ' ') {
//             sum += 1;
//         }
//         else {
//             sum += a1[c - 'a'];
//         }
//     }
//     cout << sum << endl;
//     return 0;
// }

// #include <iostream>
// #include <string>
// using namespace std;
// int main()
// {
// 	int n = 0;
// 	cin >> n;
// 	string op;
// 	string num1;
// 	string num2;
// 	string last;
// 	int ret = 0;
// 	while (n--) {
//         string ans;
//     	cin >> op;
    	
//     	if (op == "a" || op == "b" || op == "c") {
//         	cin >> num1 >> num2;
//         	int n1 = stoi(num1);
//         	int n2 = stoi(num2);
//         	ans += num1;
//         	if (op == "a")
//             	ret = n1 + n2, ans += "+";
//         	else if (op == "b")
//             	ret = n1 - n2, ans += "-";
//         	else
//             	ret = n1 * n2, ans += "*";
//         	last = op;
// 	}
// 	else {
//     	num1 = op;
//     	cin >> num2;
//     	int n1 = stoi(num1);
//     	int n2 = stoi(num2);
    	
//     	ans += num1;
//     	if (last == "a")
//         	ret = n1 + n2, ans += "+";
//     	else if (last == "b")
//         	ret = n1 - n2, ans += "-";
//     	else
//         	ret = n1 * n2, ans += "*";
//     	}
//     	ans += (num2 + "=" + to_string(ret));
//     	cout << ans << endl;
//     	cout << ans.size() << endl;
// 	}
// 	return 0;
// }
#include <iostream>
#include <algorithm>
using namespace std;
int main () {
    string s1;
    getline(cin, s1);
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    if(s1 == s2) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
    return 0;
}