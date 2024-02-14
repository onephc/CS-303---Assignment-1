#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int present(int number, int array[], int size); //This function checks if a certain integer exists in the array and if the number is present, returns the index where the number is present.
pair<int,int> replace(int position, int NewNum, int array[], int currentPos); //Modifies the value of an integer when called with the index of the integer in the array and returns the new value and old value back to the user.
void addNum(int number, int position, int array[]);//Add a new integer to the end of the array.
void removeNum(int position, int array[]);//Intakes an index of an array and replaces the value with either 0 or removes the integer altogether.