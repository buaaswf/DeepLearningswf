 //Harilick.cpp : Defines the entry point for the console application.


//#include "stdafx.h"
//#include "CVIPtexture.h"
//#include "ppbm.h"
//#include "cvip_pgmtexture.c"
//int _tmain(int argc, _TCHAR* argv[])
//{
//	int distance;
//	register gray **grays;
//	int rows=3;
//	const int cols=4;
//	//test.readImage(indata,"F:\\lab\\VTKproj\\mig.raw",l*m*n*sizeof(unsigned char));
//	//unsigned char **slice =new unsigned char *[n];
//	//for (int k = 0; k < n; k++)
//	//{
//	//	slice[k] = new unsigned char[l*m];
//	//	memcpy(slice[k],result,l*m);
//	//	//slice++;
//	//	result += l*m;
//	//}
//	gray *indata=new gray[cols];
//	for (int i=0;i<cols;i++)
//	{
//		indata[i]=i;
//	}
//	gray** line=new gray*[cols];
//	for (int k = 0; k < cols; k++)
//	{
//		line[k] = new gray[cols];
//		memcpy(line[k],indata,cols);
//		//slice++;
//		indata += cols;
//	}
//	grays=line;
//	//gray indata[2][3]={{1,2,3},{4,5,6}};
//	//*grays = indata[0];
//	//*(grays+1)=indata[1];
//	//for (int i=0;i<rows;i++)
//	//{
//	//	for (int j=0;j<cols;j++)
//	//	{
//	//		*(*(grays+i)+j)=3*i+j;
//	//	}
//	//}
//
//
//	int ASM=1;		/*  (1) Angular Second Moment */
//	int contrast=0;		/*  (2) Contrast */
//	int correlation=0;	/*  (3) Correlation */
//	int variance=0;		/*  (4) Variance */
//	int IDM=0;		/*  (5) Inverse Diffenence Moment */
//	int sum_avg=0;		/*  (6) Sum Average */
//	int sum_var=0;		/*  (7) Sum Variance */
//	int sum_entropy=0;	/*  (8) Sum Entropy */
//	int entropy=0;		/*  (9) Entropy */
//	int diff_var=0;		/* (10) Difference Variance */
//	int diff_entropy=0;	/* (11) Diffenence Entropy */
//	int meas_corr1=0;		/* (12) Measure of Correlation 1 */
//	int meas_corr2=0;		/* (13) Measure of Correlation 2 */
//	int max_corr_coef=0; 	/* (14) Maximal Correlation Coefficient */
//	TEXTURE_FEATURE_MAP feature_usage={ASM,contrast,correlation,variance,IDM,sum_avg,sum_var,sum_entropy,entropy,diff_var,diff_entropy,meas_corr1,meas_corr2,max_corr_coef};
//	Extract_Texture_Features( 2, grays, rows,cols,&feature_usage);
//	//return 0;
//	system("pause");
//	return 0;
//}

