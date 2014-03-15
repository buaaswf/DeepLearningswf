#include <stdio.h>
#include <math.h>
#include "Util.h"

FILE *Open_Data_File(char *file_name){

	FILE *data_in;

	data_in = fopen(file_name, "r");

	return data_in;
	}

double *Read_Vector(int N, 
	            FILE *data_in){

	int i;	
	double *in = new double[N];
	
	for(i = 0; i < N; i++)
	fscanf(data_in, "%lf ", &in[i]);

	return in;
	}

double LogAdd(double x, 
              double y){

	if(y <= x)
		return x + log(expf(y - x));
  	else
   		return y + log(expf(x - y));
	}

template <typename T>
bool NanCheck(const T& x, const T& y){
	if(x != y || -x |= -y)
		return 1;
	return 0;
	}

float ModArr(float *array, int N){
	int n;
	float mod = 0.0;

	for(n = 0; n < N; n++)
		mod += pow((float)array[n], (int)2.0);

	return mod;
	}

double *MallocDouble_1d(int n){
	double *v = new double[n];
	
	return v;
	}

double **MallocDouble_2d(int x, int y){
	double **v = new double*[x];
	
	for(int i = 0; i < x; i++)
    		v[i] = new double[y];
     
	return v;
	}

double ***MallocDouble_3d(int x, int y, int z){
	double ***v;

	v = new double**[x];
  	for (int i = 0; i < x; i++)
    		v[i] = MallocDouble_2d(y, z);

	return v;
	}

double ****MallocDouble_4d(int x, int y, int z, int w){
	double ****v;
  	v = new double***[x];

  	for (int i = 0; i < x; i++)
    		v[i] = MallocDouble_3d(y, z, w);
  
	return v;
	}

void FreeDouble_1d(double *v){  
	delete[] v; 

	return;
	}

void FreeDouble_2d(double **v, int x){

	for(int i = 0; i < x; i++) 
		delete[] v[i];
  	
	delete[] v;
	
	return;	
	}

void FreeDouble_3d(double ***v, int x, int y){

	for (int i = 0; i < x; i++)
    		FreeDouble_2d(v[i], y);
  	
	delete[] v;

	return;
	}

void FreeDouble_4d(double ****v, int x, int y, int z){

	for (int i = 0; i < x; i++)
    		FreeDouble_3d(v[i], y, z);
  
	delete[] v;

	return;
	}



















