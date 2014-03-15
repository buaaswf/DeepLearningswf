/***************************************************************************
* ======================================================================
* Computer Vision/Image Processing Tool Project - henry
* ======================================================================
*
*             File Name: CVIPtyp.h
*           Description: defines many of the standard types used throughout
*
** Name Changes:
** 	BOOLEAN ==> CVIP_BOOLEAN
** 	FALSE ==> CVIP_YES
** 	TRUE ==> CVIP_NO
** 	BYTE ==> CVIP_BYTE
** 	SHORT ==> CVIP_SHORT
** 	INTEGER ==> CVIP_INTEGER
** 	FLOAT ==> CVIP_FLOAT
** 	DOUBLE ==> CVIP_DOUBLE
** 	TYPE ==> CVIP_TYPE
**
 *
*
****************************************************************************/

#if !defined( CVIPTYPE_DEFINED )

   #define CVIPTYPE_DEFINED

   typedef enum {CVIP_NO, CVIP_YES} CVIP_BOOLEAN;
   typedef enum {OFF, ON} STATE;
   typedef enum {CVIP_BYTE, CVIP_SHORT, CVIP_INTEGER, CVIP_FLOAT, CVIP_DOUBLE} CVIP_TYPE;

   typedef unsigned char byte;

#endif
