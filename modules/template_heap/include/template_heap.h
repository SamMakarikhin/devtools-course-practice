// Copyright 2020 Pauzin Leonid & Myshkin Andrey
#ifndef MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_H_
#define MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_H_

#include <vector>
#include <algorithm>

template <typename T>
class THeap {
 public:
  THeap() = default;
  THeap(const THeap<T>& heap) { vector = heap.vector; }
  explicit THeap(const std::vector<T>& buffer);
  void Push(T value);
  T Remove();
  size_t GetSize();
  THeap<T>& operator = (const THeap<T>& heap_) = default;
  std::vector<T> HeapSorting();

 private:
  std::vector<T> vector;

  void Emersion();
  int GetParent(int child);
  void Immersion();
  int GetLeftChild(int parent);
  int GetRightChild(int parent);
  void Swap(int child, int parent);
};

template<typename T>
THeap<T>::THeap(const std::vector<T>& buffer) {
    for (size_t i = 0; i < buffer.size(); i++) {
        vector.push_back(buffer[i]);
        Emersion();
    }
}

template<typename T>
void THeap<T>::Push(T value) {
  vector.push_back(value);
  Emersion();
}

template<typename T>
void THeap<T>::Emersion() {
  int child = vector.size() - 1;
  int parent = GetParent(child);

  while (vector[child] > vector[parent] && child >= 0 && parent >= 0) {
    Swap(child, parent);
    child = parent;
    parent = GetParent(child);
  }
}

template <typename T>
int THeap<T>::GetParent(int child) {
  if (child > 0 && child % 2 == 0)
    return child / 2 - 1;
  else
    return child / 2;
}

template <typename T>
T THeap<T>::Remove() {
  if (vector.size() == 0) {
      throw "The heap does not contain items";
  }
  int child = vector.size() - 1;
  Swap(child, 0);
  T value = vector.back();
  vector.pop_back();
  Immersion();
  return value;
}

template <typename T>
void THeap<T>::Swap(int child, int parent) {
  std::swap(vector[child], vector[parent]);
}

template <typename T>
void THeap<T>::Immersion() {
  int parent = 0;

  while (true) {
    int left = GetLeftChild(parent);
    int right = GetRightChild(parent);
    int length = vector.size();
    int largest = parent;

    if ((left < length) && (vector[left] > vector[largest]))
      largest = left;
    if ((right < length) && (vector[right] > vector[largest]))
      largest = right;
    if (largest != parent) {
      Swap(largest, parent);
      parent = largest;
    } else {
      break;
    }
  }
}

template <typename T>
int THeap<T>::GetLeftChild(int parent) {
  int child = 2 * parent + 1;
  return child;
}

template <typename T>
int THeap<T>::GetRightChild(int parent) {
  int child = 2 * parent + 2;
  return child;
}

template <typename T>
size_t THeap<T>::GetSize() {
  return vector.size();
}

template <typename T>
std::vector<T> THeap<T>::HeapSorting() {
    THeap<T> copy(vector);
    std::vector<T> result_vector(GetSize());
    for (size_t index = 0; index < result_vector.size(); ++index) {
        result_vector[index] = copy.Remove();
    }
    return result_vector;
}

#endif  // MODULES_TEMPLATE_HEAP_INCLUDE_TEMPLATE_HEAP_H_
