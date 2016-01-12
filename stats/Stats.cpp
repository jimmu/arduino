#include "Stats.h"

Stats::Stats(int bufferSize) {
  _bufferSize = bufferSize;
  if (_bufferSize > maxSize){
    _bufferSize = maxSize;
  }
  _numValues = 0;
  _currentIndex = 0;
  _runningTotal = 0;
}

int Stats::median(int value){
  return 0;
}

int Stats::mean(int value){
  _runningTotal += value;
  // If the buffer is already full, take the value which 
  // is about to be overwritten and subtract it from the running total.
  if (_numValues >= _bufferSize){
    int oldestIndex = _currentIndex-1;
    if (oldestIndex == -1) {
      oldestIndex += _bufferSize;
    }
    _runningTotal -= _values[oldestIndex];
  }
  _values[_currentIndex] = value;
  _currentIndex++;
  if (_currentIndex == _bufferSize){
    _currentIndex = 0;
  }
  _numValues++;
  int divisor = (_numValues < _bufferSize)? _numValues : _bufferSize;
  return _runningTotal/divisor;
}
