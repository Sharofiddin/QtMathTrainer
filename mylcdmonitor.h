#ifndef MYLCDMONITOR_H
#define MYLCDMONITOR_H

#include <QLCDNumber>
class MyLCDMonitor:QLCDNumber
{
public:
    MyLCDMonitor();
    int *getNums() const;
    void setNums(int *value);

    int getCurrentIndex() const;
    void setCurrentIndex(int value);

private:
    int currentIndex;
    int *nums;

};

#endif // MYLCDMONITOR_H
