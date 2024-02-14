#include "header.h"

int main() {
    ifstream inFile;
    string FileName;
    int numbers[200] = {};// The array has a max limit of 200 numbers to make removing and adding items in the array easily.
    cout << "Please enter the name of the file you would like to input into the array :";
    cin >> FileName;
    inFile.open(FileName);
  //This checks to see if the file input is valid and opens correctly.
    if (!inFile.is_open()){
      cout << "Input file invalid\n";
      abort();
    }
    // This section takes in each line one by one and inputs them into the array
    int InNum, currentPos = 0;
    while (inFile >> InNum){
      numbers[currentPos] = InNum;
      currentPos++;
    }
    while (true){ // This loop will allow the user to choose which function they want to use and give them the option to quit and end the program.
      try{
        string option;
        cout << "\n" << endl;
        cout << "\nWelcome to the main menu! Please select an option:" << endl;
        cout << "\n1: Check if a certain integer exists in the array if the number is present return the index where the number is present." << endl;
        cout << "\n2: Modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user." << endl;
        cout << "\n3: Add a new integer to the end of the array." << endl;
        cout << "\n4: Intake an index of an array and replace the value with either 0 or remove the integer altogether." << endl;
        cout << "\n5: Quit." << endl;
        cout << "\nEnter your option:" << endl;
        cin >> option;

        if (option == "1"){
          int search;
          cout << "Please enter the number you are searching for in the array --->";
          cin >> search;
          present(search,numbers,currentPos);
        }

        
        if (option == "2"){//This option will take the user input for the location and value to replace and run the replace function
          int location,replacement;
          string input;
          cout << "Please enter the location you would like to edit." << endl;
          cin >> input;
          location = stoi(input);
          cout << "Please enter the value you would like to replace it with." << endl;
          cin >> input;
          replacement = stoi(input);
          replace(location,replacement,numbers,currentPos);
        }

        if (option == "3"){//This option will add whatever number to the end of the array
          int number;
          string input;
          cout << "What number would you like to add to the end of the array? ";
          cin >> input;
          number = stoi(input);
          addNum(number, currentPos, numbers);
          cout << endl << input << " added to array" << endl;
          currentPos++;
        }

        if (option == "4"){//This option will replace a location in the array with 0.
          int location;
          string input;
          cout << "Please enter the location in the array you would like to replace with 0: ";
          cin >> input;
          location = stoi(input);
          removeNum(location, numbers);
        }

        if (option == "5"){//This will quit the program.
          abort();
        }

        else{ // This statement will catch invalid input for the function choice
          cout << endl;
          cout << endl;
          cout << "Please enter a valid choice" << endl;
          continue;
        }
      }
      catch (invalid_argument){
        cout << "\n\nError string input instead of integer, please try again." << endl;
        continue;
      }
    }
}