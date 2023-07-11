#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x, y; cin >> x >> y;

  for (int year = x; year <= y; year++) {
    if (!((year - x) % 4) && !((year - x) % 2) && !((year - x) % 3) && !((year - x) % 5))
      cout << "All positions change in year " << year << "\n";
  }

  return 0;
}