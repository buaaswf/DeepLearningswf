///*
//K-means �㷨
//@ buaa swf pattern recognition lab
//*/
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//typedef struct  //��ṹ��
//{
//  double x;  //����1
//  double y;  //����2
//}Point;
//void main()
//{
//	int i=0;
//   vector<Point> vecPoint;   //���е�
//   vector<Point> vecCenter;  //���ĵ�
//   vector<vector<Point> > vecCluster;  //��1��2��3
//   double tempM[11][2]={2.0,10.0,2.0,5.0,8.0,4.0,5.0,8.0,7.0,5.0,6.0,4.0,1.0,2.0,4.0,9.0,7.0,3.0,1.0,3.0,3.0,9.0};
//   Point temp;
//   for(int i=0;i<11;i++) //��ʼ��������
//   {
//      temp.x=tempM[i][0];
//      temp.y=tempM[i][1];
//      vecPoint.push_back(temp);
//   }
//   //��ʼ�����ĵ�
//   temp.x=2.0;
//   temp.y=10.0;
//   vecCenter.push_back(temp);
//   temp.x=5.0;
//   temp.y=8.0;
//   vecCenter.push_back(temp);
//   temp.x=1.0;
//   temp.y=2.0;
//   vecCenter.push_back(temp);
//   double distance; //����
//   double mindistance;
//   unsigned int flag;  //����id
//   unsigned int round=1;  //�����ִ�;
//   double errorSum1;  //���ƽ����
//   double errorSum2;  //���ƽ����
//   vector<Point> tempvec;
//   //double distance1,distance2,distance3;
//   for(int i=0;i<3;i++)   //��ʼ��Cluster vector
//   {
//      vecCluster.push_back(tempvec);
//   }
//   do
//   {
//      for(int i=0;i<vecCluster.size();i++)  //���ÿһ���ض�Ӧ������
//      {
//         vecCluster[i].clear();
//      }
//      for(int i=0;i<11;i++)    //�����ݶ�����й���
//      {
//         mindistance=sqrt(pow(vecPoint[i].x-vecCenter[0].x,2.0)+pow(vecPoint[i].y-vecCenter[0].y,2.0));
//         flag=0;
//         for(int k=1;k<3;k++)   //���������ıȽϾ���   
//         {
//            distance=sqrt(pow(vecPoint[i].x-vecCenter[k].x,2.0)+pow(vecPoint[i].y-vecCenter[k].y,2.0));
//            if(distance<mindistance)  //��ôص����ĸ���
//            {
//               flag=k;
//               mindistance=distance;
//            }
//         }
//         vecCluster[flag].push_back(vecPoint[i]);  //���ൽ��Ӧ�Ĵ�
//      }// end of for(i=0;i<11;i++)
//      
//      cout<<"-------------��"<<round<<"�λ��ֽ��:-------------"<<endl;
//      for(i=0;i<vecCluster.size();i++)  //������ִεĸ������ڵ�Ԫ��
//      {
//         cout<<"��"<<i+1<<": ";
//         for(int j=0;j<vecCluster[i].size();j++)
//         {
//            cout<<"("<<vecCluster[i][j].x<<","<<vecCluster[i][j].y<<") ";
//         }
//         cout<<"��ѡ���ĵ�:("<<vecCenter[i].x<<","<<vecCenter[i].y<<")";
//         cout<<endl;
//      }
//      
//      if(round==1)
//      {
//         //�����ʼ�Ĵ��ڱ��
//         errorSum1=0;
//         for(int k=0;k<3;k++)
//         {
//            for(i=0;i<vecCluster[k].size();i++)
//            {
//                errorSum1+=pow(vecCenter[k].x-vecCluster[k][i].x,2.0)+pow(vecCenter[k].y-vecCluster[k][i].y,2.0);
//            }
//         }
//      }
//      else
//      {
//         errorSum1=errorSum2;  //��¼��һ�εĴ��ڱ��
//      }
//      
//      round++;  //�ִμ�1
//      double sum_x,sum_y;
//      vecCenter.clear();  //���ԭ���Ĵ����ļ���
//      for(int k=0;k<3;k++)   //���¼����������
//      {
//         sum_x=0;
//         sum_y=0;
//         for(i=0;i<vecCluster[k].size();i++)
//         {
//             sum_x+=vecCluster[k][i].x;
//             sum_y+=vecCluster[k][i].y;
//         }
//         temp.x=sum_x/vecCluster[k].size();
//         temp.y=sum_y/vecCluster[k].size();
//         vecCenter.push_back(temp);  //�����µĴ�����
//      }
//      errorSum2=0;  //�����µĴ��ڱ��
//
//      
//      for(int k=0;k<3;k++)
//      {        
//         for(i=0;i<vecCluster[k].size();i++)
//         {
//            errorSum2+=pow(vecCenter[k].x-vecCluster[k][i].x,2.0)+pow(vecCenter[k].y-vecCluster[k][i].y,2.0);
//         }
//      }
//      /*
//      distance1=fabs(vecCenter[0].x-vecCenter[3].x)+fabs(vecCenter[0].y-vecCenter[3].y);
//      distance2=fabs(vecCenter[1].x-vecCenter[4].x)+fabs(vecCenter[1].y-vecCenter[4].y);
//      distance3=fabs(vecCenter[2].x-vecCenter[5].x)+fabs(vecCenter[2].y-vecCenter[5].y);
//      vecCenter.erase(vecCenter.begin(),vecCenter.begin()+3);
//      */
//   }while(fabs(errorSum2-errorSum1)>0.0000000001);   //���ڱ���Ƿ������ȶ�
//    //}while(distance1||distance2||distance3);
//    cout<<endl<<">>>�����ĵ��Ѳ������ڱ���������ȶ�,���ֽ���!!!"<<endl;
//    cout<<"------------���վ�����:-------------"<<endl;
//    for(int i=0;i<vecCluster.size();i++)  //������յľ�����
//    {
//       cout<<"��"<<i+1<<": ";
//       for(int j=0;j<vecCluster[i].size();j++)
//       {
//          cout<<"("<<vecCluster[i][j].x<<","<<vecCluster[i][j].y<<") ";
//       }
//       cout<<endl;
//    }
//}