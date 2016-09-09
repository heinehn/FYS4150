#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{   
    //pointer or adresses
    int five = 5;
    int* adress = &five; //* means pointer to the adress of five
    int** adressOfAdress = &adress; //** adress to adress INSEPTION!

    cout << "Number:" << five << endl;
    cout << "adress of number:" << adress << endl;
    cout << "adress og adress:" << adressOfAdress << endl;

    *adress = 10; //change number in adress

    cout << "Number:" << five << endl;
    cout << "adress of number:" << adress << endl;

    ////////////////////////////////////////
    //make vector
    int* array = new int[10]; //make array of 10 elements

    int number = 4;
    int* arrayadress = &number;
    *arrayadress = 10;

    //these do the same
    *array = 16;
    array[0] = 16;

    array[1] = 5;
    cout << *(array +1) << endl;

    ///////////////////////////////////////
    //make matrix
    int *row0 = new int[4];
    int *row1 = new int[4];
    int *row2 = new int[4];
    int *row3 = new int[4];

    row1[3];//(2,3)

    int **matrix = new int*[4];
    matrix[0] = row0;
    matrix[1] = row1;
    matrix[2] = row2;
    matrix[3] = row3;

    matrix[3][1] = 4;

    //quick way
    int **matrix2 = new int*[4];
    for(int i=0; i<4; i++){
        matrix2[i] = new int[4];
    }
    cout << matrix[3][1] << endl;
    return 0;
}
