/**************************
 *Cameron Kimner
 *CPSC 1021, section 2, F20
 *ckimner@clemson.edu
 *Nushrat and Evan
 **************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <stdlib.h>

using namespace std;


typedef struct Employee{
	string lastName;
	string firstName;
	int birthYear;
	double hourlyWage;
}employee;

bool name_order(const employee& lhs, const employee& rhs);
int myrandom (int i) { return rand()%i;}


int main(int argc, char const *argv[]) {
  // IMPLEMENT as instructed below
  /*This is to seed the random generator */
  srand(unsigned (time(0)));


  /*Create an array of 10 employees and fill information from standard input with prompt messages*/
  employee arr[10];

  //promts user for info on 10 employees
  for(int i = 0; i < 10; i++){
    cout << "Enter a first name for employee #" << i+1 << endl;
    cin >> arr[i].firstName;
    cout << "Enter a last name for employee #" << i+1 << endl;
    cin >> arr[i].lastName;

    cout << "Enter a birth year for employee #" << i+1 << endl;
    cin >> arr[i].birthYear;

    cout << "Enter an hourly wage for employee #" << i+1 << endl;
    cin >> arr[i].hourlyWage;
  }


  /*After the array is created and initialzed we call random_shuffle() see the
   *notes to determine the parameters to pass in.*/
  //randomizes arr using myrandom
  random_shuffle(&arr[0], &arr[10], myrandom);

   /*Build a smaller array of 5 employees from the first five cards of the array created
    *above*/
  //smaller arr of size 5
  employee smallArr[5];
  //sets small array to first 5 of randomized original array
  for(int i = 0; i < 5; i++){
    smallArr[i] = arr[i];
  }


  /*Sort the new array.  Links to how to call this function is in the specs
    *provided*/
   //sorts smallArr using name_order sorting
  sort(&smallArr[0], &smallArr[5], name_order);


    /*Now print the array below */
  cout << endl << "Printing Employees: " <<endl;
  for(employee n: smallArr){
    cout << setw(10) << right << n.lastName <<", " << n.firstName << endl;
    cout << setw(6) << right << n.birthYear << endl;
    cout << setw(9) << right << showpoint << setprecision(2) << fixed << n.hourlyWage << endl << endl;
  }

  //main return statement
  return 0;
}



/*This function will be passed to the sort funtion. Hints on how to implement
* this is in the specifications document.*/

//sort() sorting algorithim, returns true if left last name is alphabetically first
bool name_order(const employee& lhs, const employee& rhs) {
  // checks if left last name is alphbetically smaller than right last name
  return lhs.lastName < rhs.lastName;
}