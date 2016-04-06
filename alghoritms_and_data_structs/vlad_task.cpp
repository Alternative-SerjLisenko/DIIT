    /*
    12. Написати програму.
    Кожен елемент заданої матриці замінити мінімальним елементом,
    вибраним серед елементів, що стоять не нижче і не правіше за цей елемент,
    включаючи його значення.
    */
     
    #include <iostream>
    #include <stdlib.h>
    #include <time.h>
    #include <fstream>
    #include <iostream>
    using namespace std;
     
    void inputMatrix(int matrRange, int **matrix);
    void generateMatrix(int matrRange, int **matrix);
    void outputMatrix(int matrRange, int **matrix);
    void setRangeMatrix(int matrRange, int **&matrix);
    void processingMatrix(int matrRange, int **matrix);
    int sortMatrix(int matrRange, int **matrix);
    void readMatrixFile(int matrRange, int **matrix);
    void recordMatrixFile(int matrRange, int **matrix);
    void userMenu();
     
    int main() {
        userMenu();
            return 0;
    }
     
    void userMenu() {
        //Variable block
        int matrRange = 0;
        int **matrix;
        char menu = '-';
		int temp = 0;
        bool matrixInit = false;
        srand (time(NULL));
        
        cout << "Input matrix range: ";
        cin >> matrRange;
        setRangeMatrix(matrRange, matrix);
       
        while(menu != '0') {
        cout << "\t" << endl;
        cout << "1. Input matrix " << endl;
        cout << "2. Generate matrix " << endl;
        cout << "3. Output matrix " << endl;
        cout << "4. Processing matrix " << endl;
        cout << "5. Sort matrix " << endl;
        cout << "6. Read matrix from file " << endl;
        cout << "7. Record matrix in file " << endl;
        cout << "0. Exit " << endl;
        cout << "\nChose menu item: ";
        cin >> menu;
        switch(menu) {
            case '1':
                inputMatrix(matrRange, matrix);
				cout << "\nMatrix successfully introduced." << endl;
            break;
           
            case '2':
                generateMatrix(matrRange, matrix);
				cout << "\nMatrix successfully introduced." << endl;
            break;
           
            case '3':
                outputMatrix(matrRange, matrix);
            break;
           
            case '4':
                processingMatrix(matrRange, matrix);
            break;
           
            case '5':
				temp = sortMatrix(matrRange, matrix);
                cout << "\nIt was performed "<< temp <<" permutations.";
            break;
            
            case '6':
                if(matrixInit == false) {
                    "Sorry but the function is available only when array processing.";
                    break;
                } else {
                    readMatrixFile(matrRange, matrix);
                }
            break;
            
            case '7':
                if(matrixInit == false) {
                    "Sorry but the function is available only when array processing.";
                    break;
                } else {
                    recordMatrixFile(matrRange, matrix);
                }
            break;
            
            case '0':
                cout << "Bye-bye!";
				menu = '0';
            break;
           
            default:
                cout << "Invalid entry!";
            break;
        }
        }
    }
     
    void setRangeMatrix(int matrRange, int **&matrix) {
        matrix = new int *[matrRange];
        for (int i = 0; i < matrRange; i++) {
            matrix[i] = new int[matrRange];
        }
    }
    void inputMatrix(int matrRange, int **matrix) {
        for (int i = 0; i < matrRange; i++) {
            for (int j = 0; j < matrRange; j++) {
                cout << "input [" << i << "][" << j << "] element: ";
                cin >> matrix[i][j];
            }
        }
    }
    void generateMatrix(int matrRange, int **matrix) {
        for (int i = 0; i < matrRange; i++) {
            for (int j = 0; j < matrRange; j++) {
                matrix[i][j] = rand() % 10;
            }
        }
    }
    void outputMatrix(int matrRange, int **matrix) {
        for (int i = 0; i < matrRange; i++) {
            for (int j = 0; j < matrRange; j++) {
                cout << " " << matrix[i][j];
            }
			cout << endl;
        }
    }
    void processingMatrix(int matrRange, int **matrix) {
       
        //Vatriable block
        int minElement = matrix[0][0];
       
        for (int i = 0; i < matrRange; i++) {
            for (int j = 0; j < matrRange; j++) {
                if (matrix[i][j] < minElement) {
                    minElement = matrix[i][j];
                }
                matrix[i][j] = minElement;
            }
        }
    }
    int sortMatrix(int matrRange, int **matrix) {
      int temp, counter = 0;
	  for (int i = 0; i < matrRange; i++)
            {
                for (int j = 0; j < matrRange; j++)
                {
                    for (int k = 0; k < matrRange; k++)
                    {
                        if (matrix[i][j] < matrix[i][k])
                        {
							counter++;
                            temp = matrix[i][j];
                            matrix[i][j] = matrix[i][k];
                            matrix[i][k] = temp;
                        }
                    }
                }
            }
	   return counter;
    }
    void readMatrixFile(int matrRange, int **matrix) {
        ifstream file;
		file.open("lab6.txt");
		while(file.eof()) {
			for (int i = 0; i < matrRange; i++) {
				for (int j = 0; j < matrRange; j++) {
					file >> matrix[i][j]; 
				}
			}
		
		file.close();
    }
}	
	void recordMatrixFile(int matrRange, int **matrix) {
		ofstream file("lab6.txt");
		/*file << "test test";
		for (int i = 0; i < matrRange; i++) {
			for (int j = 0; j < matrRange; j++) {
				file << " " << matrix[i][j];  
			}
			file << "\n";
		}*/
		file.close();
	}

    