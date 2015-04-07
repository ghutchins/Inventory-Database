/**  
*  @file    database.h
*  @author  Georgina Hutchins (hutcgb12)
*  @date    03/18/2014  
*  @version 1.0  
*
*  @brief CSC 112, Lab 7, Inventory Database
*
*  @section DESCRIPTION
*
*  The image.h header file contains the function declarations
*  or prototypes that can be utilized in a program that 
*  maintains a company's inventory database.
*
*  @bug No known bugs
*
*/


#ifndef DATABASE_H
#define DATABASE_H
#define MAX_SIZE 2000
#include <iostream>
#include <fstream>
using namespace std;


int search(int& value, int list[MAX_SIZE], int n);


void storeValue(int value, int list[MAX_SIZE], int& n);


void deleteValue(int loc, int list[MAX_SIZE], int& n);


void writeFile(int value, int list[MAX_SIZE], int n);


#endif






