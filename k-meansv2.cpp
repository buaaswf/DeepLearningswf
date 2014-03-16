/***************************************************************************
Module Name:
	KMeans low speed
	buaa swf


***************************************************************************/

#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <vector>
#include "k-meansv2.h"
using namespace std;


KMeans::KMeans(int dimNum, int clusterNum)
{
	m_dimNum = dimNum;
	m_clusterNum = clusterNum;

	m_means = new PIXTYPE*[m_clusterNum];
	for(int i = 0; i < m_clusterNum; i++)
	{
		m_means[i] = new PIXTYPE[m_dimNum];
		memset(m_means[i], 0, sizeof(PIXTYPE) * m_dimNum);
	}

	m_initMode = InitRandom;
	m_maxIterNum = 100;
	m_endError = 0.001;
}

KMeans::~KMeans()
{
	for(int i = 0; i < m_clusterNum; i++)
	{
		delete[] m_means[i];
	}
	delete[] m_means;
}

void KMeans::Cluster(const char* sampleFileName, const char* labelFileName)
{
	// Check the sample file
	ifstream sampleFile(sampleFileName, ios_base::binary);
	assert(sampleFile);

	int size = 0;
	int dim = 0;
	sampleFile.read((char*)&size, sizeof(int));
	sampleFile.read((char*)&dim, sizeof(int));
	assert(size >= m_clusterNum);
	assert(dim == m_dimNum);

	// Initialize model
	Init(sampleFile);

	// Recursion
	PIXTYPE* x = new PIXTYPE[m_dimNum];	// Sample data
	int label = -1;		// Class index
	PIXTYPE iterNum = 0;
	PIXTYPE lastCost = 0;
	PIXTYPE currCost = 0;
	int unchanged = 0;
	bool loop = true;
	int* counts = new int[m_clusterNum];
	PIXTYPE** next_means = new PIXTYPE*[m_clusterNum];	// New model for reestimation
	for(int i = 0; i < m_clusterNum; i++)
	{
		next_means[i] = new PIXTYPE[m_dimNum];
	}

	while(loop)
	{
	    //clean buffer for classification
		memset(counts, 0, sizeof(int) * m_clusterNum);
		for(int i = 0; i < m_clusterNum; i++)
		{
			memset(next_means[i], 0, sizeof(PIXTYPE) * m_dimNum);
		}

		lastCost = currCost;
		currCost = 0;

		sampleFile.clear();
		sampleFile.seekg(sizeof(int) * 2, ios_base::beg);

		// Classification
		for(int i = 0; i < size; i++)
		{
			sampleFile.read((char*)x, sizeof(PIXTYPE) * m_dimNum);
			currCost += GetLabel(x, &label);

			counts[label]++;
			for(int d = 0; d < m_dimNum; d++)
			{
				next_means[label][d] += x[d];
			}
		}
		currCost /= size;

		// Reestimation
		for(int i = 0; i < m_clusterNum; i++)
		{
			if(counts[i] > 0)
			{
				for(int d = 0; d < m_dimNum; d++)
				{
					next_means[i][d] /= counts[i];
				}
				memcpy(m_means[i], next_means[i], sizeof(PIXTYPE) * m_dimNum);
			}
		}

		// Terminal conditions
		iterNum++;
		if(fabs(lastCost - currCost) < m_endError * lastCost)
		{
			unchanged++;
		}
		if(iterNum >= m_maxIterNum || unchanged >= 3)
		{
			loop = false;
		}
		//DEBUG
		//cout << "Iter: " << iterNum << ", Average Cost: " << currCost << endl;
	}

	// Output the label file
	ofstream labelFile(labelFileName, ios_base::binary);
	assert(labelFile);

	labelFile.write((char*)&size, sizeof(int));
	sampleFile.clear();
	sampleFile.seekg(sizeof(int) * 2, ios_base::beg);

	for(int i = 0; i < size; i++)
	{
		sampleFile.read((char*)x, sizeof(PIXTYPE) * m_dimNum);
		GetLabel(x, &label);
		labelFile.write((char*)&label, sizeof(int));
	}

	sampleFile.close();
	labelFile.close();

	delete[] counts;
	delete[] x;
	for(int i = 0; i < m_clusterNum; i++)
	{
		delete[] next_means[i];
	}
	delete[] next_means;
}

//N 为特征向量数
void KMeans::Cluster(PIXTYPE *data, int N, int *Label)
{
	int size = 0;
	size = N;

	assert(size >= m_clusterNum);

	// Initialize model
	Init(data,N);

	// Recursion
	PIXTYPE* x = new PIXTYPE[m_dimNum];	// Sample data
	int label = -1;		// Class index
	PIXTYPE iterNum = 0;
	PIXTYPE lastCost = 0;
	PIXTYPE currCost = 0;
	int unchanged = 0;
	bool loop = true;
	int* counts = new int[m_clusterNum];
	PIXTYPE** next_means = new PIXTYPE*[m_clusterNum];	// New model for re-estimation
	for(int i = 0; i < m_clusterNum; i++)
	{
		next_means[i] = new PIXTYPE[m_dimNum];
	}

	while(loop)
	{
	    //clean buffer for classification
		memset(counts, 0, sizeof(int) * m_clusterNum);
		for(int i = 0; i < m_clusterNum; i++)
		{
			memset(next_means[i], 0, sizeof(PIXTYPE) * m_dimNum);
		}

		lastCost = currCost;
		currCost = 0;

		// Classification
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < m_dimNum; j++)
				x[j] = data[i*m_dimNum+j];

			currCost += GetLabel(x, &label);

			counts[label]++;
			for(int d = 0; d < m_dimNum; d++)
			{
				next_means[label][d] += x[d];
			}
		}
		currCost /= size;

		// Re-estimation
		for(int i = 0; i < m_clusterNum; i++)
		{
			if(counts[i] > 0)
			{
				for(int d = 0; d < m_dimNum; d++)
				{
					next_means[i][d] /= counts[i];
				}
				memcpy(m_means[i], next_means[i], sizeof(PIXTYPE) * m_dimNum);
			}
		}

		// Terminal conditions
		iterNum++;
		if(fabs(lastCost - currCost) < m_endError * lastCost)
		{
			unchanged++;
		}
		if(iterNum >= m_maxIterNum || unchanged >= 3)
		{
			loop = false;
		}

		//DEBUG
		//cout << "Iter: " << iterNum << ", Average Cost: " << currCost << endl;
	}

	// Output the label file
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < m_dimNum; j++)
            x[j] = data[i*m_dimNum+j];
		GetLabel(x,&label);
		Label[i] = label;
	}
	delete[] counts;
	delete[] x;
	for(int i = 0; i < m_clusterNum; i++)
	{
		delete[] next_means[i];
	}
	delete[] next_means;
}
struct sortnode 
{
	int index;
	PIXTYPE value;
	sortnode()
	{
		index=0;
		value=0;
	}
};
bool myfunction (sortnode i,sortnode j) { return (i.value>j.value); }

void KMeans::Init(PIXTYPE *data, int N)
{
	int size = N;

	if(m_initMode ==  InitRandom)
	{
		int inteval = size / m_clusterNum;
		PIXTYPE* sample = new PIXTYPE[m_dimNum];

		// Seed the random-number generator with current time
		srand((unsigned)time(NULL));

		for(int i = 0; i < m_clusterNum; i++)
		{
			int select = inteval * i + (inteval - 1) * rand() / RAND_MAX;
			for(int j = 0; j < m_dimNum; j++)
				sample[j] = data[select*m_dimNum+j];
			memcpy(m_means[i], sample, sizeof(PIXTYPE) * m_dimNum);
		}

		delete[] sample;
	}
	else if(m_initMode == InitUniform)
	{
		PIXTYPE* sample = new PIXTYPE[m_dimNum];

		for(int i = 0; i < m_clusterNum; i++)
		{
			int select = i * 255 / m_clusterNum;//swf change size to 255 20140316 for image processing
			for(int j = 0; j < m_dimNum; j++)
				sample[j] = data[select*m_dimNum+j];
			memcpy(m_means[i], sample, sizeof(PIXTYPE) * m_dimNum);
		}

		delete[] sample;
	}
	else if(m_initMode == InitManual)
	{
		// Do nothing
	}
	else if (m_initMode == FastMode) //swf change the mode for speed up and make the seeds near the centers
	{
		PIXTYPE *hisgram= new PIXTYPE[255];
		sortnode *node= new sortnode[255];
		for (int j=0;j<255;j++)
		{
			hisgram[j] = 0;
			//node[j].index = j;

		}
		for (int i=0;i < 989*1241*20; i++)
		{
			hisgram[(int)data[i]]++;
			

		}
		for (int j = 0; j < 255; j++)
		{
			node[j].index = j;
			node[j].value=hisgram[j];

		}
		std::vector<sortnode> hitsort(node,node+255);
		std::sort(hitsort.begin(),hitsort.end(),myfunction);
		PIXTYPE* sample = new PIXTYPE[m_dimNum];

		for(int i = 0; i < m_clusterNum; i++)
		{
			for(int j = 0; j < m_dimNum; j++)
				sample[j] = hitsort[i].index;
			memcpy(m_means[i], sample, sizeof(PIXTYPE) * m_dimNum);
		}

		delete[] sample;
	}
}

void KMeans::Init(ifstream& sampleFile)
{
	int size = 0;
	sampleFile.seekg(0, ios_base::beg);
	sampleFile.read((char*)&size, sizeof(int));

	if(m_initMode ==  InitRandom)
	{
		int inteval = size / m_clusterNum;
		PIXTYPE* sample = new PIXTYPE[m_dimNum];

		// Seed the random-number generator with current time
		srand((unsigned)time(NULL));

		for(int i = 0; i < m_clusterNum; i++)
		{
			int select = inteval * i + (inteval - 1) * rand() / RAND_MAX;
			int offset = sizeof(int) * 2 + select * sizeof(PIXTYPE) * m_dimNum;

			sampleFile.seekg(offset, ios_base::beg);
			sampleFile.read((char*)sample, sizeof(PIXTYPE) * m_dimNum);
			memcpy(m_means[i], sample, sizeof(PIXTYPE) * m_dimNum);
		}

		delete[] sample;
	}
	else if(m_initMode == InitUniform)
	{
		PIXTYPE* sample = new PIXTYPE[m_dimNum];

		for (int i = 0; i < m_clusterNum; i++)
		{
			int select = i * size / m_clusterNum;
			int offset = sizeof(int) * 2 + select * sizeof(PIXTYPE) * m_dimNum;

			sampleFile.seekg(offset, ios_base::beg);
			sampleFile.read((char*)sample, sizeof(PIXTYPE) * m_dimNum);
			memcpy(m_means[i], sample, sizeof(PIXTYPE) * m_dimNum);
		}

		delete[] sample;
	}
	else if(m_initMode == InitManual)
	{
		// Do nothing
	}
}

PIXTYPE KMeans::GetLabel(const PIXTYPE* sample, int* label)
{
	PIXTYPE dist = -1;
	for(int i = 0; i < m_clusterNum; i++)
	{
		PIXTYPE temp = CalcDistance(sample, m_means[i], m_dimNum);
		if(temp < dist || dist == -1)
		{
			dist = temp;
			*label = i;
		}
	}
	return dist;
}

PIXTYPE KMeans::CalcDistance(const PIXTYPE* x, const PIXTYPE* u, int dimNum)
{
	PIXTYPE temp = 0;
	for(int d = 0; d < dimNum; d++)
	{
		temp += (x[d] - u[d]) * (x[d] - u[d]);
	}
	return sqrt(temp);
}

ostream& operator<<(ostream& out, KMeans& kmeans)
{
	out << "<KMeans>" << endl;
	out << "<DimNum> " << kmeans.m_dimNum << " </DimNum>" << endl;
	out << "<ClusterNum> " << kmeans.m_clusterNum << " </CluterNum>" << endl;

	out << "<Mean>" << endl;
	for(int i = 0; i < kmeans.m_clusterNum; i++)
	{
		for(int d = 0; d < kmeans.m_dimNum; d++)
		{
			out << kmeans.m_means[i][d] << " ";
		}
		out << endl;
	}
	out << "</Mean>" << endl;

	out << "</KMeans>" << endl;
	return out;
}
