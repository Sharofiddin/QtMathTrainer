#include "mylcdmonitor.h"

MyLCDMonitor::MyLCDMonitor()
{

}

int *MyLCDMonitor::getNums() const
{
    return nums;
}

void MyLCDMonitor::setNums(int *value)
{
    nums = value;
}

int MyLCDMonitor::getCurrentIndex() const
{
    return currentIndex;
}

void MyLCDMonitor::setCurrentIndex(int value)
{
    currentIndex = value;
}
