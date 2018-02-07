#include "binary_tree.h"  

int main(void) {
	binary_tree<char> tree;
	tree.tree_insert(new tree_node<char>('C'));
	tree.tree_insert(new tree_node<char>('D'));
	tree.tree_insert(new tree_node<char>('J'));
	tree.tree_insert(new tree_node<char>('E'));
	tree.tree_insert(new tree_node<char>('B'));
	tree.tree_insert(new tree_node<char>('A'));
	tree.tree_insert(new tree_node<char>('G'));
	tree.tree_insert(new tree_node<char>('H'));
	tree.tree_insert(new tree_node<char>('F'));
	tree.tree_insert(new tree_node<char>('I'));

	cout << "���������" << endl;
	tree.inorder_tree_walk(tree.get_root()); cout << endl;
	cout << "ǰ�������" << endl;
	tree.preorder_tree_walk(tree.get_root()); cout << endl;
	cout << "���������" << endl;
	tree.posorder_tree_walk(tree.get_root()); cout << endl;

	cout << "���δ�ӡ��" << endl;
	tree.print_tree();
	tree.tree_delete(tree.search(tree.get_root(), 'E'));
	cout << "ɾ��E��" << endl;
	tree.print_tree();
}