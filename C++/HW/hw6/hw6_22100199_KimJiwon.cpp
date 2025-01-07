#include <iostream>
#include <string>
using namespace std;

class node
{
  string name;
  double score;
  node *left, *right;

public:
  node(string n = "", double s = 0) : name(n), score(s), left(NULL), right(NULL) {}
  string get_name();
  double get_score();
  void set_data(string n, double s);
  friend class my_tree;
};

string node::get_name()
{
  return name;
}

double node::get_score()
{
  return score;
}

void node::set_data(string n, double s)
{
  name = n;
  score = s;
}

class my_tree
{
  node *root;

public:
  my_tree() : root(NULL) {}
  void insert_root(node &tmp);
  bool insert_left(string parent_name, node &tmp);
  bool insert_right(string parent_name, node &tmp);
  double score_sum();
  double score_average();
  void print_data_inorder();
  void print_data_preorder();
  void print_data_postorder();

private:
  node *search(node *p, string name);
  double score_sum_helper(node *p);
  int count_nodes(node *p);
  void inorder_traverse(node *p);
  void preorder_traverse(node *p);
  void postorder_traverse(node *p);
};

void my_tree::insert_root(node &tmp)
{
  root = new node(tmp.get_name(), tmp.get_score());
}

bool my_tree::insert_left(string parent_name, node &tmp)
{
  node *parent = search(root, parent_name);
  if (parent != NULL && parent->left == NULL)
  {
    parent->left = new node(tmp.get_name(), tmp.get_score());
    return true;
  }
  return false;
}

bool my_tree::insert_right(string parent_name, node &tmp)
{
  node *parent = search(root, parent_name);
  if (parent != NULL && parent->right == NULL)
  {
    parent->right = new node(tmp.get_name(), tmp.get_score());
    return true;
  }
  return false;
}

node *my_tree::search(node *p, string name)
{
  if (p == NULL)
    return NULL;
  if (p->get_name() == name)
    return p;
  node *left_search = search(p->left, name);
  if (left_search != NULL)
    return left_search;
  return search(p->right, name);
}

double my_tree::score_sum()
{
  return score_sum_helper(root);
}

double my_tree::score_sum_helper(node *p)
{
  if (p == NULL)
    return 0;
  return p->get_score() + score_sum_helper(p->left) + score_sum_helper(p->right);
}

int my_tree::count_nodes(node *p)
{
  if (p == NULL)
    return 0;
  return 1 + count_nodes(p->left) + count_nodes(p->right);
}

double my_tree::score_average()
{
  int total_nodes = count_nodes(root);
  return total_nodes == 0 ? 0 : score_sum() / total_nodes;
}

void my_tree::print_data_inorder()
{
  inorder_traverse(root);
}

void my_tree::inorder_traverse(node *p)
{
  if (p == NULL)
    return;
  inorder_traverse(p->left);
  cout << p->get_name() << " : " << p->get_score() << "\n";
  inorder_traverse(p->right);
}

void my_tree::print_data_preorder()
{
  preorder_traverse(root);
}

void my_tree::preorder_traverse(node *p)
{
  if (p == NULL)
    return;
  cout << p->get_name() << " : " << p->get_score() << "\n";
  preorder_traverse(p->left);
  preorder_traverse(p->right);
}

void my_tree::print_data_postorder()
{
  postorder_traverse(root);
}

void my_tree::postorder_traverse(node *p)
{
  if (p == NULL)
    return;
  postorder_traverse(p->left);
  postorder_traverse(p->right);
  cout << p->get_name() << " : " << p->get_score() << "\n";
}

int main()
{
  my_tree thetree;
  node tmp;

  tmp.set_data("Kim", 8.1);
  thetree.insert_root(tmp);

  tmp.set_data("Lee", 6.5);
  thetree.insert_left("Kim", tmp);

  tmp.set_data("Park", 8.3);
  thetree.insert_right("Kim", tmp);

  tmp.set_data("Choi", 7.2);
  thetree.insert_left("Lee", tmp);

  tmp.set_data("Ryu", 9.0);
  thetree.insert_right("Lee", tmp);

  tmp.set_data("Cho", 7.7);
  thetree.insert_right("Park", tmp);

  cout << "Score Sum : " << thetree.score_sum() << "\n";
  cout << "Score Average : " << thetree.score_average() << "\n";

  cout << "\nInorder Traversal Result\n";
  thetree.print_data_inorder();

  cout << "\nPreorder Traversal Result\n";
  thetree.print_data_preorder();

  cout << "\nPostorder Traversal Result\n";
  thetree.print_data_postorder();

  return 0;
}
