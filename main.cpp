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

	int l = 989, m = 1241, n = 20; 
	//int l=281,m=481,n=100;
	RawImage test;
	unsigned char* indata=new unsigned char [l*m*n];
	//test.readImage(indata,"F:\\lab\\VTKproj\\mig.raw",l*m*n*sizeof(unsigned char));//F:\3DVdata\1\mig100.3dv.raw
	test.readImage(indata,"F:\\3DVdata\\1\\mig100.3dv.raw",l*m*n*sizeof(unsigned char));//F:\3DVdata\1\mig100.3dv.raw
	float * data= new PIXTYPE[l*m*n];
	for (int i = 0 ; i < l*m*n; i++)
	{
		data[i]=(float) indata[i];

	}
    const int size = l*m*n; //Number of samples
    const int dim = 1;   //Dimension of feature
    const int cluster_num = 8; //Cluster number

    KMeans* kmeans = new KMeans(dim,cluster_num);
    int* labels = new int[size];
    kmeans->SetInitMode(KMeans::FastMode);
	kmeans->Cluster(data,size,labels);

	//for(int i = 0; i < size; ++i)
	//{
	//    printf("%f, %f, %f belongs to %d cluster\n", data[i*dim+0], data[i*dim+1], data[i*dim+2], labels[i]);
	//}
	test.writeBuf(labels,l*n*m);
	delete []labels;
	delete kmeans;
	system("pause");
    return 0;
}
