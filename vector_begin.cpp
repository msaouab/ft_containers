#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;
//   for (int i=1; i<=5; i++) myvector.push_back(i);

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    std::cout << ' ' << *it;
	// std::vector<int>::iterator it = myvector.begin();
	// std::vector<int>::iterator il = myvector.end();
	// std::cout << '\n' << *it << '\n';
	// std::cout << *it << '\n';

  return 0;
}