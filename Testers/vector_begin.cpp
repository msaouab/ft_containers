#include "./vector/vector.hpp"
#include "./iterators/iterator.hpp"

int main ()
{
    ft::vector<int> v1;
	ft::vector<int> v2(5, 5);
    ft::vector<int> v3(v2.begin(), v2.end());
    ft::vector<int> v4(v3);
            

    // std::cout << "*********** v1 < normal > ************" << std::endl;
    // for (ft::vector<int>::iterator it = v1.begin() ; it != v1.end(); it++)
    //     std::cout << "\t" << *it ;
    // std::cout << std::endl;
            
    // std::cout << "*********** v1 < reverse > ************" << std::endl;
    // for (ft::vector<int>::reverse_iterator it = v1.rbegin() ; it != v1.rend(); it++)
    //     std::cout << "\t" << *it;
    // std::cout << std::endl;

    // std::cout << "*********** v2 < normal > ************" << std::endl;
    // for (ft::vector<int>::iterator it = v2.begin() ; it != v2.end(); it++)
    //     std::cout << "\t" << *it ;
    // std::cout << std::endl;
            
    // std::cout << "*********** v2 < reverse > ************" << std::endl;
    // for (ft::vector<int>::reverse_iterator it = v2.rbegin() ; it != v2.rend(); it++)
    //     std::cout << "\t" << *it;
    // std::cout << std::endl;

    // std::cout << "*********** v3 < normal > ************" << std::endl;
    // for (ft::vector<int>::iterator it = v3.begin() ; it != v3.end(); it++)
    //     std::cout << "\t" << *it ;
    // std::cout << std::endl;
            
    // std::cout << "*********** v3 < reverse > ************" << std::endl;
    // for (ft::vector<int>::reverse_iterator it = v3.rbegin() ; it != v3.rend(); it++)
    //     std::cout << "\t" << *it;
    // std::cout << std::endl;

    // std::cout << "*********** v4 < normal > ************" << std::endl;
    // for (ft::vector<int>::iterator it = v4.begin() ; it != v4.end(); it++)
    //     std::cout << "\t" << *it ;
    // std::cout << std::endl;
            
    // std::cout << "*********** v4 < reverse > ************" << std::endl;
    // for (ft::vector<int>::reverse_iterator it = v4.rbegin() ; it != v4.rend(); it++)
    //     std::cout << "\t" << *it;
    // std::cout << std::endl;
}