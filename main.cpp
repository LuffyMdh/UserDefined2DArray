#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void showMenu(int x,int y);
void inputArray(int** userArray,int x,int y);
void showMatrix(int** userArray,int x,int y);
void matrixSum(int** userArray,int x,int y);
void rowWiseSum(int** userArray,int x,int y);
void colWiseSum(int** userArray,int x,int y);
void transposeMatrix(int** userArray,int x,int y);

int main()
{
	string errorMessage1 = "Please input elements into the array before proceed!"; // Store error message in string variable
	int userChoice; // User choice variable
	int x,y; // Variable for row and column based on user input
	bool checkArray = 1; // Make sure user input elements into the array
	int** userArray; // Declare pointer to pointer integer type
    
    
    do{
        cout << "Please enter row number :";
        cin>> x;
        if(x <= 0){ // If user enters less than 0, this code will execute
            cout << "Please enter valid number! Greater than 0" << endl;
        }
    }while(x <= 0); // Will keep loop if user enters less than 0
    
	do{

        cout << "Please enter column number :";
        cin >> y;
        if(y <= 0){ // If user enters less than 0, this code will execute
            cout << "Please enter valid number! Greater than 0" << endl;
        }
    }while(x <= 0); // Will keep loop if user enters less than 0
    
    userArray = new int*[x]; // Allocates memory space based on X
    
    for(int i=0;i<x;i++){
        userArray[i] = new int[y]; // Allocates memory space based on Y into X[i]
    }
	
	do{
		showMenu(x,y); // Call function menu
		cin >> userChoice; // User input choice
		
		switch(userChoice){ // Direct to case number based on userChoice variable
			case 1: // If userChoice is 1
				inputArray(userArray,x,y); // Call function inputArray
				checkArray = 0;
				break;

			case 2: // If userChoice is 2
			if(checkArray){
				cout << errorMessage1 << endl;
				break;
			}
			else{
				showMatrix(userArray,x,y); // Call function showMatrix
				break;
			}
				
			case 3: // If userChoice is 3
			if(checkArray){
				cout << errorMessage1 << endl;
				break;
			}
			else{
				matrixSum(userArray,x,y); // Call function matrixSum
				break;
			}
				
			case 4: // If userChoice is 4
			if(checkArray){
				cout << errorMessage1 << endl;
				break;
			}
			else{
				rowWiseSum(userArray,x,y); // Call function rowWiseSum
				break;
			}
				
			case 5: // If userChoice is 5
			if(checkArray){
				cout << errorMessage1 << endl;
				break;
			}
			else{
				colWiseSum(userArray,x,y); // Call function colWiseSum
				break;
			}
				
			case 6: // If userChoice is 6
			if(checkArray){
				cout << errorMessage1 << endl;
				break;
			}
			else{
				transposeMatrix(userArray,x,y); // Call function tranposeMatrix
				break;
			}
				
			case 7: // If userChoice is 7
				break;
				
			default: // If userChoice is other than 1 - 7
				cout << "You have entered an invalid option. Please choose options 1 to 7 only" << endl;
				break;
		}
		system("pause"); // Pause the program
		system("cls"); // Clear the program screen
	}while(userChoice != 7); // Keep loop until userChoice is 7
	
	cout << "Thank you for using this program!" << endl;
	
    for(int deleteRow=0;deleteRow<x;deleteRow++){
        delete [] userArray[deleteRow]; // Clear allocated space in memory (x)
    }
    delete [] userArray; // Clear remaining allocated space (y)
    
	return 0;
}


//Show menu function
void showMenu(int x,int y){
	
	system("cls");
	cout << "1. Input elements into matrix of size " << x << " x " <<  y << endl;
	cout << "2. To display elements of matrix of size " << x << " x " <<  y << endl;
	cout << "3. Sum of all elements of matrix of size " << x << " x " <<  y << endl;
	cout << "4. To display row-wise sum of matrix of size " << x << " x " <<  y << endl;
	cout << "5. To display column-wise sum of matrix of size " << x << " x " <<  y << endl;
	cout << "6. To create transpose of matrix B of size size " << x << " x " <<  y << endl;
	cout << "7. Quit program" << endl;
	cout << "Enter your choice: ";
}


// Input elements to array function
void inputArray(int** userArray,int x,int y){
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cout << "[" << i << "][" << j << "]: ";
			cin >> userArray[i][j]; // Input elements into the array
		}
	}
}


// Display matrix array function
void showMatrix(int** userArray,int x,int y){
	
	//bool checkArray(x,y);
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cout << "[" << userArray[i][j] << "]"; // Display elements in the array
		}
		cout << endl;
	}	
}

// Sum of matrix function
void matrixSum(int** userArray,int x,int y){
	
	int sum = 0;
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			sum = sum + userArray[i][j]; // Store every elements sum up into variable sum
		}
	}
	
	cout << "Sum of all elements of the matrix is " << sum << endl;
}

// Sum of row wise
void rowWiseSum(int** userArray,int x,int y){
	
	int sum = 0;
	
	for(int i=0;i<x;i++){
		sum = 0;
		for(int j=0;j<y;j++){
			cout << "[" << userArray[i][j] << "]";
		}
		cout << endl;
	}
	
	for(int i=0;i<x;i++){
		sum = 0;
		for(int j=0;j<y;j++){
			sum = sum + userArray[i][j];
		}
		cout << "Sum of row " << i+1 << " is " << sum << endl;
	}
}

//Sum of columns wise
void colWiseSum(int** userArray,int x,int y){
	
	int sum = 0;
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cout << "[" << userArray[i][j] << "]";
		}
		cout << endl;
	}
	
	for(int i=0;i<x;i++){
		sum = 0;
		int j;
		for(j=0;j<y;j++){
			sum = sum + userArray[j][i];
		}
		cout << "Sum of column " << i+1 << " is " << sum << endl;
	}
}

//Transpose matrix function
void transposeMatrix(int** userArray,int x,int y)
{
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			cout << "[" << userArray[j][i] << "]"; // Display transpose matrix 
		}
		cout << endl;
	}
}