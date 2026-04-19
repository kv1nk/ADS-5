// Copyright 2025 NNTU-CS
#include <map>
#include <string>

#include "tstack.h"

using namespace std;
bool isOper(char x) {
  if (x > 41 && x < 48) {
    return 1;
  } else {
    return 0;
  }
}

bool isNum(char x) {
  if (x >= ('0' + 0) && x <= ('9' + 0)) {
    return 1;
  } else {
    return 0;
  }
}

int CharToNum(char x) { return x - '0'; }

int getPrior(char ch) {
  if (ch == '+' || ch == '-') return 1;
  if (ch == '*' || ch == '/') return 2;
  return 0;
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 10> stack;
  string res = "";

  for (int i = 0; i < inf.length(); i++) {
    char ch = inf[i];

    if (isNum(ch)) {
      if (res != "") res += ' ';
      res += ch;
    } else if (ch == '(') {
      stack.push(ch);
    } else if (ch == ')') {
      while (!stack.isEmpty() && stack.get() != '(') {
        res += ' ';
        res += stack.get();
        stack.pop();
      }
      if (!stack.isEmpty()) stack.pop();
    } else if (isOper(ch)) {
      while (!stack.isEmpty() && stack.get() != '(' &&
             getPrior(stack.get()) >= getPrior(ch)) {
        res += ' ';
        res += stack.get();
        stack.pop();
      }
      stack.push(ch);
    }
  }
  while (!stack.isEmpty()) {
    res += ' ';
    res += stack.get();
    stack.pop();
  }
  return res;
}

int eval(const std::string& pref) {
  TStack<int, 10> stack;
  for (int i = 0; i <= pref.length(); i++) {
    char ch = pref[i];

    if (ch == ' ') continue;

    if (isNum(ch)) {
      stack.push(CharToNum(ch));
    } else if (isOper(ch)) {
      int k = stack.get();
      stack.pop();
      int j = stack.get();
      stack.pop();

      int res = 0;

      if (ch == '+') res = k + j;
      if (ch == '-') res = j - k;
      if (ch == '/') res = j / k;
      if (ch == '*') res = j * k;

      stack.push(res);
    }
  }
  return stack.get();
}
