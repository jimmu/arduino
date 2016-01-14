#include "Stats.h"
// This is compilable with gcc and has a main
// method for testing purposes.
// Compile it, run it, look at the exit code.
// gcc Stats.cpp; ./a.out; echo $?

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
    _runningTotal -= _values[_currentIndex];
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

int testMean(int buffSize){
  Stats foo(buffSize);
  int x = foo.mean(1);
  x = foo.mean(10);
  x = foo.mean(10);
  x = foo.mean(12);
  return x;
}

int main(int argc, char** argv){
  //return testMean(2); //11
  //return testMean(3); //10
  return testMean(4); //8
}
