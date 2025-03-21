#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>

bool cmp(std::pair<int, int> &a, std::pair<int, int> &b) {
  return (a.first + a.second) < (b.first + b.second);
}

int main() {
  size_t n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n);
  for (auto &p : a) {
    std::cin >> p.first >> p.second;
  }

  sort(a.begin(), a.end(), cmp);
  long long count = 0, all = 0;

  for (auto &p : a) {
    if (all <= p.second) {
      all += p.first;
      ++count;
    }
  }
  std::cout << count << '\n';
}
