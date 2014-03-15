/***************************************************************************
* ======================================================================
* Computer Vision/Image Processing Tool Project For LUNG Henry
* ======================================================================
*
*             File Name: CVIPdef.h
*  
*
**************************************************************************/

#if !defined( CVIPDEF_DEFINED )

   #define CVIPDEF_DEFINED

   #if !defined( CVIPTYP_DEFINED )
      #include "CVIPtyp.h"
   #endif

   /**********************
   * No-argument macros *  
   **********************/

   #define             CLS   printf("\033[2J")
   #define            BEEP   printf("\7")

   /***********************/
   /* one-argument macros */
   /***********************/

   /* absolute value of a */
   #define ABS(a)		((((int)(a))<0) ? -(a) : (a))

   /* round a to nearest integer towards 0 */
   #define FLOOR(a)		((a)>0 ? (int)(a) : -(int)(-a))

   /* round a to nearest integer away from 0 */
   #define CEILING(a) \
   ((a)==(int)(a) ? (a) : (a)>0 ? 1+(int)(a) : -(1+(int)(-a)))

   /* round a to nearest int */
   #define ROUND(a)  (((a) < 0) ? (int)((a)-0.5) : (int)((a)+0.5))

   /* take sign of a, either -1, 0, or 1 */
   #define ZSGN(a)		(((a)<0) ? -1 : (a)>0 ? 1 : 0)	

   /* take binary sign of a, either -1, or 1 if >= 0 */
   #define SGN(a)		(((a)<0) ? -1 : 1)

   /* shout if something that should be true isn't */
   #define ASSERT(x) \
   if (!(x)) fprintf(stderr," Assert failed: %d\n",x);

   /* square a */
   #define SQR(a)		((a)*(a))

	#ifdef WIN32
   #define         drand48()   (((double)rand())/(RAND_MAX+1))
   #define         cbrt(a)   (pow((a),1.0/3.0))
	#endif

   /* find base 2 log of a number */
   #define LOG2(a)         log((double)(a))/log(2.0)

   /* Macro to ease the pains of e.g. comparing 1/3 with 1/3 */
   #define CVIP_NEAR(a,b)	(((float)((a)-(b))) < 0.001 && ((float)((a)-(b))) > -0.001) ? 1 : 0


   /***********************/
   /* two-argument macros */
   /***********************/

   /* find minimum of a and b */
   #define MIN(a,b)	(((a)<(b))?(a):(b))	

   /* find maximum of a and b */
   #define MAX(a,b)	(((a)>(b))?(a):(b))	

   /* swap a and b (see Gem by Wyvill) */
   /* M. Boland  #define SWAP(a,b)	{ a^=b; b^=a; a^=b; } */

   /* linear interpolation from l (when a=0) to h (when a=1)*/
   /* (equal to (a*h)+((1-a)*l) */
   #define LERP(a,l,h)	((l)+(((h)-(l))*(a)))

   /* clamp the input to the specified range */
   #define CLAMP(v,l,h)	((v)<(l) ? (l) : (v) > (h) ? (h) : v)

   /* reposition the shell cursor at line y, offset x */
   #define    GOTOYX(y, x)   printf("\033[%d;%dH", y, x)

	#ifdef WIN32
	#ifndef strcasecmp
	#define strcasecmp(a,b) stricmp(a,b)
	#endif
	#endif

	#if defined(SYSV)  || defined(WIN32)
	#ifndef bzero
	#define bzero(dst,len) memset(dst,0,len)
	#endif
	#ifndef bcopy
	#define bcopy(src,dst,len) memcpy(dst,src,len)
	#endif
	#endif


   /****************************/
   /* memory allocation macros */
   /****************************/

   /* create a new instance of a structure (see Gem by Hultquist) */
   #define NEWSTRUCT(x)	(struct x *)(malloc((unsigned)sizeof(struct x)))

   /* create a new instance of a type */
   #define NEWTYPE(x)	(x *)(malloc((unsigned)sizeof(x)))


   /********************/
   /* useful constants */
   /********************/

	#ifndef PI
   #define PI		3.141592654	/* the venerable pi */
	#endif
   #define PITIMES2	6.283185307	/* 2 * pi */
   #define PIOVER2	1.570796327	/* pi / 2 */
   #define E		2.718281828	/* the venerable e */
   #define SQRT2	1.414213562	/* sqrt(2) */
   #define SQRT2OVER2	0.7071068	/* sqrt(2) / 2 */
   #define SQRT3	1.732050808	/* sqrt(3) */
   #define GOLDEN	1.618034	/* the golden ratio */
   #define DTOR		0.017453293	/* convert degrees to radians */
   #define RTOD		57.29577951	/* convert radians to degrees */
/* For FreeBSD, ulong is not defined,
   so we'll define it here */
#if (defined(i386BSD) || defined(WIN32))
   typedef unsigned long ulong;
#endif

#endif
