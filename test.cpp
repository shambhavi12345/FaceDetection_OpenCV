#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect/objdetect.hpp>
#include<iostream>

using namespace std;
using namespace cv;


int main() 
{

	VideoCapture video(0);
	CascadeClassifier facedetect;

	Mat img;
	facedetect.load("haarcascade_frontalface_default.xml");
	

	while (true) {

		video.read(img);
		vector<Rect> faces;
		facedetect.detectMultiScale(img,faces,1.1,5);

		cout<<faces.size()<<endl;


		for (int i=0; i<faces.size(); i++)
		{
			rectangle(img,faces[i].tl(),faces[i].br(),Scalar(50,50,255),3);

			rectangle(img,Point(0,0),Point(280,70),Scalar(208,224,64),FILLED);

			putText(img,to_string(faces.size()) + " Face(s) Found",Point(10,40),FONT_HERSHEY_DUPLEX,1,Scalar(255,255,255),1);
		
		}

		
		resize(img,img, Size(1200,700));
		imshow("Image Window", img);
		waitKey(1);

	}
}

