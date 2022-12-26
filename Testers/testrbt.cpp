#include "../RB_TREE/Redblack_tree.hpp"

#include <iostream>
using namespace std;

int main() {
    ft::RedBlackTree<int> tree;

	// std::cout << tree.size() << '\n';
	tree.insert(4);
	tree.insert(69);
	tree.insert(70);
	tree.insert(15);
	tree.insert(8);
	tree.insert(73);
	tree.insert(97);
	tree.insert(51);
	tree.insert(78);
	tree.insert(82);
	tree.insert(50);
	tree.insert(27);
	tree.insert(64);
	tree.insert(48);
	tree.insert(58);
	tree.insert(99);
	tree.insert(79);
	tree.insert(52);
	tree.insert(76);
	tree.insert(49);

	tree.printTree();
	// std::cout << tree.size() << '\n';

	// tree.deleteNode(4);
	// tree.deleteNode(69);
	// tree.deleteNode(70);
	// tree.deleteNode(15);
	// tree.deleteNode(8);
	// tree.deleteNode(73);
	// tree.deleteNode(97);
	// tree.deleteNode(51);
	// tree.deleteNode(78);
	// tree.deleteNode(82);
	// tree.deleteNode(50);
	// tree.deleteNode(27);
	// tree.deleteNode(64);
	// tree.deleteNode(48);
	// tree.deleteNode(58);
	// tree.deleteNode(99);
	// tree.deleteNode(79);
	// tree.deleteNode(52);
	// tree.deleteNode(76);
	// tree.deleteNode(49);

	// std::cout << tree.find(49) << std::endl;

	// tree.printTree();
	// std::cout << tree.size() << '\n';
}