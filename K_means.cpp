#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <math.h>
#include "K_means.h"
#define INFINITY 1;
Kmeans::Kmeans(){}

Kmeans::Kmeans(int new_T, 
               int new_N, 
               int new_K){
	
	int t, k;

	K = new_K;
	T = new_T;
	N = new_N;
	assign = new int[T];
	count = new int[K];
	vector = new Data[T];

	for(t = 0; t < T; t++)
		vector[t].data = new float[N];

	means = new float*[K];
	for(k = 0; k < K; k++)
		means[k] = new float[N];

	}

Ff::Ff(){}

Ff::Ff(int new_T, 
       int new_N, 
       int new_K){
	
	int t, k;

	K = new_K;
	T = new_T;
	N = new_N;

	vector = new Data[T];

	for(t = 0; t < T; t++)
		vector[t].data = new float[N];

	}


Kmeans Kmeans::Estep0(Kmeans km){
	int k, t, n, kmin, nchg;
	float dmin, d;
	nchg = 0;
	for(k = 0; k < km.K; k++) 
		km.count[k] = 0;
	for(t = 0; t < km.T; t++){
		dmin = +INFINITY;
		for(k = 0; k < km.K; k++){
			for(d = 0., n = 0; n < km.N; n++) 
				d += pow((float)vector[t].data[n] - km.means[k][n], (int)2.0);
			if(d < dmin){
				dmin = d; 
				kmin = k;
				}
		}

		if(kmin != km.assign[t]) 
			nchg++;

		km.assign[t] = kmin;
		km.count[kmin]++;
		}

	return km;
	}

Kmeans Kmeans::Mstep0(Kmeans km){
	int t, n, k;
	for(k = 0; k < km.K; k++) 
		for(n = 0; n < km.N; n++) 
			km.means[k][n] = 0.;

	for(t = 0; t < km.T; t++) 
		for(n = 0; n < km.N; n++) 
			km.means[km.assign[t]][n] += vector[t].data[n];

	for(k = 0; k < km.K; k++){
		if(km.count[k] > 0) 
			for(n = 0; n < km.N; n++) 
				km.means[k][n] /= km.count[k];
		}
	return km;	
	}

int *Ff::Center(Ff ff){
	int t, n, k, l;
	int *index = new int[ff.K];
	double *mean = new double[ff.N];

	for(t = 0; t < ff.T; t++)
		for(n = 0; n < ff.N; n++)
			mean[n] += ff.vector[t].data[n];

	for(n = 0; n < ff.N; n++)
		mean[n] /= ff.T;

	double distprev = 0.0;
	double dist = 0.0;

	for(t = 0; t < ff.T; t++){
		for(n = 0; n < ff.N; n++)
			dist += pow(ff.vector[t].data[n] - mean[n], 2.0);
		
		if(dist > distprev){
			index[0] = t;
			distprev = dist;
			}
		dist = 0.0;
		}

	ff.vector[index[0]].label = 1;
	distprev = 0.0;
	dist = 0.0;
	
	double a, b;
	int temp;

	for(k = 0; k < ff.K; k++){
		for(t = 0; t < ff.T; t++)
			if(ff.vector[t].label != 1){
				for(l = 1; l < k; l++)
					if((a = ModArr(ff.vector[index[0]].data, ff.N)) > (b = ModArr(ff.vector[index[l]].data, ff.N))){
						temp = index[0];
						index[0] = index[l];
						index[0] = temp;
						}
				for(n = 0; n < ff.N; n++)	
					dist += pow((float)ff.vector[t].data[n] - ff.vector[index[0]].data[n],(int) 2.0);
					
					
				if(dist > distprev){
					index[k] = t;
					distprev = dist;
					}
				dist = 0.0;
				} 

	
		ff.vector[index[k]].label = 1;
		
		distprev = 0.0; 
		}
	
	return index;
	}


float **Var(float **x, float *m, int T, int N){
	int i, j, t;
	float **C = new float*[N];
	for(i = 0; i < N; i++)
		C[i] = new float[N];
	for(t = 0; t < T; t++)
		for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				C[i][j] += (x[t][i] * x[t][j]) - (m[i] * m[j]);

	for(i = 0; i < N; i++)
			for(j = 0; j < N; j++)
				C[i][j] /= T;

	return C;
	}
