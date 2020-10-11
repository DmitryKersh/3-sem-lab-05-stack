#include <iostream>
#include <stack.hpp>

using std::cout;

int main(){
  stack<int> s;
  s.push(12);
  cout << s.top() << " ";
  s.push(13);
  cout << s.top() << " ";
  s.push(7 + 7);
  cout << s.top() << " ";
  s.push(s.top() + 1);

  cout << s.top() << " ";
  s.pop();
  cout << s.top() << " ";
  s.pop();
  cout << s.top() << " ";
  s.pop();

  return 0;
}