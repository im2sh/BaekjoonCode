#include <iostream>
#include <stack>
#include <string>
 
using namespace std;
 
int main()
{
	int n;
	string s;
	cin >> n >> s;
	double arr[26] = { 0, };
    stack<double> stack;
    
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			stack.push(arr[s[i] - 'A']);
		}
		else if (!stack.empty()) {
			double result = stack.top();
			stack.pop();
			if (s[i] == '+') {
				result = stack.top() + result;
			}
			else if (s[i] == '-') {
				result = stack.top() - result;
			}
			else if (s[i] == '*') {
				result = stack.top() * result;
			}
			else if (s[i] == '/') {
				result = stack.top() / result;
			}
			stack.pop();
			stack.push(result);
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << stack.top() << "\n";
 
	return 0;
}