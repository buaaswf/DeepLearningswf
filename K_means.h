#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include "Util.h"

using namespace std;

typedef struct datas{

	float *data;
	int label;
	datas(){
		data=NULL;
	}

}Data;

float **Var(float **x, float *m, int T, int N);

//K-means class
class Kmeans{

	public:
	Data *vector; //Data
 	float **means; //means per cluster
	int T; //Data length 
	int N; //Data dim
	int K; //Number of clusters
	int *assign; //Each data element is assigned to one of the K cluster
	int *count; //Count of elements per cluster 
	Kmeans(); //Constructor
	Kmeans(int new_T, int new_N, int new_k); //Constructor
	Kmeans Estep0(Kmeans km); //K-means e step
	Kmeans Mstep0(Kmeans km); //K-means m step

	};

//Farthest First class
class Ff{

	public:
	Data *vector; //Data
	int T; //Data length
	int N; //Data dim
	int K; //Number of clusters
	Ff(); //Constructor
	Ff(int new_T, int new_N, int new_K); //Constructor
	int *Center(Ff ff); //Find initial centers (means) 
	
	};

