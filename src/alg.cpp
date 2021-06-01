// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H
#define INCLUDE_TPQUEUE_H
#include <cassert>

template<typename T>
class TPQueue {
  private:
  T *arr;
  int count;
  int size;
  int begin, end;
  int forward(int index) {
    int sum = ++index;
    if (sum > size)
      sum -= size + 1;
    return sum;
  }
  int back(int index) {
    int sum = --index;
    if (sum < 0)
      sum += size +1;
    return sum;
  }
  public:
  TPQueue() :
  size(100),
  begin(0), end(0), count(0) {
    arr = new T[size +1];
  }
  ~TPQueue() {
    delete[] arr;
  }
  void push(const T &item) {
    assert(count < size);
    int finale  end;
    while (begin != finale && item.prior > arr[back(finale)].prior) {
      arr[finale] = arr[back(finale)];
      finale = back(finale);
    }
    arr[finale] = item;
    end = forward(end);
    count++;
  }
  T pop() {
    assert(count > 0);
    T item = arr[begin];
    count--;
    begin = forward(begin);
    return item;
  }
  T get() const {
    assert(count > 0);
    return arr[begin];
  }
  bool isEmpty() const {
    return count == 0;
  }
  bool isFull() const {
    return count == size;
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif
