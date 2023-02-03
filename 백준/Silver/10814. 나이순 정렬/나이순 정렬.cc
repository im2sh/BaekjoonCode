#include <iostream>
#include <algorithm>
using namespace std;

struct people
{
    int age;
    string name;
};

bool compare(const people& now, const people& last)
{
    if(now.age != last.age) return now.age < last.age;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    people people[100001];

    for (int i = 0; i < N; i++)
        cin >> people[i].age >> people[i].name;

    stable_sort(people, people + N, compare);

    for (int i = 0; i < N; i++)
        cout << people[i].age << " " << people[i].name << "\n";
}