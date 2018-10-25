//Name: Hrishee Shastri

#include "tree.hh"
using namespace std;

// initializes a tree
tree_ptr_t create_tree(const key_t& key,const value_t& value,tree_ptr_t left,tree_ptr_t right)
{
    tree_ptr_t tree_ptr = new Tree(); 
    tree_ptr->key_ = key;
    tree_ptr->value_ = value;
    tree_ptr->left_ = left;
    tree_ptr->right_ = right;
  
    return tree_ptr;
}

// deallocates the memory consumed by a tree
void destroy_tree(tree_ptr_t tree)
{   
    // if node is not nullptr, delete it and its children.
    if(tree)
    {
        destroy_tree(tree->left_);
        destroy_tree(tree->right_); 
        delete tree; 
    }     
}

// takes a string with "R", "L", and "M" and splits the string at the last index of "M"
// and then deletes all occurences of "M" 
string clean_path_string(string path)
{
    int last_index;
    int i = 0;

    //get last index
    for (char c : path)
    {
        if(c == 'M')
        {
            last_index = i;
        }
        ++i;
    }

    // build split string
    string split_path = "";
    for (int j = 0; j<last_index; ++j)
    {
        split_path = split_path + path[j];
    }

    //delete occurences of 'M' from split_path
    string new_split_path = "";
    for (char c : split_path)
    {
        if(c != 'M')
        {
            new_split_path = new_split_path + c;
        }
    }

    return new_split_path;
}


// recursively checks tree to see if key in tree.
bool is_key_in_tree(tree_ptr_t tree, key_t key)
{
    if(!tree)
    {
        return false;
    }

    if(tree->key_ == key)
    {
        return true;
    }

    bool left = is_key_in_tree(tree->left_, key);
    bool right = is_key_in_tree(tree->right_, key);

    if(left or right)
    {
        return true;
    }

    return false;
}

// helper function for path_to. Recurses over right and left branches and records path.
string string_path(tree_ptr_t tree, key_t key, string path)
{   
    if(!tree)
    {
        return "absent";
    }

    if(tree->key_ == key)
    {   
        //now check if other leftmost matches occur
        string tentative_path = path;
        tentative_path = tentative_path + "M"; 
        // M marks where we encounter a match, so we can backtrack
        
        while(tree->left_ != nullptr)
        {
            tree = tree->left_;
            tentative_path = tentative_path+"L";
            if(tree->key_ == key)
            {   
                tentative_path = tentative_path+"M"; 
            }
            
        }

        return clean_path_string(tentative_path);
    }

    string right = string_path(tree->right_, key, path+"R");
    string left = string_path(tree->left_, key, path+"L");

    if(left == "absent" and right == "absent")
    {
        return "absent";
    }
    if(left == "absent" and right != "absent")
    {
        return right;
    }
    return left; 
}

// returns string of path to node with key
string path_to(tree_ptr_t tree, key_t key)
{
    if(!is_key_in_tree(tree,key))
    {
        cout << "No such key found." << "\n";
        assert(false);
    }

    return string_path(tree, key, "");
}

// returns node at end of path
tree_ptr_t node_at(tree_ptr_t tree, std::string path)
{
    for(char c : path)
    {   
        //don't crash!
        if(!tree)
        {
            return nullptr;
        }

        if(c =='R')
        {
            tree = tree->right_;
        }

        else if(c =='L')
        {
            tree = tree->left_;
        }
    };

    return tree;
}

