#include "Stats.h"

Stats::Stats(int bufferSize) {
  _bufferSize = bufferSize;
  if (_bufferSize > 10){
    _bufferSize = 10;
  }
  _numValues = 0;
  _currentIndex = 0;
}

int median(int value){
  return 0;
}

int mean(int value){
  _values[_currentIndex] = value;
  _currentIndex++;
  if (_currentIndex == _bufferSize){
    _currentIndex = 0;
  }
  _numValues++;
  // Naiive way to get the total. Sum everything up every time.
  int sum = 0;
  for (int i=0; i<=_bufferSize && i<=_numValues){
    sum += _values[i];
  }
  int divisor = (_numValues < _bufferSize)? _numValues : _bufferSize;
  return sum/divisor;
}
