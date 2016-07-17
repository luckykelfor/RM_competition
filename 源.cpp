#include<iostream>
#include<ios>
#include<io.h>
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<fstream>

#include "opticalFlow.h"


using namespace std;
using namespace cv;

//
//static string descriptorVectorFile = "E:\\UAVdataset\\descriptorvector_opencvVersion.dat";
//static string testSamplesDir = "K:/ProProSpace/";
//static const Size trainingPadding = Size(0, 0); //填充值
//static const Size winStride = Size(8, 8);			//窗口步进
//
//
//
//
//static string toLowerCase(const string& in) {
//	string t;
//	for (string::const_iterator i = in.begin(); i != in.end(); ++i) {
//		t += tolower(*i);
//	}
//	return t;
//}
//
//
//static void getFilesInDirectory(const string& dirName, vector<string>& fileNames, const vector<string>& validExtensions) {
//	printf("扫描样本目录 %s\n", dirName.c_str());
//	long hFile = 0;
//	struct _finddata_t fileInfo;
//	string pathName, fullfileName;
//	string  tempPathName = pathName.assign(dirName);
//	string  tempPathName2 = pathName.assign(dirName);
//
//	//if ((hFile = _findfirst(pathName.assign(dirName).append("\\*").c_str(), &fileInfo)) == -1) {
//	if ((hFile = _findfirst(tempPathName.append("\\*").c_str(), &fileInfo)) == -1) {
//		return;
//	}
//	do {
//		if (fileInfo.attrib&_A_SUBDIR)//文件夹跳过
//			continue;
//		else
//		{
//
//			int i = string(fileInfo.name).find_last_of(".");
//			string tempExt = toLowerCase(string(fileInfo.name).substr(i + 1));
//
//			if (find(validExtensions.begin(), validExtensions.end(), tempExt) != validExtensions.end())
//			{
//
//
//				fullfileName = tempPathName2 + (string(fileInfo.name));
//				//  cout<<"有效文件： '%s'\n"<< fullfileName << endl;
//				fileNames.push_back((cv::String)fullfileName);
//
//
//
//			}
//			else
//			{
//				cout << "不是图像文件，跳过: '%s'\n" << fileInfo.name << endl;
//			}
//
//
//		}
//
//	} while (_findnext(hFile, &fileInfo) == 0);
//	_findclose(hFile);
//	return;
//
//}
//static void showDetections(const vector<Rect>& found, Mat& imageData) {
//	vector<Rect> found_filtered;
//	size_t i, j;
//	for (i = 0; i < found.size(); ++i) {
//		Rect r = found[i];
//		for (j = 0; j < found.size(); ++j)
//		if (j != i && (r & found[j]) == r)
//			break;
//		if (j == found.size())
//			found_filtered.push_back(r);
//	}
//	for (i = 0; i < found_filtered.size(); i++) {
//		Rect r = found_filtered[i];
//		rectangle(imageData, r.tl(), r.br(), Scalar(0, 255,255), 3);
//	}
//}
//
//static void detectTest(const HOGDescriptor& hog, const double hitThreshold, const vector<string>& testImages)
//{
//	vector<Rect> foundDetection;
//	/*for (vector<string>::const_iterator posTrainingIterator = testImages.begin(); posTrainingIterator != testImages.end(); ++posTrainingIterator)
//	{
//
//		Mat imageData = imread(*posTrainingIterator);
//
//		hog.detectMultiScale(imageData, foundDetection, 0, winStride, trainingPadding);
//
//		showDetections(foundDetection, imageData);
//
//		namedWindow("HH", 0);
//		imshow("HH", imageData);
//		waitKey(100);
//
//	}*/
//	VideoCapture vcap;
//	Mat currentFrame;
//	vcap.open("test.mp4");
//			namedWindow("HH", 1);
//	//namedWindow("人脸识别");
//	if (vcap.isOpened())
//	{
//		while (vcap.read(currentFrame))
//		{
//	//	resize(currentFrame, currentFrame,Size(230,240));
//	hog.detectMultiScale(currentFrame, foundDetection, 0, winStride, trainingPadding);
//
//			showDetections(foundDetection, currentFrame);
//						imshow("HH", currentFrame);
//			waitKey(1);
//		}
//		vcap.release();
//	}
//}
//int main()
//{
//	HOGDescriptor myHOG(Size(80, 40), Size(16, 16), Size(8, 8), Size(8, 8), 9);;
//
//	vector<float> myDetector;
//
//
//
//	static vector<string>testSamples,validExtensions;
//
//	validExtensions.push_back("jpg");
//	validExtensions.push_back("png");
//	validExtensions.push_back("bmp");
//	// </editor-fold>
//
//	// <editor-fold defaultstate="collapsed" desc="Read image files">
//	getFilesInDirectory(testSamplesDir, testSamples, validExtensions);
//
//	ifstream  fin_detector(descriptorVectorFile.c_str());
//	float temp;
//	//double hitThreshold;
//	vector<float> descriptorVector;//3781维的检测器参数
//	while (!fin_detector.eof())
//	{
//		fin_detector >> temp;
//		descriptorVector.push_back(temp);//放入检测器数组
//	}
//	fin_detector.close();
//	//ifstream getSample("E:/UAVdataset/MyTrainingSetAnnotation.txt");
//	////
//	////Mat src;
//	////int temp_i = 0;
//	////while (!getSample.eof())
//	////{
//	////	char roiname[260];
//	//ofstream getTrainAnno("E:/UAVdataset/VOC_2007_UAV_Train.txt");
//	//while (!getSample.eof())
//	//{
//	//	int xmin, ymin, xmax, ymax;
//	//	char fname[100];
//	//	char savedName[200];
//	//	getSample >> xmin >> ymin >> xmax >> ymax >> fname;
//	//	getTrainAnno << fname << endl;
//	//	sprintf(savedName, "E:/UAVdataset/%s.yml", fname);
//
//	//	ofstream tempF(savedName);
//	//	tempF << "%YAML:1.0" << endl << endl <<
//	//		"annotation:" << endl <<
//	//		"  folder: VOC2007" << endl <<
//	//		"  filename: \"" << fname << ".jpg\"" << endl <<
//	//		"  object: " << endl <<
//	//		"    - bndbox: {xmin: \'" << xmin << "\', ymin: \'" << ymin <<
//	//		"\', xmax: \'" << xmax << "\', ymax: \'" << ymax << "\'}" << endl <<
//	//		"      name: " << "UAV" << endl <<
//	//		"difficult: \'0\'" << endl;
//	//	tempF.close();
//
//
//
//
//	//}
//	//getTrainAnno.close();
//	//getSample.close();
//	////	for (int i = 0; i < 5; i++)
//	//	{
//	//		Point2i left_top, right_bottom;
//	//		string filename;
//	//		getSample >> left_top.x >> left_top.y >> right_bottom.x >> right_bottom.y>>filename;
//	//		src = imread(filename);
//	//		Mat ROI = src(Rect(left_top, right_bottom));
//	//		sprintf(roiname, "E:/UAVdataset/pos/roi%04d.jpg", temp_i);
//	//		imwrite(roiname, ROI);//保存文件
//	//	}
//	//	temp_i++;
//	//}
//	//getSample.close();
//
//
//	descriptorVector.pop_back();
// 
//	//ifstream readThreshold(ThresholdPath.c_str(), ios::in);
//	//readThreshold >> hitThreshold;
//	//readThreshold.close();
//	// const double hitThreshold
//	cout << "The size of Descripto Vector:" << descriptorVector.size() << endl;
//	// Set our custom detecting vector  设置为我们自己的支持向量（检测子向量）
//	myHOG.setSVMDetector(descriptorVector);
//	detectTest(myHOG, 0, testSamples);
//	return 0;
//}






int H_MIN = 0;
int H_MAX = 360;
int S_MIN =0;
int S_MAX = 255;
int V_MIN = 0;
int V_MAX = 255;

//default capure width and height 
const int FRAME_WIDTH = 640;
const int PRAME_HEIGHT = 480;
void on_trackbar(int, void*)
{
	;
}

string intToString(int number)
{
	
	string temp = "**********";
	sprintf((char*)(temp.at(0)), "%9d", number);
	return temp;
}

void createTrackbars()
{
	namedWindow("trackbars", 0);
	createTrackbar("H_MAX", "trackbars", &H_MAX, H_MAX, on_trackbar);
	createTrackbar("H_MIN", "trackbars", &H_MIN, H_MAX, on_trackbar);

	createTrackbar("S_MAX", "trackbars", &S_MAX, S_MAX, on_trackbar);
	createTrackbar("S_MIN", "trackbars", &S_MIN, S_MAX, on_trackbar);

	createTrackbar("V_MAX", "trackbars", &V_MAX, V_MAX, on_trackbar);
	createTrackbar("V_MIN", "trackbars", &V_MIN, V_MAX, on_trackbar);
}

void morphOps(Mat & threshold)
{
	
	//create structing element that will be used to dilate and erode imags. The elemtne chosen here is a 3px by 3px rectangle
	Mat erodeElement = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat dilateElement = getStructuringElement( MORPH_ELLIPSE, Size(30, 30));
	
	erode(threshold, threshold, erodeElement);
	erode(threshold, threshold, erodeElement);
	dilate(threshold, threshold, erodeElement);
	dilate(threshold, threshold, erodeElement);
	;
	imshow("After Open", threshold);
}


void drawObjects(int x, int y, Mat & frame)
{

	circle(frame, Point(x, y), 10, Scalar(255, 0, 255), 2, 8, 0);
}


void trackFilteredObjects(int &x, int &y, Mat& threshold_opened, Mat & src)
{
	
	
	
	
	//These two vectors needed for output of findContours
	vector<Vec4i> hierarchy;
	//find contours of filtered image using openCV finContours function
	vector<vector<Point>>contours;
	findContours(threshold_opened, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	
	//use moments method to find our filtered object;
	double refArea = 0;
	bool objectFound = false;
	if (hierarchy.size() > 0)
	{
		int numObjects = hierarchy.size();
		
		//if numboer of objects greater than 10, probably o noisy filter
		if (numObjects < 10)
		{
			for (int ind = 0; ind >= 0; ind = hierarchy[ind][0])
			{
				
				//if the area is less than 20px by 20px, then it is probabl just noise
				//if the area is the same as the 3/2 of the image size, probably just a bad filter
				//we only want the object with the largest area so we save a reference area each iteration and compare it to the area in the next iteration
				
				std::vector<Point> approx;
				cv::approxPolyDP(contours[ind], approx, cv::arcLength(cv::Mat(contours[ind]), true)*0.02, true);
				Moments moment = moments((Mat)contours[ind]);
				double area = moment.m00;

				if (approx.size() >= 4)
				{

									
					if (area >400 && area<PRAME_HEIGHT*FRAME_WIDTH / 1.5 && area>refArea)
					{
						x = moment.m10 / area;
						y = moment.m01 / area;
						objectFound = true;
						drawContours(src, contours, ind, Scalar(255,0,255), 1, 8, hierarchy, 0, cv::Point());
						// approx.
					}
					else
						objectFound = false;
				}

			}

		//let user know you found an object 	
			if (objectFound == true)
			{
				putText(src, "Tracking Object", Point(0, 50), 2, 1, Scalar(0, 255, 0), 2);
				drawObjects(x, y, src);	
				 
			}	

				
		}
		
		else		
		{
				
			putText(src, "TOO MUCH NOISE! ADJUST FILTER", Point(0, 50), 1, 2, Scalar(0, 0, 255), 2);
					
		}

	}

}






int main()
{
	char windowName[20] = "Origin";
	char windowName1[20] = "HSV";
	char windowName2[20] = "Threshold";
	
	bool trackObjects = true;
	bool useMorphOps = true;



	Mat currentFrame;
	Mat threshold;

	Mat HSV;

	int x = 0, y = 0;// x and y locaitons

	createTrackbars();

	VideoCapture vidCap;
	vidCap.open("D:/test.MP4");
	if (vidCap.isOpened())
	while (vidCap.read(currentFrame))
	{
		//Convert to HSV colorspace;
		cvtColor(currentFrame, HSV, COLOR_BGR2HSV);
        imshow("HSV", HSV);
		//filter HSV image between values and stroe filtered image to threshold matrix
		inRange(HSV, Scalar(H_MIN, S_MIN, V_MIN), Scalar(H_MAX, S_MAX, V_MAX), threshold);
		imshow("After HSV selection", threshold);
		if (useMorphOps)
			morphOps(threshold);

		if (trackObjects)
			trackFilteredObjects(x,y,threshold,currentFrame);

		imshow(windowName, currentFrame);
		
	//	imshow(windowName2, threshold);
         waitKey(80);
	}

	

	return 0;
}