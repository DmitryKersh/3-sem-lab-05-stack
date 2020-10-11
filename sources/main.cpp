#include <iostream>
#include <stack.hpp>

using std::cout;

int main(){
  stack<int> s;
  s.push(12);
  cout << s.head() << " ";
  s.push(13);
  cout << s.head() << " ";
  s.push(7 + 7);
  cout << s.head() << " ";
  s.push(s.head() + 1);

  cout << s.head() << " ";
  s.pop();
  cout << s.head() << " ";
  s.pop();
  cout << s.head() << " ";
  s.pop();

  return 0;
}