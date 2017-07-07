#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

bool IsSorted(const vector<int> &numbers) {
  for (auto iter = cbegin(numbers); iter != cend(numbers) - 2; iter++) {
    if (iter > iter + 1)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {

  // read input
  int n;
  cin >> n;

  string input;
  getline(cin, input);
  istringstream iss(input);

  vector<int> numbers, sorted;
  int val = 0;
  while (iss >> val) {
    numbers.push_back(val);
  }

  if (IsSorted(numbers)) {
    cout << "yes" << endl;
    return 0;
  }
                                                                       
  // costly. Do we need to do this?
  copy(begin(numbers), end(numbers), begin(sorted));
 
  // check left
  int lIdx = 0, rIdx = 0;
  for (int i = 0; i < numbers.size(); ++i) {
    if (numbers[i] != sorted[i]) {
      lIdx = i;
      break;
    }
  }                                                                                                                                  

  // check right
  for (int i = numbers.size() - 1; i >= 0; --i) {
    if (numbers[i] != sorted[i]) {
      rIdx = i;
      break;
    }
  }
    
  swap(numbers[lIdx], numbers[rIdx]);
  if (IsSorted(numbers)) {
    cout << "swap " << lIdx << ", " << rIdx << endl;
    return 0;
  }
}
