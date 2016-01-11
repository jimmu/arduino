#ifndef Stats_h
#define Stats_h

#include "Arduino.h"

class Stats
{
  public:
    Stats(int bufferSize);
    int median(int value);
    int mean(int value);
  private:
    int _bufferSize;
    int[10] _values;
    int _currentIndex;
    int _numValues;
}

#endif
