#include "header.h"

int present(int number, int array[], int size){//This function will use a loop of the size given and search for the number and cout if it is in the array, otherwise it will say it isnt in the array.
  for (int i = 0; i < size; i++){
    if (number == array[i]){
      cout << number << " can be found at position " << i << endl;
      return i;
    }
  }
  cout << number << " was not found in the array" << endl;
  return -1;
}

pair<int,int> replace(int position, int NewNum, int array[], int currentPos){//The replace function will take a given index and number and replace the number at the given index with the input
  try{
    pair<int,int> replacements;

    if(position >= currentPos){
      string error = "Position not found in array";
      throw error;
    }
    replacements.second = array[position];
    array[position] = NewNum;
    replacements.first = array[position];
    cout << "The number " << replacements.second << " at " << position << " has been replaced by " << replacements.first << endl;
    return replacements;
  }
  catch(string a){
    cout << endl;
    cout << endl;
    cout << a << endl;
    cout << "Returning empty pair" << endl;
    pair<int,int> error;
    return error;
  }
}

void addNum(int number, int position, int array[]){//This function will add a new number to the end of the array. The array size is set to 200 so that there is plenty of space to add new items.
  try{
    if(position >= 200){
      string error = "Error max limit of array has been reached";
      throw error;
    }
    array[position] = number;
  }
    catch(string a){
      cout << endl;
      cout << endl;
      cout << a << endl;
    }
}
void removeNum(int position, int array[]){
  array[position] = 0;
}