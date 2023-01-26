#include <iostream>
#include <vector>
#include <string>

using std::vector, std::string;

template <typename T, typename Y>
vector<T> transform(vector<T> A, Y f) {
    vector<T> result;
    for (auto &i : A) result.push_back(f(i));
    return result;
}

int square(int x) {
    return x*x;
}

int main() {
    vector<int> v1 = {1, 2, 3, 4};
    vector<int> v2 = transform(v1, &square);
    vector<string> v3 = {"1", "2", "3", "4", "5"};
    vector<string> v4 = transform(v3, [] (string x) {return "0x"+x;});
    return 0;
}

