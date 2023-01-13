#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum=0,y=0,mean,x=1,z=0,max=A[0],min=A[0];
    for (int i=0; i<N ; i++ ){
        sum +=A[i];
    }
    mean = sum/N;
    for (int j=0; j<N ; j++ ){
        y += pow(A[j]-mean,2);
    }
    B[0]=mean;
    B[1] = sqrt(((1.0/N)*y));
    for (int k=0; k<N ; k++ ){
        x *= A[k] ;
    }
    B[2] = pow(x,1.0/N);
    for (int l=0; l<N ; l++ ){
        z += 1.0/A[l] ;
    }
    B[3] = N/z;
    for (int m=1; m<N; m++){
        if(A[m] > max) max= A[m];
    }
    B[4] = max;
    for (int n=1; n<N; n++){
        if(A[n] < min) min= A[n];
    }
    B[5]=min;
}
