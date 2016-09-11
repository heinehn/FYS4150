#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
ofstream ofile;

double f(double x){
    return 100*exp(-10*x);
}

double f_solution(double x){
    return 1.0-(1-exp(-10))*x - exp(-10*x);
}

int main(int argc, char *argv[]){

    char *outfilename;
    int n;

    if( argc <= 2 ){
          cout << "Bad Usage: " << argv[0] <<
              " read also output file and n (int) on same line" << endl;
          exit(1);
    }
        else{
          //outfilename = argv[2]; // first command line argument.
        outfilename = argv[1];
        n = atoi(argv[2]);  // second command line argument.
    }

    //Steplength
    double h = 1.0/(n + 1.0);
    double hh = h*h;

    //Vectors
    double *vec_a = new double[n+1];
    double *vec_b = new double[n+1];
    double *vec_c = new double[n+1];
    double *x = new double[n+2];
    double *vec_u = new double[n+2];
    double *vec_f_approx = new double[n+2];
    double *vec_f_solution = new double[n+2];

    //Setting x values with x+1 so x_0 = 0 and x_(n+2) = 1


    for(int i=0;i==n;i++){
        vec_u[i] = 0;
        vec_f_approx[i] = 0;
        vec_f_solution[i] = 0;
        x[i] = 0;
    }

    for(int i=0;i==n+1;i++){
        x[i] = i*h;
        cout << "x=" << x[i] << " and " << "h^2*f(x) = " << hh*f(x[i]) << endl;
        vec_a[i] = 0;
        vec_b[i] = 0;
        vec_c[i] = 0;
    }

    //Setting up known values
    for(int i = 1;i<n;i++){
        vec_f_solution[i] = f_solution(x[i]);
        vec_f_approx[i] = hh*f(x[i]);
        //cout << vec_f_approx[i] << endl;
        //cout << "exact:  " << vec_f_solution[i] << "approx:  " << vec_f_approx[i]
          //      << endl;
        vec_a[i] = 2;
        vec_b[i] = -1;
        vec_c[i] = -1;
        //cout << "a" << vec_a[i] << "b" << vec_b[i] << "c" << vec_c[i] << endl;
    }
    //makes no sense?
    //vec_b[n] = 0;
    //vec_c[1] = 0;
    cout << vec_a[0] << vec_a[n] << endl;

    //Forward substitution
    //double a = 0;
    for(int i = 2;i<=n;i++){
        //a = vec_c[i-1]/vec_a[i-1];
        vec_a[i] = vec_a[i] - (vec_b[i-1]*vec_c[i-1])/vec_a[i-1];
        vec_f_approx[i] = vec_f_approx[i] - vec_f_approx[i-1]*vec_c[i-1]/vec_a[i-1];
        cout <<"vec_a = "<< vec_a[i] <<" vec_f_approx = "<< vec_f_approx[i] << endl;
    }

    //backwards substitution
    //the first solution
    vec_u[n-1] = vec_f_approx[n-1]/vec_a[n-1];
    //cout << "last is:" << vec_u[n-1] << endl;
    //backwards loop
    for(int i=n-2;i>=1;i--){
        vec_u[i] = (vec_f_approx[i] - vec_b[i]*vec_u[i+1])/vec_a[i];
      // cout << vec_u[i] << "    and " << vec_f_solution[i] << endl;
    }
/*
    //write to file
    ofile.open(outfilename);
    ofile << setiosflags(ios::showpoint | ios::uppercase);
    ofile << "       x:             approx:          exact:  " << endl;
    for (int i=0;i<=n;i++) {
       ofile << setw(15) << setprecision(8) << x[i];
       ofile << setw(15) << setprecision(8) << vec_u[i];
       ofile << setw(15) << setprecision(8) << vec_f_solution[i] << endl;
       /*cout << "x: " << x[i] << "approx: " << vec_f_approx[i]
            << "exact: " << vec_f_solution[i] <<  endl;

    }
    //ofile.close();
*/

    delete [] x;
    delete [] vec_a;
    delete [] vec_b;
    delete [] vec_c;
    delete [] vec_u;
    delete [] vec_f_approx;
    delete [] vec_f_solution;

    return 0;
}
