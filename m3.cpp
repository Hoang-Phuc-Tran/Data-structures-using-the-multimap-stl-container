/*
 * Project:	    Major 3
 * Author:	    Hoang Phuc Tran
 * Student ID:  8789102
 * Date:		July 28, 2022
 * Description: a program that takes in information about flights and stores the destination, date
				and fare in a multimap STL container to be displayed.
 */
#include <stdio.h>
#include <iomanip>
#include <string>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <cstring>
#include <string>
using namespace std;


// Prototypes
void printfMapFare(multimap <pair<double, string>, string> myMap);
void printfMapDest(multimap < pair<string, string>, double> myMap);



int main()
{
	// a map sorted by destination
	typedef multimap < pair<string, string>, double> myMapDest;
	myMapDest mapDest;

	// a pair that contains a 'destination' string and a 'date' string, this pair will be put into a map sorted by destination
	pair<string, string> obj;

	// a map sorted by fare
	typedef multimap < pair<double, string>, string > myMapFare;
	myMapFare mapFare;

	// a pair that contains a 'fare' double and a 'date' string, this pair will be put into a map sorted by fare
	pair<double, string> obj2;

	bool check = true;

	while (check)
	{
		// a string contains the destination of a flight
		string destination;
		// a string contains the date of a flight
		string date;
		// a string contains the fare of a flight
		string stringFare;
		double fare = 0;

		cout << "Destination: ";
		// Get the destination from a user
		getline(cin, destination);
		// Check if the string contains '.' character
		if (destination == ".")
		{
			break;
		}

		cout << "Date: ";
		// Get the date from a user
		getline(cin, date);
		// Check if the string contains '.' character
		if (date == ".")
		{
			break;
		}

		cout << "Fare: ";
		// Get the fare from a user
		getline(cin, stringFare);
		// Check if the string contains '.' character
		if (stringFare == ".")
		{
			break;
		}
		// convert string to double
		fare = atof(stringFare.c_str());

		// Put the fare an destination into the pair 
		obj2.first = fare;
		obj2.second = destination;

		// Insert the flight's information into the map sorted by fare
		mapFare.insert(make_pair(obj2, date));

		// Put the date an destination into the pair
		obj.first = destination;
		obj.second = date;

		// Insert the flight's information into the map sorted by destination
		mapDest.insert(make_pair(obj, fare));
	}

	cout << "\nSorted By Fare:" << endl;

	// Display all the information of map sorted by fare
	printfMapFare(mapFare);

	cout << "Sorted By Destination:" << endl;

	// Display all the information of map sorted by destination
	printfMapDest(mapDest);

	// a string contains a destination to search for
	string dest;
	// a string contains a date to search for
	string date1;
	// a string contains a fare to search for
	string strFare;
	// a double contains a fare to search for
	double newFare;

	cout << "Destination: ";
	// Get the destination from a user
	getline(cin, dest);
	cout << "Date: ";
	// Get the date from a user
	getline(cin, date1);

	// Declare an interator
	myMapDest::iterator it;

	// Find the flight that contains in the map sorted by destination
	it = mapDest.find(make_pair(dest, date1));

	// Check if we found the flight
	if (it != mapDest.end())
	{
		cout << "Old fare: ";
		printf("$%.2lf\n", it->second);

		cout << "\nNew fare: ";
		// Get the new fare from the user
		getline(cin, strFare);
		// convert string to double
		newFare = atof(strFare.c_str());

		// Check if the new fare and the old fare is equal
		if (it->second != newFare)
		{
			it->second = newFare;
		}
		else
		{
			cout << "Old fare and new fare are identical." << endl;
		}

		// Declare an iterator
		myMapFare::iterator it2;

		// Loop to find the filght that contains in the map sorted by fare
		for (it2 = mapFare.begin(); it2 != mapFare.end(); ++it2)
		{
			// If we found the flight 
			if (it2->first.second == dest && it2->second == date1)
			{
				break;
			}
		}

		// Check if we found the flight
		if (it2 != mapFare.end())
		{
			// a string contains a destination
			string dest;
			// a string contains a date
			string date;

			// Declare a pair
			pair<double, string> obj3;

			// We save the information of the flight
			dest = it2->first.second;
			date = it2->second;

			// Put the date and the destination into the pair
			obj3.first = newFare;
			obj3.second = dest;

			// Then we erase the flight we had found
			mapFare.erase(it2);

			// Insert a new flight into the map sorted by fare
			mapFare.insert(make_pair(obj3, date));
		}

	}
	// If not found the flight
	else
	{
		cout << "Flight not found:" << endl;
	}


	cout << "\nSorted By Fare:" << endl;

	// Display all the information of map sorted by fare
	printfMapFare(mapFare);

	cout << "Sorted By Destination:" << endl;

	// Display all the information of map sorted by destination
	printfMapDest(mapDest);


	return 0;
}


/*
* Function: printfMapFare()
* Description : This function will prints all of the information contained within the map sorted by fare
* Parameters : one parameter - (a map sorted by fare).
* Returns : NONE
*/
void printfMapFare(multimap <pair<double, string>, string> myMap)
{
	typedef multimap <pair<double, string>, string> myMapFare;

	// Use an iterator to loop display
	for (myMapFare::const_iterator it = myMap.begin(), end = myMap.end(); it != end; ++it)
	{
		printf("%-35s", (it->first.second).c_str());
		printf("%-35s", (it->second).c_str());
		printf("$%-35.2lf\n", it->first.first);
	}
	printf("\n");
}

/*
* Function: printfMapDest()
* Description : This function will prints all of the information contained within the map sorted by destination
* Parameters : one parameter - (a map sorted by destination).
* Returns : NONE
*/
void printfMapDest(multimap < pair<string, string>, double> myMap)
{
	typedef multimap < pair<string, string>, double> myMapDest;

	// Use an iterator to loop display
	for (myMapDest::const_iterator it = myMap.begin(), end = myMap.end(); it != end; ++it)
	{
		printf("%-35s", (it->first.first).c_str());
		printf("%-35s", (it->first.second).c_str());
		printf("$%-35.2lf\n", it->second);
	}
	printf("\n");
}