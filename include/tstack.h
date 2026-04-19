// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template <typename T, int size>
class TStack {
 private:
 static const int kSize = size;
  T arr[kSize];  // массив для хранения элементов
  int top;      // позиция вершины стека
 public:
  // конструктор класса
  TStack() : top(-1) {}
  // проверка на пустоту
  bool isEmpty() const { return top == -1; }
  // проверка на заполненность
  bool isFull() const { return top == size - 1; }
  T get() const {
    if (!isEmpty()) return arr[top];
  }
  void pop() {
    if (!isEmpty()) top--;
  }
  void push(T item) {
    if (!isFull()) arr[++top] = item;
  }
};

#endif  // INCLUDE_TSTACK_H_
