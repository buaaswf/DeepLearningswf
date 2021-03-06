#ifndef INTERFACE_SWF
#define INTERFACE_SWF


#include "vol_math_ImageVolume.h"
#include "vol_math_RawImage.h"
#include "vol_math_WipeNioisePde.h" //3d ansitropic filter
#include "vol_math_BilateralFilter.h" //2d bilateralfilter
#include "vol_math_ThreeDim_Bilateral.h"//3d bilateralfilter
#include "vol_math_GuassFilter.h"//2d \3d guass filter
#include "vol_math_trilateralfilter.h"//3d trilaterfilter
#include "vol_math_Anistropic2D.h"
#include "vol_math_2Dtrilateralfilter.h"
#include "vol_math_Otsu.h"
#include"vol_math_FourierFilter2.h"
#include "vol_math_FourierFilter3.h"
#include "vol_math_Watersheds.h"
extern size_t globalProgressChanged;
extern size_t volatile progressStep;
struct GeoBodyDataStruct
{
    const char* file_name;
    const char* project_name;
    const char* survey_name;
    //    GC_TIME = 1,
    //    GC_DEPTH = 2,
    //    GC_ANY = 3
    int field_system;
    int coordinate_system;
    float grid_inc[3];
    float global_min_value;
    float global_max_value;
    std::vector<float> min_property_value;
    std::vector<float> max_property_value;
    long long points_count;
    int body_count;
    std::vector<long long> body_index_number;
        //qym 
        std::vector<double> z_projection_area_size;//project subvolume on Z plane 
 /*   std::vector<Box3Int> coordinate_ranges;
    std::vector<std::vector<Int16Triple>*> body_data;*/
    std::vector<std::vector<unsigned char>*> body_data_value8;
     std::vector<std::vector<unsigned short>*> body_data_value16;
     std::vector<std::vector<float>*> body_data_value32;
        /*std::vector<unsigned char*> body_data_value8;
        std::vector<unsigned short*> body_data_value16;
        std::vector<float*>  body_data_value32;*/
    //1 unsigned char
    //2 unsigned short
    //3 float
    int data_type;//



    GeoBodyDataStruct()
    {
        field_system = 1;
        coordinate_system = 0;//0 cdp, 1 x-y
        grid_inc[0] = 1;// if coordinate_system == 0 ,line cdp time inc
        grid_inc[1] = 1;// if coordinate_system == 0 ,line cdp time inc
        grid_inc[2] = 1;// if coordinate_system == 0 ,line cdp time inc
        global_min_value = 0;
        global_max_value = 254;
        /*min_property_value = 0;
          max_property_value = 254;*/
        points_count = 0; //how many points of all point set
        body_count = 0; //how many point set 

        this->data_type = 1;

    }
};
	//struct Points
	//{
	//	short x;
	//	short y;
	//	short z;
	//	//void * pixel;
	//	Points(short x,short y,short z)
	//	{
	//		this->x = x;
	//		this->y = y;
	//		this->z = z;
	//	}
	//};

/**
 \brief	Anisotropic filter interface parameter 
 */

struct  AnistropicII
{
	int time;
	int val; //val=1
	int method; 
	int datatype;
	int threadcount;
	/*
	method:
	1:Perona_Malik();
	2:four_diff
	*/
	AnistropicII(int time,int val,int method,int datatype,int threadcount)
	{
		this->time = time;
		this->val = val;
		this->method = method;
		this->datatype = datatype;
		this->threadcount = threadcount;
	}


};
struct  AnistropicI
{
	int time;
	int val; //val=1
	int method; 
	int threadcount;
	/*
	method:
	1:Perona_Malik();
	2:four_diff
	*/
	AnistropicI(int time,int val,int method,int threadcount)
	{
		this->time = time;
		this->val = val;
		this->method = method;
		this->threadcount = threadcount;
	}


};
struct  TrilateralfilterI
{
	float sigmaC;//sigmaC=1	spacing domain variance
	float sigmaA;//value  domain variance
	int threadcount;

	TrilateralfilterI(int threadcount,float sigmaC =3)
	{
		this->sigmaC = sigmaC;
		this->threadcount=threadcount;
	}
	TrilateralfilterI(int threadcount,float sigmaC,float sigmaA)
	{
		this->sigmaC = sigmaC;
		this->threadcount=threadcount;
		this->sigmaA;
	}
};

struct BilateralFilterI
{
	double sigmaD;//guass fliter cooper std for space 
	double sigmaR;//guass filter cooper std for pixel
	int threadcount;
	BilateralFilterI(double sigmaD,double sigmaR,int threadcount)
	{
		this->sigmaD=sigmaD;
		this->sigmaR=sigmaR;
		this->threadcount=threadcount;
	}
};

struct GuassFilterI
{
	int halfsize;
	int threadcount;
	GuassFilterI(int halfsize,int threadcount)
	{
		this->halfsize=halfsize;
		this->threadcount=threadcount;
	}
};

struct lowPassI
{
	float threshold;
	lowPassI(float threshold)
	{
		this->threshold =threshold;
	}


};
struct MultiOstuI
{
	int method;
	int classnum; //expexted numbers
	/*
	1\user write the number 
	2\algorithm compute the number
	*/
	MultiOstuI(int method,int classnum)
	{
		this->method=method;
		this->classnum=classnum;
		
	}
};
struct WaterShedsI
{
	int smoothszie;
	int threshold;
	WaterShedsI(int smoothszie,int threshold)
	{
		this->smoothszie=smoothszie;
		this->threshold=threshold;
	}
	WaterShedsI()
	{

	}
};
//=======================================================================================================================================
//2014 -1-21add by buaa songwf :
// big data multi thread process interface add a
// struct  process(
//int window_size;
//pixtype **line;
//pixtype *resault;
//parameters .....)
// 用于窗口为n的一般意义上的滤波。比如window_size一般为3，下面那个pixtype **line就放三个剖面的数据。然后根据参数计算结果。
struct Process
{
		
	int method;
	/*
	1 tilateral
	2 anistropic
	3 bilatetral
	4 gauss
	*/
	int datatype;
	/*
	1u char
	2 u short
	3 float
	*/
	int xsize;
	int ysize;
	int window_size; //for normal filters
	PIXTYPE **slices;
	PIXTYPE *result;
	double sigmaD;//bilateral filter,trilateral filter
	double sigmaR;//bilateral filter ,trilateral filter
	double sigmaD2;//trilateral filter
	double sigmaR2;//trilateral filter
	int threadcount;
	Process (int datatype, int xsize,int ysize,int window_size , PIXTYPE **slice, PIXTYPE *result, double s1 ,double s2, double s3, double s4 ,int threadcount)
	{
		this->datatype = datatype;
		this->xsize = xsize;
		this->ysize = ysize;
		this->window_size = window_size;
		this->slices = slice;
		this->result = result;
		this->sigmaD = s1 ;
		this->sigmaR = s2 ;
		this->sigmaD2 = s3 ;
		this->sigmaR2 = s4 ;
		this->threadcount = threadcount;

	}

};

/**
 \brief	Executes the anistropic i operation.

 \param [in,out]	src		  	Source for the.
 \param [in,out]	parameter2	The second parameter.

 \return	null if it fails, else.
 */

extern void * doAnistropicI (ImageVolume &src,AnistropicI &);

/**
 \brief	Executes the anistropic i operation.

 \param [in,out]	src		  	If non-null, source for the.
 \param [in,out]	ret		  	If non-null, the ret.
 \param [in,out]	parameter3	The third parameter.

 \return	null if it fails, else.
 */

extern void * doAnistropicI (Raw *src, Raw *ret, AnistropicII &);

/**
 \brief	Executes the anisotropic i operation. for direction x multi 
		thread segment the slices from x direction 

 \param [in,out]	src 	If non-null, source for the input data.
 \param [in,out]	ret 	If non-null, the ret for the output data.
 \param [in,out]	para	The para for interface.

 \return	true if it succeeds, false if it fails.
 */

extern bool  doAnistropicI(ImageVolume * src, ImageVolume *ret,AnistropicI &para);
extern bool  doAnistropicI(ImageVolume * src, ImageVolume *ret,AnistropicI &para,void(*ProgressChanged)(int,int,int,bool &));
extern void *doTrilateralfilterI ( ImageVolume &, TrilateralfilterI &);
extern void * doAnistropicI (Process &);
extern void *doAnistropicykfour_diff(ImageVolume &src,AnistropicI &);
extern void *doGuassFilterI (ImageVolume &, GuassFilterI &);
extern void *doGuassFilterI (Process &);
/**
 \brief	Executes the anisotropic interface y operation for y direction .

 \param [in,out]	src 	If non-null, source for the.
 \param [in,out]	ret 	If non-null, the ret.
 \param [in,out]	para	The para.

 \return	true if it succeeds, false if it fails.
 */

extern bool  doAnistropicIY(ImageVolume * src, ImageVolume *ret,AnistropicI &para );
extern bool  doAnistropicIYproqt(ImageVolume * src, ImageVolume *ret,AnistropicI &para,int tasknum,void(*ProgressChanged)(int,int,int,bool &) );
extern void * doBilateralI (ImageVolume &, BilateralFilterI &);
bool  doBilateralI (ImageVolume * src, ImageVolume *ret,BilateralFilterI &para);
bool  doBilateralIY (ImageVolume * src, ImageVolume *ret,BilateralFilterI &para);
bool  doBilateralproqt(ImageVolume * src, ImageVolume *ret,BilateralFilterI &para,int tasknum,void(*ProgressChanged)(int,int,int,bool &) );
bool doGuassFilterI (ImageVolume * src, ImageVolume *ret,GuassFilterI &para);
bool doGuassFilterIY (ImageVolume * src, ImageVolume *ret,GuassFilterI &para);
bool doGuassFilterFileMode(void **src,int width,int height ,int count,void * ret,GuassFilterI &para,int datatype);
bool doGaussproqt(ImageVolume * src, ImageVolume *ret,GuassFilterI &para,int tasknum,void(*ProgressChanged)(int,int,int,bool &));
bool doAnistropicFilterFileMode(void **src,int width,int height ,int count,void * ret,AnistropicI &para,int datatype);
bool doTrilateralFilterFileMode(void **src,int width,int height ,int count,void * ret,TrilateralfilterI &para,int datatype);
bool doBilateralFilterFileMode(void **src,int width,int height ,int count,void * ret,BilateralFilterI &para,int datatype);  
bool doTrilateralfilterI ( ImageVolume * src, ImageVolume *ret,TrilateralfilterI &para);
bool doTrilateralproqt(ImageVolume * src, ImageVolume *ret,TrilateralfilterI &para,int tasknum,void(*ProgressChanged)(int,int,int,bool &));
bool doTrilateralfilterIY ( ImageVolume * src, ImageVolume *ret,TrilateralfilterI &para);
bool doMultiOstuI (ImageVolume *src,ImageVolume *ret,MultiOstuI &para);
bool doMWaterSheds(ImageVolume *src,ImageVolume *ret,WaterShedsI &para);
bool dolowPassI (ImageVolume *src,ImageVolume * ret,lowPassI &);
bool doGuassFilterFileMode(void **src,int width,int height ,int count,void * ret,GuassFilterI &para,int datatype,void(*ProgressChanged)(int,int,int,bool &));
bool doAnistropicFilterFileMode(void **src,int width,int height ,int count,void * ret,AnistropicI &para,int datatype,void(*ProgressChanged)(int,int,int,bool &));
bool doTrilateralFilterFileMode(void **src,int width,int height ,int count,void * ret,TrilateralfilterI &para,int datatype,void(*ProgressChanged)(int,int,int,bool &));
bool doBilateralFilterFileMode(void **src,int width,int height ,int count,void * ret,BilateralFilterI &para,int datatype, void(*ProgressChanged)(int,int,int,bool &));
bool doAnistropicIY(ImageVolume * src, ImageVolume *ret,AnistropicI &para,void(*ProgressChanged)(int,int,int,bool &));
bool doGuassFilterIY (ImageVolume * src, ImageVolume *ret,GuassFilterI &para,void(*ProgressChanged)(int,int,int,bool &));
bool doTrilateralfilterIY ( ImageVolume * src, ImageVolume *ret,TrilateralfilterI &para,void(*ProgressChanged)(int,int,int,bool &));
bool doMultiOstuI (ImageVolume *src,ImageVolume *ret,MultiOstuI &para,void(*ProgressChanged)(int,int,int,bool &));
bool doWaterShedsI(ImageVolume *src,ImageVolume *ret,WaterShedsI &para,void (*progresschanged)(int,int,int,bool &));
bool doWaterSheds2D(Image2D *src,Image2D *ret,WaterShedsI &para);
bool doBilateralI (ImageVolume * src, ImageVolume *ret,BilateralFilterI &para,void(*ProgressChanged)(int,int,int,bool &));
bool dolowPassI (ImageVolume *src,ImageVolume * ret,lowPassI &,void(*ProgressChanged)(int,int,int,bool &));
extern void *doAnistropicI2D (Image2D &src,AnistropicI &);
extern void *doBilateralI2D (Image2D&, BilateralFilterI &);
extern void *doGuassFilterI2D (Image2D &, GuassFilterI &);
extern void *doTrilateralfilterI2D ( Image2D &, TrilateralfilterI &);
extern void *doMultiOstuI2D (Image2D &src,MultiOstuI &);
extern void *dolowPassI2D (Image2D &src,lowPassI &);
extern void *doMultiOstuI (Image2D &src,MultiOstuI &);
//extern void *domultiThread (int medthod,int threadcount);
/*
1
2
3
4
5
6
7
8
9
10
11
12
*/

#endif