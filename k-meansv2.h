/***************************************************************************
Module Name:
	KMeans

History:
	2003/10/16	Fei Wang
	2013 luxiaoxun
***************************************************************************/

#pragma once
#include <fstream>
#include "vol_math_RawImage.h"
class KMeans
{
public:
	enum InitMode
	{
		InitRandom,
		InitManual,
		InitUniform,
		FastMode,
	};

	KMeans(int dimNum = 1, int clusterNum = 1);
	~KMeans();

	void SetMean(int i, const PIXTYPE* u){ memcpy(m_means[i], u, sizeof(PIXTYPE) * m_dimNum); }
	void SetInitMode(int i)				{ m_initMode = i; }
	void SetMaxIterNum(int i)			{ m_maxIterNum = i; }
	void SetEndError(PIXTYPE f)			{ m_endError = f; }

	PIXTYPE* GetMean(int i)	{ return m_means[i]; }
	int GetInitMode()		{ return m_initMode; }
	int GetMaxIterNum()		{ return m_maxIterNum; }
	PIXTYPE GetEndError()	{ return m_endError; }


	/*	SampleFile: <size><dim><data>...
		LabelFile:	<size><label>...
	*/
	void Cluster(const char* sampleFileName, const char* labelFileName);
	void Init(std::ifstream& sampleFile);
	void Init(PIXTYPE *data, int N);
	void Cluster(PIXTYPE *data, int N, int *Label);
	friend std::ostream& operator<<(std::ostream& out, KMeans& kmeans);

private:
	int m_dimNum;
	int m_clusterNum;
	PIXTYPE** m_means;

	int m_initMode;
	int m_maxIterNum;		// The stopping criterion regarding the number of iterations
	PIXTYPE m_endError;		// The stopping criterion regarding the error

	PIXTYPE GetLabel(const PIXTYPE* x, int* label);
	PIXTYPE CalcDistance(const PIXTYPE* x, const PIXTYPE* u, int dimNum);
};
