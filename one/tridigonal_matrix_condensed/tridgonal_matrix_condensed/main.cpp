#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include <cmath>
#include "time.h"

using namespace std;
ofstream ofile;

//Function
double f(double x){
    return 100*exp(-10*x);
}

//Function for exact solution
double f_exact(double x){
    return 1-x*(1-exp(-10))-exp(-10*x);
}


//Main program reads filename and N form command line
int main() {

    /*
     Declaration of initial variables
     by user input.
    */
    char *filename;
    int N;
    string str;
    string format = ".txt";
    cout << "Number of iterations:" << endl;
    cin >> N;
    cout << "Filename and format:" << endl;
    cin >> str;
    //str.append(filename,format);

    //Set steplenght
    double h = 1.0/(N+1.0);
    double hh = h*h;

    //declare vectors
    double* x = new double[N];
    double* vec_f = new double[N];
    double* vec_f_exact = new double[N];

    //Set initial values to vectors
    for(int i=0;i<N;i++){
        x[i] = i*h;
        vec_f[i] = hh*f(x[i]);
        vec_f_exact[i] = f_exact(x[i]);
    }

    //initialize clock
    clock_t time;

    //startr clock
    time = clock();

    //Special algoritme for unique matix
    for(int i = 0; i<N-1;i++){
        vec_f[i+1] = vec_f[i+1] + i*vec_f[i]/(i+1);
        //Write out data
        //cout << vec_f[i] << endl;
    }

    //clock stops here
    time = clock() - time;
    cout << "Time in sec:" << ((float)time)/CLOCKS_PER_SEC << endl;


    //write to file
    ofile.open(str);
    ofile << setiosflags(ios::showpoint | ios::uppercase);
    ofile << "      x:      approx:     exact:  " << endl;
    for(int i=0;i<N;i++){
        ofile << setw(15) << setprecision(8) << x[i];
        ofile << setw(15) << setprecision(8) << vec_f[i];
        ofile << setw(15) << setprecision(8) << vec_f_exact[i] << endl;
    }
    ofile.close();

    delete [] x;
    delete [] vec_f;
    delete [] vec_f_exact;


    return 0;
}
