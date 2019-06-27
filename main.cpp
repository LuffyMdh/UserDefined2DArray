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
	string errorMessage1 = "Please input elements into the array before proceed!";
	int userChoice; //User choice variable
	int x,y;
	bool checkArray = 1; // Make sure user input elements into the array
	int** userArray;
    
    
	cout << "Please enter row number : ";
	cin >> x;
	cout << "Please enter column number : ";
	cin >> y;
    
    userArray = new int*[x];
    
    for(int i=0;i<x;i++)
    {
        userArray[i] = new int[y];
    }
	
	do{
		showMenu(x,y);
		cin >> userChoice;
		
		switch(userChoice){
			case 1:
				inputArray(userArray,x,y);
				checkArray = 0;
				break;

			case 2:
			if(checkArray){
				cout << errorMessage1 << endl;
				break;
			}
			else{
				showMatrix(userArray,x,y);
				break;
			}
				
			case 3:
			if(checkArray){
				cout << errorMessage1 << endl;
				break;
			}
			else{
				matrixSum(userArray,x,y);
				break;
			}
				
			case 4:
			if(checkArray){
				cout << errorMessage1 << endl;
				break;
			}
			else{
				rowWiseSum(userArray,x,y);
				break;
			}
				
			case 5:
			if(checkArray){
				cout << errorMessage1 << endl;
				break;
			}
			else{
				colWiseSum(userArray,x,y);
				break;
			}
				
			case 6:
			if(checkArray){
				cout << errorMessage1 << endl;
				break;
			}
			else{
				transposeMatrix(userArray,x,y);
				break;
			}
				
			case 7:
				break;
				
			default:
				cout << "You have entered an invalid option. Please choose options 1 to 7 only" << endl;
				break;
		}
		system("pause");
		system("cls");
	}while(userChoice != 7);
	
	cout << "Thank you for using this program!" << endl;
	
    for(int deleteRow=0;deleteRow<x;deleteRow++){
        delete [] userArray[deleteRow];
    }
    delete [] userArray;
    
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
			cin >> userArray[i][j];
		}
	}
}


// Display matrix array function
void showMatrix(int** userArray,int x,int y){
	
	//bool checkArray(x,y);
	for(int i=0;i<x;i++){
		
		for(int j=0;j<y;j++){
			
			cout << "[" << userArray[i][j] << "]";
		}
		cout << endl;
	}	
}

// Sum of matrix function
void matrixSum(int** userArray,int x,int y){
	
	int sum = 0;
	
	for(int i=0;i<x;i++){
		
		for(int j=0;j<y;j++){
			
			sum = sum + userArray[i][j];
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
			
			cout << "[" << userArray[j][i] << "]";
		}
		cout << endl;
	}
}