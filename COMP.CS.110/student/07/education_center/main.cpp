/* Education center´
 *
 * Desc:
 * This program reads education center data from a user-specified file,
 * sorts it alphabetically, and provides a browsing interface until the user quits.
 * Data includes courses with names, themes, and enrollments.
 * Each education center has themes, each theme has courses.
 * The program loads data, sorts it, and enters a browsing loop.
 * Commands: list all locations, list themes in a location,
 * list courses and their enrollments under a theme in a location, list available courses,
 * list courses under a theme across all locations, identify most popular theme(s).
 * Informative errors are raised if problems occur.
 *
 * Program authors:
 *
 * Name: Antton Alivuotila
 * Student number: 151259218
 * UserID: bvanal
 * E-Mail: antton.alivuotila@tuni.fi
 *
 * Name: Jenna Pham
 * Student number: 152048567
 * UserID: bhjeph
 * E-Mail: jenna.pham@tuni.fi
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <set>

// Declaring Course for use in education center structure
struct Course;
using namespace std;

// Aliases
using Themes = map<string, vector<Course>>;
using Education_Center = pair<string, Themes>;

// Error messages
const string FILE_NOT_OPENED = "Error: the input file cannot be opened";
const string EMPTY_FIELD = "Error: empty field";
const string UNKNOWN_LOCATION = "Error: unknown location";
const string UNKNOWN_LOCATION_NAME = "Error: unknown location name";
const string UNKNOWN_THEME = "Error: unknown theme";
const string UNKNOWN_COMMAND = "Error: Unknown command: ";
const string ERROR_IN_COMMAND = "Error: error in command ";

// Course object - variables and comparison operator
struct Course
{
    // Variables
    string name;
    string theme;
    int enrollments;

    // Comparison operator
    bool operator<(const Course& other) const
    {
        return name < other.name;
    }
};

// Indexes for data types in a structure for line reading
enum Data_Field {LOCATION, THEME, COURSE, ENROLLED_AMOUNT};

// Splits a string into multiple parts
// s : string to be split
// delimiter : character where the string is split
// ignore_empty : skips empty parts if true
// returns vector<string> containing all parts
vector<string> split(const string& s, const char delimiter, bool ignore_empty = false)
{
    vector<string> result;
    string tmp = s;

    while(tmp.find(delimiter) != string::npos)
    {
        string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());

        // if new part is empty and should be ignored
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    // if new part is empty and should be ignored
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

// Removes quotes and combines parameters if necessary
// command : command inputted by the user
// required_parameters : parameters wanted for the next function
// returns nothing
void join_quotes(vector<string>& command, unsigned int required_parameters)
{
    // If the number of parameters matches the required number
    if ( command.size() == required_parameters )
    {
        // Get the last parameter
        string& keyword = command.back();
        // If the parameter is enclosed in quotes
        if ( keyword.at(0) == '"' )
        {
            // Remove the quotes
            keyword = keyword.substr(1, keyword.length() - 2);
        }
    }
    // If the number of parameters is one more than required
    else
    {
        // Get the second to last parameter
        string& keyword = command.at(command.size()-2);
        // If the parameter is enclosed in quotes
        if ( keyword.at(0) == '"' )
        {
            // Combine it with the last parameter
            keyword = keyword + " " + command.back();
            // Remove the quotes
            keyword = keyword.substr(1, keyword.length() - 2);
            // Remove the last parameter from the command
            command.pop_back();
        }
    }
}

// Corrects enrollments if new course already exists
// existing_themes : themes already in the location
// new_course : newest course to be added
// returns boolean indicating if values were corrected.
bool enrollments_corrected(Themes& existing_themes, const Course& new_course)
{
    // Iterate through courses under the theme
    for ( Course& course : existing_themes.at(new_course.theme) )
    {
        // If the course already exists
        if ( course.name == new_course.name )
        {
            // Update enrollments
            course.enrollments = new_course.enrollments;
            return true;
        }
    }
    return false;
}

// Creates a course object with gathered data
// data_fields : data gathered from the line in turn
// returns course object
Course create_course(const vector<string>& data_fields)
{
    Course new_course;
    // If enrollment status is "full"
    if ( data_fields.at(ENROLLED_AMOUNT) == "full" )
    {
        // Create course with maximum enrollments
        new_course = {data_fields.at(COURSE), data_fields.at(THEME), 50};
    }
    else
    {
        // Create course with specified enrollments
        new_course = {data_fields.at(COURSE), data_fields.at(THEME), stoi(data_fields.at(ENROLLED_AMOUNT))};
    }
    return new_course;
}

// Finds index of location in education centers vector
// education_centers : structure containing education centers
// new_location : target location for index
// returns the found index or -1 if not found.
int find_location_index(const vector<Education_Center>& education_centers, const string& new_location)
{
    // Iterate through education centers
    for ( size_t i = 0; i < education_centers.size(); ++i )
    {
        // If location matches target location
        if ( education_centers.at(i).first == new_location )
        {
            return i;
        }
    }
    // Location not found
    return -1;
}

// Processes gathered data and inserts it into the structure appropriately
// education_centers : structure containing education centers
// data_fields : data gathered from the line in turn
// returns nothing
void read_line(vector<Education_Center>& education_centers, const vector<string>& data_fields)
{
    // Create a new course object
    Course new_course = create_course(data_fields);
    // Find the index of the location
    int location_index = find_location_index(education_centers, data_fields.at(LOCATION));

    // If the location already exists
    if ( location_index != -1 )
    {
        Themes& existing_themes = education_centers.at(location_index).second;
        string existing_location = education_centers.at(location_index).first;

        // If the theme already exists
        if ( existing_themes.find(new_course.theme) != existing_themes.end() )
        {
            // If the course doesn't already exist
            if ( not enrollments_corrected(existing_themes, new_course) )
            {
                // Adds the course
                existing_themes.at(new_course.theme).push_back(new_course);
            }
        }
        // If the theme does not exist
        else
        {
            // Add it along with the course
            existing_themes.insert({ new_course.theme, {new_course} });
        }
    }
    // If the location does not exist
    else
    {
        // Add it along with the theme and course
        education_centers.push_back({data_fields.at(LOCATION), {{ new_course.theme, {new_course}}}});
    }
    return;
}

// Requests file name, processes each line into structure, handles errors.
// education_centers : structure containing education centers
// returns boolean indicating if an error was raised
bool read_file(vector<Education_Center>& education_centers)
{
    // Request input file name from the user
    string input_file_name;
    cout << "Input file: ";
    getline(cin, input_file_name);

    // Open the input file
    ifstream input_file(input_file_name);

    // If the file isn't opened successfully
    if ( not input_file )
    {
        cout << FILE_NOT_OPENED << endl;
        return false;
    }

    else
    {
        string line;
        vector<string> data_fields;

        // Read each line from the file
        while ( getline(input_file, line) )
        {
            // Split the line into data fields
            data_fields = split(line, ';', true);

            // If all data fields aren't present
            if ( data_fields.size() != 4 )
            {
                cout << EMPTY_FIELD << endl;
                return false;
            }
            else
            {
                // Process the line and insert data into the structure
                read_line(education_centers, data_fields);
            }
        }
        return true;
    }
}

// Sorts all data in the structure alphabetically.
// education_centers : structure containing education centers
// returns nothing
void sort_data(vector<Education_Center>& education_centers)
{
    // Sort education centers alphabetically
    sort(education_centers.begin(), education_centers.end());

    // Sort themes and courses within each education center
    for (Education_Center& education_center: education_centers)
    {
        for (auto& theme: education_center.second)
            sort(theme.second.begin(), theme.second.end());
    }
}

// Prints known locations alphabetically, each on a separate line.
// education_centers : structure containing education centers
// returns nothing
void print_locations(const vector<Education_Center>& education_centers)
{
    // Print locations
    for (const Education_Center& education_center: education_centers)
    {
        cout << education_center.first << endl;
    }
}

// Prints themes in given location alphabetically, each on a separate line.
// education_centers : structure containing education centers
// location :
// returns nothing
void print_themes_in_location(const vector<Education_Center>& education_centers, string location)
{
    // Find the index of the given location
    int location_index = find_location_index(education_centers, location);

    // If location is not found
    if ( location_index == -1 )
    {
        cout << UNKNOWN_LOCATION << endl;
    }
    else
    {
        // Print themes
        for (const auto& theme: education_centers.at(location_index).second)
        {
            cout << theme.first << endl;
        }
    }
}

// Prints all courses and enrollments in specific location and theme, alphabetically.
// education_centers : structure containing education centers
// returns nothing
void print_courses(const vector<Education_Center>& education_centers, string location, string theme)
{
    // Find the index of the given location
    int location_index = find_location_index(education_centers, location);

    // If location is not found
    if ( location_index == -1 )
    {
        cout << UNKNOWN_LOCATION_NAME << endl;
        return;
    }

    Themes existing_themes = education_centers.at(location_index).second;

    // If theme is not found for the location
    if ( existing_themes.find(theme) == existing_themes.end() )
    {
        cout << UNKNOWN_THEME << endl;
    }
    else
    {
        // Print courses for the theme
        for (const Course& course: education_centers.at(location_index).second.at(theme))
        {
            // If course is full
            if ( course.enrollments == 50 )
            {
                cout << course.name << " --- " << "full" << endl;
            }
            else
            {
                cout << course.name << " --- " << course.enrollments << " enrollments" << endl;
            }
        }
    }
}

// Prints locations, themes, and names of available courses alphabetically
// sorted by location, then theme, then course name.
// education_centers : structure containing education centers
// returns nothing
void print_available(const vector<Education_Center>& education_centers)
{
    // Iterate through each education center
    for (const Education_Center& education_center: education_centers)
    {
        // Iterate through each theme in the education center
        for (const auto& theme: education_center.second)
        {
            // Iterate through each course in the theme
            for (const Course& course: theme.second)
            {
                // If course is available
                if ( course.enrollments != 50 )
                {
                    // Print location, theme, and course name
                    cout << education_center.first << " : "
                         << course.theme << " : " << course.name << endl;
                }
            }
        }
    }
}

// Prints all courses under specified theme in all locations.
// education_centers : structure containing education centers
// returns nothing
void print_courses_in_theme(const vector<Education_Center>& education_centers, string theme)
{
    // Unique course names
    set<string> course_names;
    // Theme is found in any location
    bool theme_is_unknown = true;

    // Iterate through each education center
    for (const Education_Center& education_center: education_centers)
    {
        Themes existing_themes = education_center.second;
        // If the specified theme exists in the current education center
        if ( existing_themes.find(theme) != existing_themes.end() )
        {
            theme_is_unknown = false;
            // Iterate through courses under the specified theme
            for (const Course& course: existing_themes.at(theme))
            {
                // Add course name to set
                course_names.insert(course.name);
            }
        }
    }

    // If specified theme isn't found in any location
    if ( theme_is_unknown )
    {
        cout << UNKNOWN_THEME << endl;
        return;
    }
    // Print all unique course names
    for (const string& course_name: course_names)
    {
        cout << course_name << endl;
    }
}

// Inserts theme enrollments in all locations into a map.
// education_centers : structure containing education centers
// theme_enrollment_map: map for theme enrollments
// returns nothing
void insert_values(const vector<Education_Center>& education_centers, map<string, unsigned int>& theme_enrollment_map)
{
    // Iterate through each education center
    for (const Education_Center& education_center: education_centers)
    {
        // Iterate through each theme in the education center
        for (const auto& theme: education_center.second)
        {
            // Initialize enrollment count for the current theme
            theme_enrollment_map.insert({theme.first, 0});

            // Iterate through each course under the current theme
            for (const Course& course: theme.second)
            {
                // Add enrollments to the count
                theme_enrollment_map.at(theme.first) += course.enrollments;
            }
        }
    }
}

// Prints the most popular theme(s) based on total enrollments.
// education_centers : structure containing education centers
// returns nothing
void print_favorite_theme(const vector<Education_Center>& education_centers)
{
    map<string, unsigned int> theme_enrollment_map;

    // Insert theme enrollments
    insert_values(education_centers, theme_enrollment_map);

    // Enrollment record and corresponding theme(s)
    unsigned int enrollment_record = 0;
    vector<string> themes_to_print;

    // Find theme with highest enrollment
    for (const auto& theme_enrollment_pair : theme_enrollment_map)
    {
        // If record is broken
        if (theme_enrollment_pair.second > enrollment_record)
        {
            // Update highest enrollment
            themes_to_print.clear();
            themes_to_print.push_back(theme_enrollment_pair.first);
            enrollment_record = theme_enrollment_pair.second;
        }
        // If record is tied
        else if (theme_enrollment_pair.second == enrollment_record)
        {
            // Add second theme to record
            themes_to_print.push_back(theme_enrollment_pair.first);
        }
    }

    // Sort themes alphabetically
    sort(themes_to_print.begin(), themes_to_print.end());

    // Print enrollment record and the corresponding theme(s)
    cout << enrollment_record << " enrollments in themes" << endl;
    for (const string& theme: themes_to_print)
    {
        cout << "--- " << theme << endl;
    }
}

// Asks for commands to browse education centers until they choose to quit.
// education_centers : structure containing education centers
// returns nothing
void browse_data(const vector<Education_Center>& education_centers)
{
    string command_input;
    vector<string> command;

    // Loop until user enters "quit"
    while ( command_input != "quit" )
    {
        // Get user input
        cout << "> ";
        getline(cin, command_input);
        command = split(command_input, ' ');

        // Find correct command
        if ( command.at(0) == "locations" )
        {
            if ( command.size() != 1 )
            {
                cout << ERROR_IN_COMMAND << command.at(0) << endl;
            }
            else
            {
                print_locations(education_centers);
            }
        }
        else if ( command.at(0) == "themes_in_location" )
        {
            if ( command.size() != 2 )
            {
                cout << ERROR_IN_COMMAND << command.at(0) << endl;
            }
            else
            {
                print_themes_in_location(education_centers, command.at(1));
            }
        }
        else if ( command.at(0) == "courses" )
        {
            join_quotes(command, 3);
            if ( command.size() != 3 )
            {
                cout << ERROR_IN_COMMAND << command.at(0) << endl;
            }
            else
            {
                print_courses(education_centers, command.at(1), command.at(2));
            }
        }
        else if ( command.at(0) == "available" )
        {
            if ( command.size() != 1 )
            {
                cout << ERROR_IN_COMMAND << command.at(0) << endl;
            }
            else
            {
                print_available(education_centers);
            }
        }
        else if ( command.at(0) == "courses_in_theme" )
        {
            join_quotes(command, 2);
            if ( command.size() != 2 )
            {
                cout << ERROR_IN_COMMAND << command.at(0) << endl;
            }
            else
            {
                print_courses_in_theme(education_centers, command.at(1));
            }
        }
        else if ( command.at(0) == "favorite_theme" )
        {
            if ( command.size() != 1 )
            {
                cout << ERROR_IN_COMMAND << command.at(0) << endl;
            }
            else if ( education_centers.empty() )
            {
                cout << "No enrollments" << endl;
            }
            else
            {
                print_favorite_theme(education_centers);
            }
        }
        else if ( command.at(0) == "quit" )
        {
            continue;
        }
        else
        {
            cout << UNKNOWN_COMMAND << command.at(0) << endl;
        }
    }
}

// Reads education center data from file, sorts alphabetically, allows browsing until user quits.
int main()
{
    vector<Education_Center> education_centers;

    // If reading the file inputted is unsuccesful
    if ( not read_file(education_centers) )
    {
        return EXIT_FAILURE;
    }

    // Sorts the data into an alphabetical order
    sort_data(education_centers);

    // Runs the program until the user quits.
    browse_data(education_centers);
    {
        return EXIT_SUCCESS;
    }
}
