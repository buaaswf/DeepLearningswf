#include <stdio.h>
#include <stdlib.h>
//
//int main(int argc, char **argv){
//	
//	int i, j;
//	int Number = atoi(argv[1]);
//
//	double *p = (double *)malloc(sizeof(double) * Number);
//	double **A = (double **)malloc(sizeof(double*) * Number);
//	for(i = 0;i < Number; i++)
//		A[i] = (double *)malloc(sizeof(double ) * Number);
//
//	/*circular*/
//	/*for(i = 0; i < Number; i++)
//		p[i] = 1.0;
//		
//	for(i = 0; i < Number; i++){
//		for(j = 0; j < Number; j++){
//			A[i][j] = 0.0;
//			
//			if(i == j - 1) 
//				A[i][j] = 1.0;
//	
//			else if(i == j) 
//				A[i][j] = 1.0;
//	
//			else if(i == Number - 1 && j == 0) 
//				A[i][j] = 1.0;
//			}
//		}*/
//
//	
//		/*left-to-right*/
//	for(i = 0; i < Number; i++){
//		if(i) 
//			p[i] = 0.0;
//
//		else 
//			p[i] = 1.0;
//		}
//
//	for(i = 0; i < Number; i++){
//		for(j = 0; j < Number; j++){
//			A[i][j] = 0.0;
//
//			if(i == j - 1) 
//				A[i][j] = 1.0;
//
//			else if(i == j) 
//				A[i][j] = 1.0;
//			}
//		}
//
//	for(i = 0; i < Number; i++)
//		printf("%.2f ", p[i]);
//	printf("\n\n");
//	
//	for(i = 0; i < Number; i++){
//		for(j = 0; j < Number; j++)
//			printf("%.2f ", A[i][j]);
//		printf("\n");
//		}
//	printf("\n");
//
//	return 0;
//	}
