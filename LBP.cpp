#include "StdAfx.h"
#include "LBP.h"

CLBP::CLBP(void)
{
}

CLBP::~CLBP(void)
{
	if (m_cvImage) cvReleaseImage(&m_cvImage);
	if (m_cvLBPImage) cvReleaseImage(&m_cvLBPImage);
	if (m_cvSubImage) cvReleaseImage(&m_cvSubImage);
}

void CLBP::LBP(string src_image_fl, string lbp_image_fl)
{
	IplImage* temp_image = cvLoadImage(src_image_fl.c_str(), 1);
	m_cvImage = cvCreateImage(cvSize(temp_image->width, temp_image->height), 8, 1);
	m_cvSubImage = cvCreateImage(cvSize(temp_image->width, temp_image->height), 8, 1);
	if (temp_image->nChannels == 3)
	{
		cvCvtColor(temp_image, m_cvImage, CV_BGR2GRAY);
	}
	cvNamedWindow("src_image", 1);
	cvShowImage("src_image", m_cvImage);
	m_cvLBPImage = cvCreateImage(cvSize(m_cvImage->width, m_cvImage->height), 8, 1);

	int center=0;
	int center_lbp=0;
	for (int row=1; row<m_cvImage->height-1; row++)
		for (int col=1; col<m_cvImage->width-1; col++)
		{
			center = cvGetReal2D(m_cvImage, row, col);
			center_lbp = 0;
			if (center >= cvGetReal2D(m_cvImage, row-1, col-1))
			{
				center_lbp += 1;
			}
			if (center >= cvGetReal2D(m_cvImage, row-1, col))
			{
				center_lbp += 2;
			}
			if (center >= cvGetReal2D(m_cvImage, row-1, col+1))
			{
				center_lbp += 4;
			}
			if (center >= cvGetReal2D(m_cvImage, row, col-1))
			{
				center_lbp += 8;
			}
			if (center >= cvGetReal2D(m_cvImage, row, col+1))
			{
				center_lbp += 16;
			}
			if (center >= cvGetReal2D(m_cvImage, row+1, col-1))
			{
				center_lbp += 32;
			}
			if (center >= cvGetReal2D(m_cvImage, row+1, col))
			{
				center_lbp += 64;
			}
			if (center >= cvGetReal2D(m_cvImage, row+1, col+1))
			{
				center_lbp += 128;
			}
			cvSetReal2D(m_cvLBPImage, row, col, center_lbp);
		}
	
	cvNamedWindow("lbp_image", 1);
	cvShowImage("lbp_image", m_cvLBPImage);
    
    SRC_LBP(m_cvImage, m_cvLBPImage, m_cvSubImage);
	cvReleaseImage(&temp_image);
	cvWaitKey(0);
	cvDestroyAllWindows();

}

void CLBP::SRC_LBP(IplImage* image1, IplImage* image2, IplImage* dst)
{
	for (int row=0; row<dst->height; row++)
		for (int col=0; col<dst->width; col++)
		{
			cvSetReal2D(dst, row, col, abs(cvGetReal2D(image1, row, col)-cvGetReal2D(image2, row, col)));
		}
	cvNamedWindow("sub_image", 1);
	cvShowImage("sub_image", dst);
}