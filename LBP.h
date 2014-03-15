#pragma once

#pragma comment(lib, "cv.lib")
#pragma comment(lib, "cxcore.lib")
#pragma comment(lib, "highgui.lib")
#include "cv.h"
#include "cxcore.h"
#include "highgui.h"
#include <string>
using namespace std;

class CLBP
{
public:
	CLBP(void);
public:
	~CLBP(void);

private:
	IplImage*			m_cvImage;
	IplImage*			m_cvLBPImage;
	IplImage*			m_cvSubImage;
	string				m_strFilename;
	string				m_strLBPFilename;

public:
	void				LBP(string src_image_fl, string lbp_image_fl);
	void				SRC_LBP(IplImage* image1, IplImage* image2, IplImage* dst);
};
