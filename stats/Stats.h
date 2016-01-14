#ifndef Stats_h
#define Stats_h

class Stats
{
  public:
    Stats(int bufferSize);
    int median(int value);
    int mean(int value);
    int medianFive(int value);
    static const int maxSize = 10;
  private:
    int _bufferSize;
    int _values [maxSize];
    int _currentIndex;
    int _numValues;
    int _runningTotal;
    void storeValue(int value);
    void sort(int a, int b, int toa, int tob);
};

#endif
