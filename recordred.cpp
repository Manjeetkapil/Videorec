#include <opencv2/core.hpp>
#include "opencv2/imgproc.hpp"
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

//only red coloured video recording with gaussian blur

int recordred(string login) {
	Mat frame,R;
    VideoCapture vcap(0);
    if (!vcap.isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return -1;
    }
    vcap >> frame;
    if (frame.empty()){
    	cerr << "ERROR! blank frame grabbed\n";
    	return -1;
	}
    ifstream fin;
    fin.open("./redrecord/read.txt", ios::app | ios::in);
    string line;
    getline(fin,line);
    bool isColor = (frame.type() == CV_8UC3);
    string path = "./redrecord/";
    path.append(login);
    path.append(line);
    string format = ".mp4";
    path.append(format);
    cout<<path<<endl;
    VideoWriter video(path, VideoWriter::fourcc('M', 'J', 'P', 'G'), 30, frame.size(), isColor);
    int count=0;
    ofstream fio;
    fio.open("./redrecord/read.txt", ios::trunc | ios::out);
    int i = atoi(line.c_str());
    i++;
    fio<<i;

    for (;;) {
        vcap >> frame;
		Mat channels[3];
		split(frame, channels);//extracting channel from frames

		channels[0] = Mat::zeros(frame.rows,frame.cols, CV_8UC1);
		channels[1] = Mat::zeros(frame.rows,frame.cols, CV_8UC1);
		merge(channels,3,frame);
		Mat channel_blurred_with_5x5_kernel;
		GaussianBlur(frame, channel_blurred_with_5x5_kernel, Size(5,5), 0);//channels[2] is red channel and applying gaussian blur on that channel
        count++;
        video.write(channel_blurred_with_5x5_kernel);
        imshow("Recording video", channel_blurred_with_5x5_kernel);
        char c = (char)waitKey(33);
        if (c == 27) break;
        if(count>300){
        	break;
        }
    }
    destroyWindow("Recording video");
    return 0;
}