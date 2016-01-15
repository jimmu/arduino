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
  storeValue(value);
  int divisor = (_numValues < _bufferSize)? _numValues : _bufferSize;
  return _runningTotal/divisor;
}

void Stats::storeValue(int value){
  _values[_currentIndex] = value;
  _currentIndex++;
  if (_currentIndex == _bufferSize){
    _currentIndex = 0;
  }
  _numValues++;
}

int Stats::medianFive(int value){
  // Store last 5 integers. Return the median of them.
  // Start off with naive approach.
  // Fancier ones exist but for a small set any gain is minimal.
  _bufferSize = 5; // Yes this belongs elsewhere.
  storeValue(value);
  // Now we know the low 5 elements of the array
  // contain the most recent 5 values.
  // Now sort them into the high 5 elements.
  int median = 0;
  if (_numValues >= _bufferSize){
    sort(0,1, 5,6);
    sort(3,4, 8,9);
    // Most of the data is now in the upper half of the array.
    sort(5,2, 5,7);
    // Now it all is.
    sort(6,7, 6,7);
    sort(5,8, 5,8);
    sort(7,8, 7,8);
    sort(6,9, 6,9);
    sort(6,7, 6,7);
    //sort(8,9, 8,9); We don't actually need to bother fully sorting the array.

    median = _values[7];
  }
  return median;
}

void Stats::sort(int a, int b, int toa, int tob){
  int lower, higher;
  if (_values[a] > _values[b]){
    lower = _values[b];
    higher = _values[a];
  }
  else {
    lower = _values[a];
    higher = _values[b];
  }
  _values[toa] = lower;
  _values[tob] = higher;
}

int testMean(int buffSize){
  Stats foo(buffSize);
  int x = foo.mean(1);
  x = foo.mean(10);
  x = foo.mean(10);
  x = foo.mean(12);
  return x;
}

int testMedianFive(){
  Stats foo(1);
  int x = foo.medianFive(1);
  x = foo.medianFive(2);
  x = foo.medianFive(3);
  x = foo.medianFive(4);
  x = foo.medianFive(50);
  x = foo.medianFive(60);
  x = foo.medianFive(61);
  return x;
}

int main(int argc, char** argv){
  //return testMean(2); //11
  //return testMean(3); //10
  //return testMean(4); //8
  return testMedianFive();
}
