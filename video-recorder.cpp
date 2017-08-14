#include "opencv2/opencv.hpp"

#include <iostream>
#include <stdio.h>
#include <chrono>
#include <ctime>

using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
    VideoCapture video0;
    video0.open("/dev/video0");

    if (!video0.isOpened()) {
        cerr << "ERROR: Unable to open device" << endl;
        return 1;
    }

    Size resolution = Size(640, 480);
    bool isColor = true;
    int codec = CV_FOURCC('F','F', 'V', '1');
    double fps = 25.0;
    string filename = "./out.mp4";

    VideoWriter writer;
    writer.open(filename, codec, fps, resolution);

    if (!writer.isOpened()) {
        cerr << "ERROR: Could not open output file for write" << endl;
        return 1;
    }

    unsigned int totalFrames = 10 * fps;
    unsigned int qtdFrames = 0;
    Mat frame;

    cout << "Start recording.." << endl;
    for(;;) {
        video0.read(frame);
        writer.write(frame);
        qtdFrames++;

        if (qtdFrames == totalFrames) {
            break;
        }
    }
    cout << "End recording" << endl;

    return 0;
}
