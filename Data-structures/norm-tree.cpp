# include <iostream>
# include <string>
# include <vector>
using namespace std;

struct node
{
    string name;
    int occuption;
    node *next_bro = NULL;
    node *first_child = NULL;
};

class norm_tree
{
private: node root;
public:
    norm_tree(string, int);
    ~norm_tree();
    node& tree_name();
    norm_tree& add_child(string name, node*, int);
    vector<node*> the_childs(node*);
    void show_childs(node*);
    void print_tree(node*, int);
    int calc_occup(node*);
};

norm_tree::norm_tree(string name, int value)
{
    root.name = name;
    root.occuption = value;
}
node& norm_tree::tree_name()
{
    return root;
}
norm_tree& norm_tree::add_child(string name, node *loc, int value)
{
    node* child = new node;
    child->name = name;
    child->occuption = value;

    if (!loc) loc = &root;

    child->next_bro = loc->first_child;
    loc->first_child = child;
    
    return *this;
}
vector<node*> norm_tree::the_childs(node* loc)
{
    vector<node*> childs;
    
    if (!loc) loc = &root;

    for (node* p = loc->first_child; p; p = p->next_bro)
    {
        childs.push_back(p);
    }

    return childs;
}
void norm_tree::show_childs(node* now_root)
{
    vector<node*> childs = this->the_childs(now_root);

    for (int i = 0; i < childs.size(); ++i)
    {
        cout << childs[i]->name << " ";
    }
    cout << endl;
}
void norm_tree::print_tree(node* now_root, int depth)
{
    if (!now_root) now_root = &root;

    for (int i = 0; i < depth; ++i) cout << "\t";
    cout << now_root->name  << "(" << now_root->occuption << ")" << endl;

    for (node* p = now_root->first_child; p; p = p->next_bro)
    {
        print_tree(p, depth + 1);
    }
}
int norm_tree::calc_occup(node* now_root)
{
    if (!now_root) now_root = &root;

    vector<node*> childs = this->the_childs(now_root);
    int now_occuption = (childs.size() > 0) + now_root->occuption;
    
    for (int i = 0; i < childs.size(); ++i)
    {
        now_occuption += calc_occup(childs[i]);
    }
    cout << now_root->name << ": " << now_occuption << endl; 
    
    now_root->occuption = now_occuption;
    return now_root->occuption;
}
void free_childs(node* parent, norm_tree& tree)
{
        vector<node*> childs = tree.the_childs(parent);

        if (childs.empty())
        {
            cout << "del" << parent->name << endl;
            delete parent;
        }
        else
        {
            for (int i = 0; i < childs.size(); i++)
            {
                free_childs(childs[i], tree);
            }
            cout << "del" << parent->name << endl;
            if (parent != &tree.tree_name()) delete parent;
        }
}
norm_tree::~norm_tree()
{
    cout << "start delete" << endl;
    free_childs(&root, *this);
}

int main()
{
    norm_tree tree("root", 0);
    tree.add_child("c11", nullptr, 1).add_child("c12", nullptr, 2).add_child("c13", nullptr, 3);

    vector<node*> childs1 = tree.the_childs(nullptr);

    tree.add_child("c21", childs1[0], 1).add_child("c22", childs1[0], 3).add_child("c23", childs1[1], 2).add_child("c24", childs1[1], 5);

    vector<node*> childs2 = tree.the_childs(childs1[1]);

    tree.add_child("c31", childs2[0], 2).add_child("c32", childs2[1], 1).add_child("c33", childs2[1], 3);
    
    tree.calc_occup(nullptr);
    tree.print_tree(nullptr, 0);

    return 0;
}