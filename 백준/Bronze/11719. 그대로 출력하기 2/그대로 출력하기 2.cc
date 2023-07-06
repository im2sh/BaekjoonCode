#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string s; 
    int i;
    while(i < 100)
    {
        getline(cin, s);

        cout << s << "\n";
        
        i++;
    }

    return 0;
}