// A sample program to conduct the sorting in a vector.
// Written by Dr. Byun for CST238/370.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> numbers = {40, 70, 10, 90, 50, 20, 99, 30, 80, 60};

    cout << "\n===== Unsorted Order =====\n";
	for (int element: numbers)
	{
		cout << element << ' ';
	}
	cout << endl;

    // Call the sort() function of STL
    sort(numbers.begin(), numbers.end());

    cout << "\n===== Sorted Order =====\n";
	for (int element: numbers)
	{
		cout << element << ' ';
	}
	cout << endl;
    cout << "Enter value to search:" ;
    int input; 
    cin >> input; 
    if(binary_search(numbers.begin(), numbers.end(), input) == true)
    {
        cout << "found";
    }

    return 0;
}