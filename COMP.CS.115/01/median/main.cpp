#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    cout << "Enter numbers: ";
    string input;
    double median;
    getline(cin, input);

    multiset<double> numbers_set;
    vector<double> numbers_vec;

    size_t start = 0;
    size_t end = input.find(' ', start);

    if (input.empty()){
        cout << "No input" << endl;
        return 1;
    }

    while (end != string::npos)
    {
        string part = input.substr(start, end - start);
        try {
            double value = stod(part);
            numbers_set.insert(value);
        } catch (invalid_argument&) {
            cout << "Not a double" << endl;
            return 1;
        }
        start = end + 1;
        end = input.find(' ', start);
    }

    if (start < input.size()) {
        try {
            double value = stod(input.substr(start));
            numbers_set.insert(value);
        } catch (invalid_argument&) {
            cout << "Not a double" << endl;
            return 1;
        }
    }

    for (double number : numbers_set){
        numbers_vec.push_back(number);
    }

    int sizehalf = numbers_vec.size()/2;

    if (numbers_vec.size() % 2 == 1){
        median = numbers_vec[sizehalf+0.5];
        cout << "Median: " << median << endl;
    }

    else{
        median = (numbers_vec[sizehalf-1]+numbers_vec[sizehalf])/2;
        cout << "Median: " << median << endl;
    }

    return 0;
}
