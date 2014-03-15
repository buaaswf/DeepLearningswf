#include <iostream>
#include "k-meansv2.h"
#include "vol_math_RawImage.h"
using namespace std;
ImageVolume * testinterface()
{
	//int l = 4338, m = 3353, n = 3;
	int l = 281, m = 481, n =2; 
	RawImage test;
	unsigned char * indata = new unsigned char [l*m*n];
	test.readImage(indata,"F:\\lab\\VTKproj\\mig.raw",l*m*n*sizeof(unsigned char));
	unsigned char * outdata = new unsigned char[l*m*n]; 
	ImageVolume *src = new ImageVolume(l,m,n,1,indata,false);
	ImageVolume *ret = new ImageVolume(l,m,n,1,outdata,false);
	test.writeImagesesmicarray(ret->Data ,ret->Width,ret->Height,ret->Depth);
	delete outdata;
	return ret;


}
int main()
{
    double data[] = {
        0.0, 0.2, 0.4,
        0.3, 0.2, 0.4,
        0.4, 0.2, 0.4,
        0.5, 0.2, 0.4,
        5.0, 5.2, 8.4,
        6.0, 5.2, 7.4,
        4.0, 5.2, 4.4,
        10.3, 10.4, 10.5,
        10.1, 10.6, 10.7,
        11.3, 10.2, 10.9
    };
		int l = 281, m = 481, n =2; 
	//RawImage test;
	//unsigned char* indata=new unsigned char [l*m*n];
	//test.readImage(indata,"F:\\lab\\VTKproj\\mig.raw",l*m*n*sizeof(unsigned char));
	
    const int size = l*m*n; //Number of samples
    const int dim = 1;   //Dimension of feature
    const int cluster_num = 4; //Cluster number

    KMeans* kmeans = new KMeans(dim,cluster_num);
    int* labels = new int[size];
    kmeans->SetInitMode(KMeans::InitUniform);
	kmeans->Cluster(data,size,labels);

	for(int i = 0; i < size; ++i)
	{
	    printf("%f, %f, %f belongs to %d cluster\n", data[i*dim+0], data[i*dim+1], data[i*dim+2], labels[i]);
	}

	delete []labels;
	delete kmeans;
	system("pause");
    return 0;
}
