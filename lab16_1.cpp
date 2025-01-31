#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void findColSum(const double *a, double *b, int row, int column) {
    for (int i = 0; i < column; i++) {  
        double sum = 0;
        for (int j = 0; j < row; j++) { 
            sum += a[j * column + i]; 
        }
        b[i] = sum;  
    }
}
//เติมส่วนที่หายไปใน Function showData() โดยห้ามแก้ไขโครงสร้าง

void showData(double *a,int N,int M){
    cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << a[i];
        if((i+1)%M == 0) cout << endl;
        else cout << " ";
    }
}

//เติมส่วนที่หายไปใน Function randData() โดยห้ามแก้ไขโครงสร้าง

void randData(double *a, int N, int M){
    for(int i = 0; i < N*M; i++){
         a[i] = rand()%101/100.0;
    }
}


void findRowSum(const double *a,double *b,int row,int column){
    int o = 0;
    double sum =0 ;
    for(int i = 0; i < row*column; i++){
        sum += *(a+i);
        if((i+1)%column == 0) {//i%M == M-1
            *(b+o) = sum;
            o++;
            sum = 0;
        }

    }
    
}