#if 1
#ifdef _CH_
#pragma package
#endif

#ifndef _EiC
#include "opencv/cv.h"
#include "opencv/highgui.h"
#endif

char wndname[] = "Edge";
char tbarname[] = "Threshold";
int edge_thresh = 1;

IplImage *image = 0, *cedge = 0, *gray = 0, *edge = 0;

// ����������� callback ����
void on_trackbar(int h)
{
	cvSmooth( gray, edge, CV_BLUR, 3, 3, 0 );
	cvNot( gray, edge );

	// �ԻҶ�ͼ����б�Ե���
	cvCanny(gray, edge, (float)edge_thresh, (float)edge_thresh*3, 3);
	cvZero( cedge );
	// copy edge points
	cvCopy( image, cedge, edge );
	// ��ʾͼ��
	cvShowImage(wndname, cedge);
}

int main( int argc, char** argv )
{
	//char* filename = argc == 2 ? argv[1] : (char*)"fruits.jpg";

	//if( (image = cvLoadImage( filename, 1)) == 0 )
	//	return -1;
	CvCapture* capture = 0;
	capture = cvCaptureFromCAM(1);
	if(!capture)
	{
		fprintf(stderr,"����Ƶ�ļ�����%s\n");
		return -2;
	}

	if( !cvGrabFrame( capture ))
		return -1;
	image = cvRetrieveFrame( capture );

	// Create the output image
	cedge = cvCreateImage(cvSize(image->width,image->height), IPL_DEPTH_8U, 3);

	// ����ɫͼ��ת��Ϊ�Ҷ�ͼ��
	gray = cvCreateImage(cvSize(image->width,image->height), IPL_DEPTH_8U, 1);
	edge = cvCreateImage(cvSize(image->width,image->height), IPL_DEPTH_8U, 1);
	cvCvtColor(image, gray, CV_BGR2GRAY);

	// Create a window
	cvNamedWindow(wndname, 1);

	// create a toolbar
	cvCreateTrackbar(tbarname, wndname, &edge_thresh, 100, on_trackbar);

	// Show the image
	on_trackbar(0);

	// Wait for a key stroke; the same function arranges events processing
	cvWaitKey(0);
	cvReleaseImage(&image);
	cvReleaseImage(&gray);
	cvReleaseImage(&edge);
	cvDestroyWindow(wndname);

	return 0;
}

#ifdef _EiC
main(1,"edge.c");
#endif

#else
///����ʶ��
#include "opencv/cv.h" 
#include "opencv/highgui.h"

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 
#include <math.h> 
#include <float.h> 
#include <limits.h> 
#include <time.h> 
#include <ctype.h>

#ifdef _EiC 
#define WIN32 
#endif

static CvMemStorage* storage = 0; 
static CvHaarClassifierCascade* cascade = 0;

void detect_and_draw( IplImage* image );

const char* cascade_name = 
"haarcascade_frontalface_alt.xml"; 
/*    "haarcascade_profileface.xml";*/

int main( int argc, char** argv ) 
{ 
	cascade_name = "haarcascade_frontalface_alt2.xml"; 
	cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 ); 

	if( !cascade ) 
	{ 
		fprintf( stderr, "ERROR: Could not load classifier cascade\n" ); 
		return -1; 
	} 
	storage = cvCreateMemStorage(0); 
	cvNamedWindow( "result", CV_WINDOW_AUTOSIZE ); 

	//const char* filename = "Lena.jpg"; 
	//IplImage* image = cvLoadImage( filename, 1 );
	
	CvCapture* capture = 0;
	capture = cvCaptureFromCAM(1);
	if(!capture)
	{
		fprintf(stderr,"����Ƶ�ļ�����%s\n");
		return -2;
	}
	if( capture )
	{
		//cvNamedWindow( "image", CV_WINDOW_AUTOSIZE );
		for(;;)
		{
			IplImage* image;
			if( !cvGrabFrame( capture ))
				break;
			image = cvRetrieveFrame( capture );
			if( image )
			{ 
				detect_and_draw( image ); 
				cvWaitKey(0); 
				//cvReleaseImage( &image );   
			}
		}
	}

	cvDestroyWindow("result"); 

	return 0; 
}


void detect_and_draw(IplImage* img ) 
{ 
	double scale=1.2; 
	static CvScalar colors[] = { 
		{{0,0,255}},{{0,128,255}},{{0,255,255}},{{0,255,0}}, 
		{{255,128,0}},{{255,255,0}},{{255,0,0}},{{255,0,255}} 
	};//Just some pretty colors to draw with

	//Image Preparation 
	// 
	IplImage* gray = cvCreateImage(cvSize(img->width,img->height),8,1); 
	IplImage* small_img=cvCreateImage(cvSize(cvRound(img->width/scale),cvRound(img->height/scale)),8,1); 
	cvCvtColor(img,gray, CV_BGR2GRAY); 
	cvResize(gray, small_img, CV_INTER_LINEAR);

	cvEqualizeHist(small_img,small_img); //ֱ��ͼ����

	//Detect objects if any 
	// 
	cvClearMemStorage(storage); 
	double t = (double)cvGetTickCount(); 
	CvSeq* objects = cvHaarDetectObjects(small_img, 
		cascade, 
		storage, 
		1.1, 
		2, 
		0/*CV_HAAR_DO_CANNY_PRUNING*/, 
		cvSize(30,30));

	t = (double)cvGetTickCount() - t; 
	printf( "detection time = %gms\n", t/((double)cvGetTickFrequency()*1000.) );

	//Loop through found objects and draw boxes around them 
	for(int i=0;i<(objects? objects->total:0);++i) 
	{ 
		CvRect* r=(CvRect*)cvGetSeqElem(objects,i); 
		cvRectangle(img, cvPoint(r->x*scale,r->y*scale), cvPoint((r->x+r->width)*scale,(r->y+r->height)*scale), colors[i%8]); 
	} 
	for( int i = 0; i < (objects? objects->total : 0); i++ ) 
	{ 
		CvRect* r = (CvRect*)cvGetSeqElem( objects, i ); 
		CvPoint center; 
		int radius; 
		center.x = cvRound((r->x + r->width*0.5)*scale); 
		center.y = cvRound((r->y + r->height*0.5)*scale); 
		radius = cvRound((r->width + r->height)*0.25*scale); 
		cvCircle( img, center, radius, colors[i%8], 3, 8, 0 ); 
	}

	cvShowImage( "result", img ); 
	cvReleaseImage(&gray); 
	cvReleaseImage(&small_img); 
}
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#include "opencv/cv.h"
#include "opencv/highgui.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "windows.h"
//#include <iostream.h>
//using namespace std;
double TrianglArea( int x1,int y1,int x2, int y2, int x3,int y3);
double SquArea(int x1,int y1,int x2, int y2, int x3,int y3,int x4,int y4);
void detect_face(IplImage* dst_img,int* count);
// various tracking parameters (in seconds)
const double MHI_DURATION = 1;
//const double MAX_TIME_DELTA = 0.5;
//const double MIN_TIME_DELTA = 0.05;
const int    N = 3;

//
const int CONTOUR_MAX_AERA = 160;

// ring image buffer
IplImage **buf = 0;
int last = 0;
int nFrmnum=1;
// ��ʱͼ�����
IplImage *mhi = 0;                                                                 // MHI: �˶���ʷͼ��

//CvFilter filter = CV_GAUSSIAN_5x5;                                     //����5x5�ĸ�˹�˲�ģ��
CvConnectedComp *cur_comp, min_comp;
CvConnectedComp comp;
CvMemStorage *storage;
CvPoint pt[4];
//�����ĸ���Ȥ�������
IplImage* dst_img1=0;                                                           //�������Ȥ����ͼ��ָ��
//CvMemStorage *stor1;
//CvSeq *cont1;
IplImage *sub_buy=0;
//IplImage* sub_buy=0;
//  ������
//  img �C ������Ƶ֡
//  dst �C �����
void  update_mhi( IplImage* img, IplImage* dst, int diff_threshold )
{
	double timestamp = clock()/CLOCKS_PER_SEC;            // ��ȡ��ǰʱ��
	CvSize size = cvSize(img->width,img->height);            // ��ȡ��ǰ֡�Ĵ�С
	int i, j, idx1, idx2;
	int danger_x[4];															   //����Σ������ı߽綥������
	int danger_y[4];
	int obj_x[100][4];
	int obj_y[100][4];
	int objArea=0;
	int numobj=0;                                                             //�����⵽��Ŀ������
	double ratio1,ratio2;
	//int danger_x2;
	//int danger_y2;
	//int danger_x3;
	//int danger_y3;
	//int danger_x4;
	//int danger_y4;
	int danger_width=60;                                                                  //����Σ������Ŀ��
	int danger_length=40;                                                                 //����Σ������ĳ���
	double T_area1,T_area2,T_area3,T_area4,Sb;                                            //������㲻�����ı������������Ҫ�ı���
	double Sf[4];
	double F_area1[100],F_area2[100],F_area3[100],F_area4[100],St;                //�������Ŀ���ı������������Ҫ�ı���
	double Sp[100][4];
	char strSaveImagename[40] = "C:\\motiondetect\\"; //!����ͼƬ��Ŀ¼��
	char strTmp[20];
	IplImage* silh;                                                           //����֡����ͼ��ָ��
	IplImage* Bimg=0;                                                    //�������Ȥ����ͼ��ָ��
	//uchar val;
	//float temp;
	IplImage* pyr = cvCreateImage( cvSize((size.width & -2)/2, (size.height & -2)/2), 8, 1 );
	CvMemStorage *stor;
	CvSeq *cont;// *result, *squares;
	//CvSeqReader reader;
	double Y;//,Cr,Cb;
	if( !mhi || mhi->width != size.width || mhi->height != size.height ) 
	{
		if( buf == 0 ) 
		{
			buf = (IplImage**)malloc(N*sizeof(buf[0]));
			memset( buf, 0, N*sizeof(buf[0]));
		}

		for( i = 0; i < N; i++ ) 
		{
			cvReleaseImage( &buf[i] );
			buf[i] = cvCreateImage( size, IPL_DEPTH_8U, 1 );
			cvZero( buf[i] );
		}
		cvReleaseImage( &mhi );
		mhi = cvCreateImage( size, IPL_DEPTH_32F, 1 );
		cvZero( mhi );                                                                           // clear MHI at the beginning
	} // end of if(mhi)

	cvCvtColor( img, buf[last], CV_BGR2GRAY );                                  // convert frame to grayscale

	idx1 = last;
	idx2 = (last + 1) % N;                                                                      // index of (last - (N-1))th frame 
	last = idx2;

	// ��֡��
	silh = buf[idx2];
	cvAbsDiff( buf[idx1], buf[idx2], silh );                                                     // ֡������

	// �Բ�ͼ������ֵ��
	cvThreshold( silh, silh, diff_threshold, 255, CV_THRESH_BINARY );          // and threshold it

	cvUpdateMotionHistory( silh, mhi, timestamp, MHI_DURATION );                                 // update MHI
	//cvCvtScale( mhi, dst, 255./MHI_DURATION,(MHI_DURATION - timestamp)*255./MHI_DURATION );    
	cvCvtScale( mhi, dst, 255./MHI_DURATION, 0 );    

	// ��ֵ�˲�������С������
	cvSmooth( dst, dst, CV_MEDIAN, 3, 0, 0, 0 );

	// ���²�����ȥ������
	cvPyrDown( dst, pyr, CV_GAUSSIAN_5x5 );
	cvDilate( pyr, pyr, NULL, 1 );						// �����Ͳ���������Ŀ��Ĳ������ն�
	cvPyrUp( pyr, dst, CV_GAUSSIAN_5x5 );
	//===================================================================================
	// ����ĳ���������ҵ�����
	// Create dynamic structure and sequence.
	stor = cvCreateMemStorage(0);
	cont = cvCreateSeq(CV_SEQ_ELTYPE_POINT, sizeof(CvSeq), sizeof(CvPoint) , stor);

	// �ҵ���������
	numobj=cvFindContours( dst, stor, &cont, sizeof(CvContour), 
		CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE, cvPoint(0,0));
	/*
	for(;cont;cont = cont->h_next)
	{   
	// Number point must be more than or equal to 6 (for cvFitEllipse_32f).        
	if( cont->total < 6 )  
	continue;

	// Draw current contour.
	cvDrawContours(img,cont,CV_RGB(255,0,0),CV_RGB(255,0,0),0,1, 8, cvPoint(0,0));
	}  // end of for-loop: "cont"
	*/
	//��ͼ�񴰿��л���һ��Σ������
	//========================================================================
	//�������ı��ζ�������ĳ�ʼ��
	danger_x[0]=0;
	danger_y[0]=0;
	danger_x[3]=0;
	danger_y[3]=0;
	danger_x[1]=danger_x[0]+danger_width;
	danger_y[1]=danger_y[0]+danger_length;
	danger_x[2]=danger_x[3]+danger_width-20;
	danger_y[2]=danger_y[3]+danger_length;
	//======================================================================

	// ֱ��ʹ��CONTOUR�еľ�����������
	CvRect rect = {640, 320, 0, 0};
	int x1 = 640, y1 = 320, x2 = 0, y2 = 0;
	for(;cont;cont = cont->h_next)
	{
		CvRect r = ((CvContour*)cont)->rect;
		if(r.height * r.width > CONTOUR_MAX_AERA) // ���С�ķ���������
		{
			x1 = r.x < x1 ? r.x : x1;
			y1 = r.y < y1 ? r.y : y1;
			x2 = r.x + r.width > x2  ? r.x + r.width : x2;
			y2 = r.y + r.height > y2  ? r.y + r.height : y2;
		}
		//obj_x[numobj][0]=r.x;
		//obj_y[numobj][0]=r.y;
		//obj_x[numobj][1]=r.x;
		//obj_y[numobj][1]=r.y;
		//obj_x[numobj][2]=r.x;
		//obj_y[numobj][2]=r.y;
		//obj_x[numobj][3]=r.x;
		//obj_y[numobj][3]=r.y;
		///*for(j=0;j<4;j++)
		//{
		//	T_area1=TrianglArea(  danger_x[j],danger_y[j],r.x+r.width,r.y, r.x,r.y);
		//	T_area2=TrianglArea(  danger_x[j],danger_y[j],r.x+r.width,r.y,r.x,r.y+r.height);
		//	T_area3=TrianglArea(  danger_x[j],danger_y[j],r.x,r.y+r.height,r.x+r.width,r.y+r.height);
		//	T_area4=TrianglArea(  danger_x[j],danger_y[j],r.x+r.width,r.y+r.height, r.x,r.y);
		//	Sf[j]=T_area1+T_area2+T_area3+T_area4;
		//}
		//Sb=SquArea( r.x,r.y,r.x+r.width,r.y,r.x,r.y+r.height,r.x+r.width,r.y+r.height);                               //���㻮����Σ����������
		////cvSetImageROI(img, cvRect( r.x,r.y,r.x+r.width,r.y+r.height));                                                //���ü������ĸ���Ȥ������
		////cvShowImage("img",img);
		//for(j=0;j<4;j++)
		//{
		//	F_area1[numobj]=TrianglArea(  danger_x[0],danger_y[0],danger_x[1],danger_y[1], obj_x[numobj][j],obj_y[numobj][j]);
		//	F_area2[numobj]=TrianglArea(  danger_x[2],danger_y[2],danger_x[1],danger_y[1], obj_x[numobj][j],obj_y[numobj][j]);
		//	F_area3[numobj]=TrianglArea(  danger_x[2],danger_y[2],danger_x[3],danger_y[3], obj_x[numobj][j],obj_y[numobj][j]);
		//	F_area4[numobj]=TrianglArea(  danger_x[3],danger_y[3],danger_x[1],danger_y[1], obj_x[numobj][j],obj_y[numobj][j]);
		//	Sp[numobj][j]=T_area1+T_area2+T_area3+T_area4;
		//}
		//St=SquArea( danger_x[3],danger_y[3],danger_x[1],danger_y[1],danger_x[2],danger_y[2],danger_x[3],danger_y[3]); */
		//cvReleaseImage( &Bimg);
		//Bimg=cvCreateImage(cvSize(r.width,r.height),IPL_DEPTH_8U,1);                                              //�½�һ��ͼ�񲢷����ڴ�
		//cvZero(Bimg);

		////cvCopy(img,dst_img1,0);
		//for(j=r.x;j<r.x+r.width;j++)
		//	for(i=r.y;i<r.y+r.height;i++)
		//	{
		//		CvScalar Rimg;
		//		CvScalar s3,s4;
		//		s3.val[0]=1;s4.val[0]=0;
		//		//if(j>=356) 
		//		//{ printf("array out of range\n");
		//		//printf("%d\n",i);
		//		//}
		//		Rimg=cvGet2D(img,i,j);
		//		//printf("%f,%f,%f\n",Rimg.val[0],Rimg.val[1],Rimg.val[2]);
		//		Y=0.299*Rimg.val[0]+0.587*Rimg.val[1]+0.114*Rimg.val[2];
		//		//Cr=(Rimg.val[0]-Y)*0.713+128;
		//		//Cb=(Rimg.val[2]-Y)*0.564+128;
		//		if(Y>=130)
		//			objArea=objArea+1;
		//	}
		//	ratio1=objArea/(r.width*r.height);//�����
		//	ratio2=r.width/r.height;//�����

		//	if(r.height * r.width > CONTOUR_MAX_AERA) // ���С�ķ���������
		//	{
		//		if (Sf[0]>Sb&&Sf[1]>Sb&&Sf[2]>Sb&&Sf[3]>Sb)//&&Sp[0]>St&&Sp[1]>St&&Sp[2]>St&&Sp[3]>St)                                                              //���˲���Σ������ʱ������߿���ʾΪ��ɫ
		//		{
		//			cvRectangle( img, cvPoint(r.x,r.y), 
		//				cvPoint(r.x + r.width, r.y + r.height),
		//				CV_RGB(0,255,0), 1, CV_AA,0);
		//			/*cvLine(img,cvPoint(danger_x[0],danger_y[0]),
		//				cvPoint(danger_x[1],danger_y[1]),
		//				CV_RGB(0,255,0), 1, CV_AA,0);
		//			cvLine(img,cvPoint(danger_x[1],danger_y[1]),
		//				cvPoint(danger_x[2],danger_y[2]),
		//				CV_RGB(0,255,0), 1, CV_AA,0);
		//			cvLine(img,cvPoint(danger_x[0],danger_y[0]),
		//				cvPoint(danger_x[3],danger_y[3]),
		//				CV_RGB(0,255,0), 1, CV_AA,0);
		//			cvLine(img,cvPoint(danger_x[3],danger_y[3]),
		//				cvPoint(danger_x[2],danger_y[2]),
		//				CV_RGB(0,255,0), 1, CV_AA,0);*/
		//		}
		//		else                                                    
		//		{   
		//			if(ratio1>=0.3&&ratio2>=0.59)                                                        //���˽���Σ������ʱ������߿���ʾΪ��ɫ������ʾ������
		//			{
		//				cvRectangle( img, cvPoint(r.x,r.y), 
		//					cvPoint(r.x + r.width, r.y + r.height),
		//					CV_RGB(0,255,0), 1, CV_AA,0);
		//				/*cvLine(img,cvPoint(danger_x[0],danger_y[0]),
		//					cvPoint(danger_x[1],danger_y[1]),
		//					CV_RGB(255,0,0), 1, CV_AA,0);
		//				cvLine(img,cvPoint(danger_x[1],danger_y[1]),
		//					cvPoint(danger_x[2],danger_y[2]),
		//					CV_RGB(255,0,0), 1, CV_AA,0);
		//				cvLine(img,cvPoint(danger_x[0],danger_y[0]),
		//					cvPoint(danger_x[3],danger_y[3]),
		//					CV_RGB(255,0,0), 1, CV_AA,0);
		//				cvLine(img,cvPoint(danger_x[3],danger_y[3]),
		//					cvPoint(danger_x[2],danger_y[2]),
		//					CV_RGB(255,0,0), 1, CV_AA,0);*/
		//				//�ڴ�������ʾԤ����ʾ��
		//				cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX,0.5,1,0,1,8);
		//				cvPutText(img,"Danger! No Entering",cvPoint(10,150),&font,CV_RGB(255,0,0));
		//				sprintf(strTmp, "SaveImage_%d.jpg", nFrmnum); //�޸ı����ͼƬ��
		//				strcat(strSaveImagename,strTmp);//ͼƬ����ӵ�ͼƬ����Ŀ¼����
		//				cvSaveImage(strSaveImagename,img);
		//				nFrmnum=nFrmnum+1;
		//			}
		//			else
		//			{
		//				cvRectangle( img, cvPoint(r.x,r.y), 
		//					cvPoint(r.x + r.width, r.y + r.height),
		//					CV_RGB(0,255,0), 1, CV_AA,0);
		//				/*cvLine(img,cvPoint(danger_x[0],danger_y[0]),
		//					cvPoint(danger_x[1],danger_y[1]),
		//					CV_RGB(0,255,0), 1, CV_AA,0);
		//				cvLine(img,cvPoint(danger_x[1],danger_y[1]),
		//					cvPoint(danger_x[2],danger_y[2]),
		//					CV_RGB(0,255,0), 1, CV_AA,0);
		//				cvLine(img,cvPoint(danger_x[0],danger_y[0]),
		//					cvPoint(danger_x[3],danger_y[3]),
		//					CV_RGB(0,255,0), 1, CV_AA,0);
		//				cvLine(img,cvPoint(danger_x[3],danger_y[3]),
		//					cvPoint(danger_x[2],danger_y[2]),
		//					CV_RGB(0,255,0), 1, CV_AA,0);*/
		//			}
		//			/* else                                                                 
		//			{

		//			cvRectangle( img, cvPoint(r.x,r.y), 
		//			cvPoint(r.x + r.width, r.y + r.height),
		//			CV_RGB(0,255,0), 1, CV_AA,0);
		//			cvLine(img,cvPoint(danger_x[0],danger_y[0]),
		//			cvPoint(danger_x[1],danger_y[1]),
		//			CV_RGB(255,0,0), 1, CV_AA,0);
		//			cvLine(img,cvPoint(danger_x[1],danger_y[1]),
		//			cvPoint(danger_x[2],danger_y[2]),
		//			CV_RGB(255,0,0), 1, CV_AA,0);
		//			cvLine(img,cvPoint(danger_x[0],danger_y[0]),
		//			cvPoint(danger_x[3],danger_y[3]),
		//			CV_RGB(255,0,0), 1, CV_AA,0);
		//			cvLine(img,cvPoint(danger_x[3],danger_y[3]),
		//			cvPoint(danger_x[2],danger_y[2]),
		//			CV_RGB(255,0,0), 1, CV_AA,0);
		//			//�ڴ�������ʾԤ����ʾ��
		//			cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX,0.5,1,0,1,8);
		//			cvPutText(img,"Danger! No Entering",cvPoint(10,150),&font,CV_RGB(255,0,0));
		//			}*/
		//		}
		//}
	}
	rect.x = x1;
	rect.y = y1;
	rect.width = x2 - x1;
	rect.height = y2 - y1;
	if (rect.x != 640 && rect.y != 320 && rect.width > 0 && rect.height > 0)
	{
		cvRectangle( img, cvPoint(rect.x,rect.y), 
			cvPoint(rect.x + rect.width, rect.y + rect.height),
			CV_RGB(0,255,0), 1, CV_AA,0);
		
		CvFont font;
		cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX,0.5,1,0,1,8);
		cvPutText(img,"Danger! Somebodt Entering",cvPoint(10,150),&font,CV_RGB(255,0,0));
	}


	cvReleaseMemStorage(&stor);
	cvReleaseImage( &pyr );
}
//��������������ĺ���
double TrianglArea( int x1,int y1,int x2, int y2, int x3,int y3)
{
	double a,b,c,s,T_area;
	a=sqrt((double)(pow((double)(x2-x1),2)+pow((double)(y2-y1),2)));
	b=sqrt((double)(pow((double)(x3-x2),2)+pow((double)(y3-y2),2)));
	c=sqrt((double)(pow((double)(x3-x1),2)+pow((double)(y3-y1),2)));
	if((a+b>c)&&(a+c>b)&&(b+c>a)) 
	{
		s=(a+b+c)/2; 
		T_area=sqrt(s*(s-a)*(s-b)*(s-c)); 
	}
	else
		//���ܹ���������
		T_area=0.;
	return T_area;
}
//�����ı��ε����
double SquArea(int x1,int y1,int x2, int y2, int x3,int y3,int x4,int y4)
{
	double T_area1,T_area2,S_area;
	T_area1=TrianglArea(  x1,y1,x2,y2, x3,y3);
	T_area2=TrianglArea( x1,y1,x4,y4, x3,y3);
	S_area=T_area1+T_area2;
	return S_area;
}
int main()
{
	IplImage* motion = 0; 
	CvCapture* capture = 0;
	//capture = cvCaptureFromAVI("C:\\Documents and Settings\\Jorhy\\Web\\RecordFiles\\2012-04-12\\92.168.1.1_01_2012041211310446.mp4");
	capture = cvCaptureFromCAM(1);
	if(!capture)
	{
		fprintf(stderr,"����Ƶ�ļ�����%s\n");
		return -2;
	}
	if( capture )
	{
		cvNamedWindow( "Motion", CV_WINDOW_AUTOSIZE );
		for(;;)
		{
			IplImage* image;
			if( !cvGrabFrame( capture ))
				break;
			image = cvRetrieveFrame( capture );
			if( image )
			{
				if( !motion )
				{
					motion = cvCreateImage( cvSize(image->width,image->height), 8, 1 );
					cvZero( motion );
					motion->origin = image->origin;
				}
			}
			//Sleep(5000);
			update_mhi( image, motion, 128);
			cvShowImage( "Motion", image );

			if( cvWaitKey(10) >= 0 )
				break;
		}
		cvReleaseCapture( &capture );
		cvDestroyWindow( "Motion" );
	}
	return 0;
}


//#else


#include <iostream>  
#include <string>  

#include <opencv2/opencv.hpp>  

int main(int argc, char* argv[])  
{  
	//std::string videoFile = "E:\\Jorhy\\���Ӿ簮�鹫Ԣ.ipart.S01E01.CHi.RMVB.720x576-δɾ����.rmvb";  

	cv::VideoCapture capture;  
	capture.open(1);  

	if (!capture.isOpened())  
	{  
		std::cout<<"read video failure"<<std::endl;  
		return -1;  
	}  


	cv::BackgroundSubtractorMOG2 mog;  

	cv::Mat foreground;  
	cv::Mat background;  

	cv::Mat frame;  
	long frameNo = 0;  
	while (capture.read(frame))  
	{  
		++frameNo;  

		std::cout<<frameNo<<std::endl;  

		// �˶�ǰ����⣬�����±���  
		mog(frame, foreground, 0.001);         

		// ��ʴ  
		cv::erode(foreground, foreground, cv::Mat());  

		// ����  
		cv::dilate(foreground, foreground, cv::Mat());  

		mog.getBackgroundImage(background);   // ���ص�ǰ����ͼ��  

		cv::imshow("video", foreground);  
		cv::imshow("background", background);  


		if (cv::waitKey(1) > 0)  
		{  
			break;  
		} 
	}  

	return 0; 
}

#endif