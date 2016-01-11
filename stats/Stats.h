#ifndef Stats_h
#define Stats_h

class Stats
{
  public:
    Stats(int bufferSize);
    int median(int value);
    int mean(int value);
  private:
    int _bufferSize;
    int _values [10];
    int _currentIndex;
    int _numValues;
}

#endif
