#include <iostream>
#include <fstream>
#include <stdio.h>
//plotting
#include <QApplication>
#include "figure.h"
#include <vector>

using namespace std;

#include "time.h"


//Function
double f(double x){
    return 100*exp(-10*x);
}

//exact solution
double f_exact(double x){
    return 1-x*(1-exp(-10))-exp(-10*x);
}

int main(int argc, char **argv)
{
    //number of matices
    int n = 3;
    double* vec_N = new double[n];
    int m = 1;

    for(int i = 0; i<n; i++){
        m = 10*m;
        vec_N[i] = m;
    }

    for(int j=0; j<0; j++){

    //constants
    int N = vec_N[j];
    double h = 1.0/(N+1.0);
    double hh = h*h;

    //assigning vectors
    double* vec_a = new double[N];
    double* vec_b = new double[N];
    double* vec_c = new double[N];
    double* vec_u = new double[N];//solution vector
    double* vec_f = new double[N];
    double* vec_u_exact = new double[N];
    double* x = new double[N];

    //assingning numbers to each element in diagonal martix
    for(int i=0; i< N; i++){
        x[i] = i*h;
        vec_a[i] = 2;//center diagonal
        vec_b[i] = -1;//right diagonal
        vec_c[i] = -1;//left diagonal
        vec_u[i] = 0;
        vec_f[i] = hh*f(x[i]);
        vec_u_exact[i] = 0;
    }

    //clock starts here
    clock_t time; //declare start and final time

    time = clock();

    //forward substitution
    for(int i=0; i<N-1; i++){
        double var = 0;
        double var_f = 0;
        var = vec_c[i]/vec_a[i];
        var_f = vec_f[i]*var;
        var = vec_b[i]*var;
        vec_a[i+1] = vec_a[i+1] - var;
        vec_f[i+1] = vec_f[i+1] - var_f;
        vec_u_exact[i] = f_exact(x[i]);
    }

    //define special element
    vec_u[N-2] = vec_f[N-2]/vec_a[N-2];

    //Backwards substitution
    for(int i=N-3; i>0; i--){
        double mult_var = 0;
        double sub_var = 0;
        mult_var = vec_b[i]*vec_u[i+1];
        sub_var = vec_f[i] - mult_var;
        vec_u[i] = sub_var/vec_a[i];
    }

    //clock stops here
    time = clock() - time;
    printf("Time %d and sec. %f.\n",time,((float)time)/CLOCKS_PER_SEC);


/*
    //write to file and add plott elemnts
    ofstream outfile;
    outfile.open("output.txt");
    for(int i=0;i<N;i++){
        outfile <<  x[i] << " , " << vec_u[i] << " , "
                 << vec_u_exact[i] << "\n" << endl;
    }
    outfile.close();
*/
    }
    return 0;
}
