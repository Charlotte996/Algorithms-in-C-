#ifndef BINARY_TREE
#define BINARY_TREE

#include"util.h"

template<typename T>
class tree_node 
{
public:
	tree_node(T key_) :key(key_), parent(NULL), left_child(NULL), right_child(NULL) {};
	T get_key();
	tree_node* get_parent();
	tree_node* get_left_child();
	tree_node* get_right_child();
	void set_parent(tree_node* p);
	void set_left_child(tree_node* lc);
	void set_right_child(tree_node* rc);

private:
	T key;
	tree_node* parent;
	tree_node* left_child;
	tree_node* right_child;
};

template<typename T>
class binary_tree 
{
public:
	binary_tree() :root(NULL), size(0), max_key_length(0), change(false) {};
	void inorder_tree_walk(tree_node<T>* r) const;//中序遍历
	void preorder_tree_walk(tree_node<T>* r) const;//先序遍历
	void posorder_tree_walk(tree_node<T>* r) const;//后序遍历
	tree_node<T>* search(tree_node<T>* x, T k) const;//查找键值为k的节点
	tree_node<T>* min_node(tree_node<T>* x) const;//查找键值最小的节点
	tree_node<T>* max_node(tree_node<T>* x) const;//查找键值最大的节点
	tree_node<T>* successor_node(tree_node<T>* x) const;//返回最小的比当前节点大的节点
	tree_node<T>* get_root() const;//获取根节点
	void tree_insert(tree_node<T>* z);//插入节点
	void tree_delete(tree_node<T>* z);//删除节点
	void print_tree();//打印二叉树
	int tree_size() const;//节点个数
	int tree_high(tree_node<T>* r) const;//二叉树高度

private:
	void transplant(tree_node<T>* u, tree_node<T>* v);//用v为根节点替换为用u为根节点
	void find_nodes_indexs(tree_node<T>* r, int layer);//计算节点的坐标用于打印
	int get_max_key_length() const;//获取键最大长度（用于打印）
	int size;//节点个数
	int max_key_length;//最大键长
	tree_node<T>* root;//根节点指针
	map <tree_node<T>*, pair<int, int>> node_indexs;
	bool change;//与上次打印相比是否发生变化
};

/***********tree_node***************/

template<typename T>
T tree_node<T>::get_key() 
{
	return key;
}

template<typename T>
tree_node<T>* tree_node<T>::get_parent() 
{
	return parent;
}

template<typename T>
tree_node<T>* tree_node<T>::get_left_child() 
{
	return left_child;
}

template<typename T>
tree_node<T>* tree_node<T>::get_right_child() 
{
	return right_child;
}

template<typename T>
void tree_node<T>::set_parent(tree_node<T>* p) 
{
	parent = p;
}

template<typename T>
void tree_node<T>::set_left_child(tree_node<T>* lc) 
{
	left_child = lc;
}

template<typename T>
void tree_node<T>::set_right_child(tree_node<T>* rc) 
{
	right_child = rc;
}

/*************binary_tree****************/

template<typename T>
void binary_tree<T>::inorder_tree_walk(tree_node<T>* r) const 
{
	if (r != NULL) 
	{
		inorder_tree_walk(r->get_left_child());
		cout << r->get_key() << " ";
		inorder_tree_walk(r->get_right_child());
	}
}

template<typename T>
void binary_tree<T>::preorder_tree_walk(tree_node<T>* r) const 
{
	if (r != NULL) 
	{
		cout << r->get_key() << " ";
		preorder_tree_walk(r->get_left_child());
		preorder_tree_walk(r->get_right_child());
	}
}

template<typename T>
void binary_tree<T>::posorder_tree_walk(tree_node<T>* r) const 
{
	if (r != NULL) 
	{
		posorder_tree_walk(r->get_left_child());
		posorder_tree_walk(r->get_right_child());
		cout << r->get_key() << " ";
	}
}

template<typename T>
tree_node<T>* binary_tree<T>::search(tree_node<T>* x, T k) const 
{
	if (x != NULL || x->get_key() == k) 
	{
		return x;
	}
	if (k < x->get_key())
	{
		return search(x->get_left_child(), k);
	}
		return search(x->get_right_child(), k);
	
}

template<typename T>
tree_node<T>* binary_tree<T>::max_node(tree_node<T>* x) const
{
	while (x->get_left_child() != NULL)
		x = x->get_left_child;
	return x;
}

template<typename T>
tree_node<T>* binary_tree<T>::min_node(tree_node<T>* x) const 
{
	while (x->get_right_child() != NULL)
		x = x->get_right_child();
	return x;
}

template<typename T>
tree_node<T>* binary_tree<T>::successor_node(tree_node<T>* x) const 
{
	if (x->get_right_child() != NULL)
		return min_node(x->get_right_child());
	tree_node<T>* y = x->get_parent;
	while (y != NULL && x == y->get_right_child()) 
	{
		x = y;
		y = y->get_parent();
	}
	return y;
}

template<typename T>
void binary_tree<T>::tree_insert(tree_node<T>* z) 
{
	size++;
	change = true;
	if (z != NULL && T2string(z->get_key()).size() > max_key_length)
		max_key_length = T2string(z->get_key()).size();
	tree_node<T>* y = NULL;
	tree_node<T>* x = root;
	while (x != NULL) 
	{
		y = x;
		if (z->get_key() < x->get_key()) 
		{
			x = x->get_left_child();
		}
		else
		{
			x = x->get_right_child();
		}
	}
	z->set_parent(y);
	if (y = NULL)
		root = z;
	else if (z->get_key() < y->get_key())
		y->set_left_child(z);
	else
		y->set_right_child(z);
}

template<typename T>
void binary_tree<T>::tree_delete(tree_node<T>* z) 
{
	size--;
	change = true;
	if (z->get_left_child() == NULL) 
	{
		transplant(z, z->get_right_child());
	}
	else if (z->get_right_child() == NULL) 
	{
		transplant(z, z->get_left_child());
	}
	else 
	{
		tree_node<T>* y = min_node(z->get_right_child());
		if (y->get_parent() != z) 
		{
			transplant(y, y->get_right_child());
			y->set_left_child(z->get_right_child());
			y->get_right_child()->set_parent(y);
		}
		transplant(z, y);
		y->set_left_child(z->get_left_child());
		y->get_left_child()->set_parent(y);
	}
}

template<typename T>
tree_node<T>* binary_tree<T>::get_root() const 
{
	return root;
}

template<typename T>
int binary_tree<T>::tree_size() const 
{
	return size;
}

template<typename T>
int binary_tree<T>::tree_high(tree_node<T>* r) const 
{
	if (r == NULL)
		return 0;
	int right_depth = 0, left_depth = 0;

	if (r->get_left_child() != NULL)
		left_depth = tree_high(r->get_left_child());
	if (r->get_right_child() != NULL)
		right_depth = tree_high(r->get_right_child());
	return max(right_depth, left_depth) + 1;
}

template<typename T>
void binary_tree<T>::transplant(tree_node<T>* u, tree_node<T>* v)
{
	if (u->get_parent() == NULL)
		root = v;
	else if (u == u->get_parent()->get_left_child())
	{
		u->get_parent()->set_left_child(v);
	}
	else
		u->get_parent()->set_right_child(v);
	if (v == NULL)
		v->set_parent(u->get_parent());
}

template<typename T>
void binary_tree<T>::find_nodes_indexs(tree_node<T>* r, int layer) 
{
	if (r != NULL) 
	{
		static int col;
		if (layer == 0)
			col = 0;
		find_nodes_indexs(r->get_right_child(), layer + 1);
		node_indexs[r] = make_pair(layer, col++);
		find_nodes_indexs(r->get_right_child(), layer + 1);
	}
}

template<typename T>
int binary_tree<T>::get_max_key_length() const 
{
	return max_key_length;
}

template<typename T>
void binary_tree<T>::print_tree() 
{
	int row = tree_high(root);
	int col = tree_size();
	int len = get_max_key_length();

	vector<vector<string>> chart(row, vector<string>(col));
	if (change) 
	{
		node_indexs.clear();
		find_nodes_indexs(root, 0);
		change = false;
	}
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++) 
		{
			chart[i][j] = string(len, ' ');
		}
	}
	typename map<tree_node<T>*, pair<int, int>>::iterator i = node_indexs.begin();
	while (i != node_indexs.end()) 
	{
		int cur_row = i->second.first;
		int cur_col = i->second.second;
		T cur_key = i->first->get_key();
		int blank_num = max_key_length - T2string(cur_key).size();
		string cur_str(blank_num, ' ');
		cur_str += T2string(cur_key);
		chart[cur_row][cur_col] = cur_str;
		i++;
	}
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++) 
		{
			cout << chart[i][j];
		}
		cout << endl;
	}
}
#endif
