#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &input, string delimiter) {
  auto start = 0;
  auto end = input.find(delimiter);

  vector<string> result;
  while (end != string::npos) {
    result.push_back(input.substr(start, end - start));
    start = end + delimiter.size();
    end = input.find(delimiter, start);
  }

  result.push_back(input.substr(start));
  return result;
}

int main() {
  string str = "apple, banana, orange, grape";
  vector<string> fruits = split(str, ", ");

  for (const string &fruit : fruits) {
    cout << fruit << '\n';
  }

  return 0;
}