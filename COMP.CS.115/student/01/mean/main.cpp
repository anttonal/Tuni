#include <iostream>
#include <vector>

using namespace std;

// Splits the given string into several strings, by using the given delimiter
// as a separator.
// Returns the splitted string as a vector such that each string part is an
// element of the vector.
// User can specify if empty parts will be ignored or not.
vector<string> split(const string& str, const char delimiter,
                     bool ignore_empty = false)
{
    vector<string> result;
    string tmp = str;

    while(tmp.find(delimiter) != string::npos)
    {
        string word = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter) + 1, tmp.size());
        if(not (ignore_empty and word.empty()))
        {
            result.push_back(word);
        }

    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}


double mean(const string& input)  // Don't change the function definition!
{
    // TODO: Write mean function code here.
    // Must throw invalid_argument and domain_error on applicaple errors
    vector<double> numbers_vec;
    size_t start = 0;
    size_t end = input.find(' ', start);

    if (input.empty()){
        throw domain_error("No numbers");
    }

    while (true)
    {
        string part = input.substr(start, end - start);
        try
        {
            double value = stod(part);
            numbers_vec.push_back(value);
        }
        catch (invalid_argument&)
        {
            throw invalid_argument("stod");
        }

        if (end == string::npos) {
            break;
        }

        start = end + 1;
        end = input.find(' ', start);
    }

    double sum = 0.0;
    for (double number : numbers_vec)
    {
        sum += number;
    }

    return sum / numbers_vec.size();
}


// Don't remove! Needed for tests.
#ifndef MEAN_TEST
// Don't remove! Needed for tests.
// Main function
int main()
{

    string input;
    double mean_value;
    cout << "Enter numbers: ";
    getline(cin, input);


    try {
        mean_value = mean(input);
        cout << "Mean: " << mean_value << endl;
    }
    catch (const invalid_argument& ex) {
        cout << "invalid_argument: " << ex.what() << endl;
    }
    catch (const domain_error& ex) {
        cout << "domain_error: " << ex.what() << endl;
    }


    return 0;
}
// Don't remove! Needed for tests.
#endif // MEAN_TEST
// Don't remove! Needed for tests.
