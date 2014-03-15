#ifndef CVIPTEXTURE_H

#define CVIPTEXTURE_H

/***************************************************************************
* ======================================================================
* Computer Vision/Image Processing Tool Project - Henry
* ======================================================================
*
*             File Name: CVIPtexture.h
* 
**
****************************************************************************/

typedef struct  {
/* [0] -> 0 degree, [1] -> 45 degree, [2] -> 90 degree, [3] -> 135 degree,
   [4] -> average, [5] -> range (max - min) */
	float ASM[6];		/*  (1) Angular Second Moment */
	float contrast[6];	/*  (2) Contrast */
	float correlation[6];	/*  (3) Correlation */
	float variance[6];	/*  (4) Variance */
	float IDM[6];		/*  (5) Inverse Diffenence Moment */
	float sum_avg[6];	/*  (6) Sum Average */
	float sum_var[6];	/*  (7) Sum Variance */
	float sum_entropy[6];	/*  (8) Sum Entropy */
	float entropy[6];	/*  (9) Entropy */
	float diff_var[6];	/* (10) Difference Variance */
	float diff_entropy[6];	/* (11) Diffenence Entropy */
	float meas_corr1[6];	/* (12) Measure of Correlation 1 */
	float meas_corr2[6];	/* (13) Measure of Correlation 2 */
	float max_corr_coef[6]; /* (14) Maximal Correlation Coefficient */
	} TEXTURE;


typedef struct {
/* Allows the user to choose which features to extract, a zero will cause 
   the feature to be ignored, the returned feature value will be 0.0 */
	int ASM;		/*  (1) Angular Second Moment */
	int contrast;		/*  (2) Contrast */
	int correlation;	/*  (3) Correlation */
	int variance;		/*  (4) Variance */
	int IDM;		/*  (5) Inverse Diffenence Moment */
	int sum_avg;		/*  (6) Sum Average */
	int sum_var;		/*  (7) Sum Variance */
	int sum_entropy;	/*  (8) Sum Entropy */
	int entropy;		/*  (9) Entropy */
	int diff_var;		/* (10) Difference Variance */
	int diff_entropy;	/* (11) Diffenence Entropy */
	int meas_corr1;		/* (12) Measure of Correlation 1 */
	int meas_corr2;		/* (13) Measure of Correlation 2 */
	int max_corr_coef; 	/* (14) Maximal Correlation Coefficient */
	} TEXTURE_FEATURE_MAP;

#endif