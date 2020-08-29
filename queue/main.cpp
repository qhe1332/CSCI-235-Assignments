#include <iostream>
#include "queue.h"
int main()
{
   std::cout << "Queue Array Results:" << "\n";
  queueA *qa = new queueA();

  std::cout << qa->is_empty() << "\n";
  qa->enqueue(5);
  qa->enqueue(10);
  qa->enqueue(20);
  std::cout << qa->is_empty() << "\n";

  int r = qa->dequeue();
  std::cout << qa->is_empty() << " " << r << "\n";
  r = qa->dequeue();
  std::cout << qa->is_empty() << " " << r << "\n";
  r = qa->dequeue();
  std::cout << qa->is_empty() << " " << r << "\n";

  try {
    std::cout << qa->dequeue() << "\n";
  } catch (int e){
    std::cout << "Exception: " << e << "\n";
    
  }
  
  std::cout << "\n" <<"Queue Linked List Results:" << "\n";
  queueLL *ql = new queueLL();

  std::cout << ql->is_empty() << "\n";
  ql->enqueue(3);
  ql->enqueue(6);
  ql->enqueue(9);
  std::cout << ql->is_empty() << "\n";

  int b = ql->dequeue();
  std::cout << ql->is_empty() << " " << b << "\n";
  b = ql->dequeue();
  std::cout << ql->is_empty() << " " << b << "\n";
  b = ql->dequeue();
  std::cout << ql->is_empty() << " " << b << "\n";

  try {
    std::cout << ql->dequeue() << "\n";
  } catch (int e){
    std::cout << "Exception: " << e << "\n";
    
  }
  return 0;
}