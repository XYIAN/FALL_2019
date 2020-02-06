// A sample program to demonstrate the map container.
// Original code is "Program 17-11" of Gaddis Book and
// updated by Dr. Byun for CST238 and 370.
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    // Create a map containing employee IDs and names.
    map<int, string> employees = 
        { {101,"Chris Jones"}, {102,"Jessica Smith"},
          {103,"Amanda Stevens"},{104,"Will Osborn"} };
   
    // [] Operator to add a new pair or update an existing one.
    employees[105] = "Alice Otter";
    employees[104] = "Bob Otter";
    
    // Create an iterator for the map.
    map<int, string>::iterator iter;
   
    // Use the iterator to display each element in the map.
    for (iter = employees.begin(); iter != employees.end(); iter++)
    {
        cout << "ID: " << iter->first 
             << "\tName: " << iter->second << endl;
    }
    
    // Add a new element with the insert() member function
    employees.insert(make_pair(99, "Monica Otter"));
    employees.erase(105);
    // The key 105 already exist. insert() will fail in this case.
    employees.insert(make_pair(105, "Error Otter"));  

    // Delete the employee with ID 102.
    employees.erase(102);

    // Use the iterator to display each element in the map.
    cout << "\n===== Another way to display the elements in the map =====\n";
    for (auto element : employees)
    {
       cout << "ID: " << element.first 
            << "\tName: " << element.second << endl;
    }

    return 0;
}
