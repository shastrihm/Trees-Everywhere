# Trees-Everywhere
A simple tree data structure with traversal algorithms in C++

# How to build
Just use the Makefile.
>make

# Design choices

*tree.hh* -- header file declares a Tree struct and four public API functions, which are defined in *tree.cc*
and subjected to rigorous testing in *test_tree.cc*: 
>tree_ptr_t create_tree(const key_t& key,
                       const value_t& value,
                       tree_ptr_t left = nullptr,
                       tree_ptr_t right = nullptr);

creates a tree node and returns a pointer to that node. Left and right are pointers to branching nodes. 
                       
>void destroy_tree(tree_ptr_t tree);

Deconstructs the tree by recursively traversing the tree and deleting each node. 

>std::string path_to(tree_ptr_t tree, key_t key);

Returns a string path (e.g. "LRLRLL") to the leftmost node containing the key specified. It uses a private
function called "string_path" that recursively traverses the tree by calling itself on the right and subtrees.
If and once such a node is found, the tree iterates through all the left children of that node and places an 'M' in the
spot wherever another node with the same key is found. Then the string path is cleaned up to return the path[:m] where 
m is the index of the final occurence of 'M', and is then sanitized of all other occurences of 'M'. 

>tree_ptr_t node_at(tree_ptr_t tree, std::string path);

Iterates over the path such that for each step, tree=tree->left_ when step is 'L' and tree=tree->right_ when step is 'R'.
Returns a pointer to the node at the destination.


