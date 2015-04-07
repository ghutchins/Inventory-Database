/**  
*  @file    main.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    03/18/2014  
*  @version 1.0  
*
*  @brief CSC 112, Lab 7, Inventory Database
*
*  @section DESCRIPTION
*
*  This program maintains a company's inventory database
*  where each product has a unique ID number. The program
*  can remove duplicate entries, sort entires, and add or
*  delete ID numbers from the database.
*
*  @bug No known bugs
*
*/



#include <iostream>
#include <fstream>
#include "database.h"
using namespace std;



int main()
{

	int list[MAX_SIZE];	///< Database array
	int value;		///< ID number values in the database
	int n = 0;		///< Number of entries in the array (logical size)
	char action;		///< Letter indicating action-code from file
	int loc;		///< Location of a deletion from the database  
	

	fstream inFile("invent.dat", ios :: in);

	while(inFile >> value)
	{
		if(search(value, list, n) == -1)
			storeValue(value, list, n);
	}

	inFile.close();

	cout << "Database has " << n << " ID numbers" << '\n';
	cout << "----------------------------------------------------" << '\n';

	fstream upFile("update.dat", ios :: in);

	while(upFile >> action >> value) 
	{
		if(action == 'a' || action == 'A')
		{
			if(search(value, list, n) == -1)
				storeValue(value, list, n);
		}
		else if(action == 'd' || action == 'D')
		{
			loc = search(value, list, n);
			if(loc != -1)
				deleteValue(loc, list, n);
		}

	}
	
	cout << "Updated database" << '\n';
	cout << "Database has " << n << " ID numbers" << '\n';

	writeFile(value, list, n);


	return 0;

}



