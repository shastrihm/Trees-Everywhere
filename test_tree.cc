//name: Hrishee Shastri
#include "tree.hh"
#include "tree.cc"
using namespace std;


//test trees

void tree1()
{
    // the tree pictured in tree.hh
    tree_ptr_t leaf1 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t leaf2 = create_tree(6,0,leaf1,nullptr);
    tree_ptr_t leaf3 = create_tree(12,0,nullptr,nullptr);
    tree_ptr_t leaf4 = create_tree(-5,0,leaf3,leaf2);
    tree_ptr_t leaf5 = create_tree(3,0,nullptr,nullptr);
    tree_ptr_t leaf6 = create_tree(12,0,leaf5,nullptr);
    
    tree_ptr_t tree = create_tree(126,0,leaf4,leaf6);

    //path_to test cases 
    //(note that case where key  is not in tree is when program exits)
    assert(path_to(tree,126)=="");
    assert(path_to(tree,9)=="LRL");
    assert(path_to(tree,3)=="RL");
    assert(path_to(tree,-5)=="L");
    assert(path_to(tree,12)=="LL");
    assert(path_to(tree,6)=="LR");

    //node_at test cases
    assert(node_at(tree,"LLL")==nullptr);
    assert(node_at(tree,"LRR")==nullptr);
    assert(node_at(tree,"")==tree);
    assert(node_at(tree,"R")==leaf6);
    assert(node_at(tree,"RL")==leaf5);
    assert(node_at(tree,"L")==leaf4);
    assert(node_at(tree,"LL")==leaf3);
    assert(node_at(tree,"LR")==leaf2);
    assert(node_at(tree,"LRL")==leaf1);

    destroy_tree(tree);

    cout<<"All tests passed in tree 1"<<"\n";
}

void tree2()
{
    // tree with 1 node
    tree_ptr_t tree = create_tree(1,2,nullptr,nullptr);

    //path_to test cases
    assert(path_to(tree,1)=="");

    //node_at test cases
    assert(node_at(tree,"")==tree);
    assert(node_at(tree,"L")==nullptr);
    assert(node_at(tree,"R")==nullptr);
    assert(node_at(tree,"RL")==nullptr);

    destroy_tree(tree);

    cout<<"All tests passed in tree 2"<<"\n";
}

void tree3()
{
    // tree with 0 nodes (nullptr)
    
    //path_to test cases

    //node_at test cases
    assert(node_at(nullptr,"R")==nullptr);
    assert(node_at(nullptr,"L")==nullptr);
    assert(node_at(nullptr,"")==nullptr);

    destroy_tree(nullptr);

    cout<<"All tests passed in tree 3"<<"\n";
}


void tree4()
{
    // tree with only left branches
    tree_ptr_t leaf1 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t leaf2 = create_tree(6,0,leaf1,nullptr);
    tree_ptr_t leaf3 = create_tree(12,0,leaf2,nullptr);
    tree_ptr_t leaf4 = create_tree(-5,0,leaf3,nullptr);
    tree_ptr_t leaf5 = create_tree(3,0,leaf4,nullptr);
    tree_ptr_t leaf6 = create_tree(12,0,leaf5,nullptr);
    
    tree_ptr_t tree = create_tree(126,0,leaf6,nullptr);

    //path_to test cases
    assert(path_to(tree,126)=="");
    assert(path_to(tree,9)=="LLLLLL");
    assert(path_to(tree,-5)=="LLL");
    assert(path_to(tree,12)=="LLLL");

    //node_at test cases
    assert(node_at(tree,"")==tree);
    assert(node_at(tree,"R")==nullptr);
    assert(node_at(tree,"LLLLLL")==leaf1);
    assert(node_at(tree,"L")==leaf6);
    assert(node_at(tree,"LLLL")==leaf3);

    destroy_tree(tree);

    cout<<"All tests passed in tree 4"<<"\n";
}

void tree5()
{
    // tree with only right branches
    tree_ptr_t leaf1 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t leaf2 = create_tree(6,0,nullptr,leaf1);
    tree_ptr_t leaf3 = create_tree(12,0,nullptr,leaf2);
    tree_ptr_t leaf4 = create_tree(-5,0,nullptr,leaf3);
    tree_ptr_t leaf5 = create_tree(3,0,nullptr,leaf4);
    tree_ptr_t leaf6 = create_tree(12,0,nullptr,leaf5);
    
    tree_ptr_t tree = create_tree(126,0,nullptr,leaf6);

    //path_to test cases
    assert(path_to(tree,126)=="");
    assert(path_to(tree,9)=="RRRRRR");
    assert(path_to(tree,-5)=="RRR");
    assert(path_to(tree,12)=="R");

    //node_at test cases
    assert(node_at(tree,"")==tree);
    assert(node_at(tree,"L")==nullptr);
    assert(node_at(tree,"RRRRRR")==leaf1);
    assert(node_at(tree,"R")==leaf6);
    assert(node_at(tree,"RRRR")==leaf3);

    destroy_tree(tree);

    cout<<"All tests passed in tree 5"<<"\n";
}

void tree6()
{
    // tree with only one left node whose key is also in right nodes
    tree_ptr_t leaf0 = create_tree(-5,1,nullptr,nullptr);
    tree_ptr_t leaf1 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t leaf2 = create_tree(6,0,nullptr,leaf1);
    tree_ptr_t leaf3 = create_tree(12,0,nullptr,leaf2);
    tree_ptr_t leaf4 = create_tree(-5,0,nullptr,leaf3);
    tree_ptr_t leaf5 = create_tree(3,0,nullptr,leaf4);
    tree_ptr_t leaf6 = create_tree(12,0,nullptr,leaf5);
    
    tree_ptr_t tree = create_tree(126,0,leaf0,leaf6);

    //path_to test cases
    assert(path_to(tree,-5)=="L");
    assert(path_to(tree,9)=="RRRRRR");
    assert(path_to(tree,126)=="");

    //node_at test cases
    assert(node_at(tree,"")==tree);
    assert(node_at(tree,"LL")==nullptr);
    assert(node_at(tree,"L")==leaf0);
    assert(node_at(tree,"RRR")==leaf4);

    destroy_tree(tree);

    cout<<"All tests passed in tree 6"<<"\n";
}

void tree7()
{
    // tree with only one right node whose key is also in left nodes
    tree_ptr_t leaf0 = create_tree(-5,1,nullptr,nullptr);
    tree_ptr_t leaf1 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t leaf2 = create_tree(6,0,leaf1,nullptr);
    tree_ptr_t leaf3 = create_tree(12,0,leaf2,nullptr);
    tree_ptr_t leaf4 = create_tree(-5,0,leaf3,nullptr);
    tree_ptr_t leaf5 = create_tree(3,0,leaf4,nullptr);
    tree_ptr_t leaf6 = create_tree(12,0,leaf5,nullptr);
    
    tree_ptr_t tree = create_tree(126,0,leaf6,leaf0);

    //path_to test cases
    assert(path_to(tree,-5)=="LLL");
    assert(path_to(tree,9)=="LLLLLL");
    assert(path_to(tree,126)=="");

    //node_at test cases
    assert(node_at(tree,"")==tree);
    assert(node_at(tree,"RR")==nullptr);
    assert(node_at(tree,"R")==leaf0);
    assert(node_at(tree,"LLL")==leaf4);

    destroy_tree(tree);

    cout<<"All tests passed in tree 7"<<"\n";
}

void tree8()
{
    // tree with all same keys (same structure as tree1)
    tree_ptr_t leaf1 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t leaf2 = create_tree(9,0,leaf1,nullptr);
    tree_ptr_t leaf3 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t leaf4 = create_tree(9,0,leaf3,leaf2);
    tree_ptr_t leaf5 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t leaf6 = create_tree(9,0,leaf5,nullptr);
    
    tree_ptr_t tree = create_tree(9,0,leaf4,leaf6);

    //path_to test cases 
    assert(path_to(tree,9)=="LL");

    //node_at test cases
    assert(node_at(tree,"LLL")==nullptr);
    assert(node_at(tree,"LRR")==nullptr);
    assert(node_at(tree,"")==tree);
    assert(node_at(tree,"R")==leaf6);
    assert(node_at(tree,"RL")==leaf5);
    assert(node_at(tree,"L")==leaf4);
    assert(node_at(tree,"LL")==leaf3);
    assert(node_at(tree,"LR")==leaf2);
    assert(node_at(tree,"LRL")==leaf1);

    destroy_tree(tree);

    cout<<"All tests passed in tree 8"<<"\n";
 
}

void tree9()
{
    // tree with 2 nodes
    tree_ptr_t leaf1 = create_tree(1,10,nullptr,nullptr);
    tree_ptr_t tree = create_tree(10,100,leaf1,nullptr);

    //path_to test cases 
    assert(path_to(tree,10)=="");
    assert(path_to(tree,1)=="L");

    //node_at test cases
    assert(node_at(tree,"LL")==nullptr);
    assert(node_at(tree,"R")==nullptr);
    assert(node_at(tree,"RR")==nullptr);
    assert(node_at(tree,"")==tree);
    assert(node_at(tree,"L")==leaf1);

    destroy_tree(tree);

    cout<<"All tests passed in tree 9"<<"\n";

}

int main()
{
    tree1();
    tree2();
    tree3();
    tree4();
    tree5();
    tree6();
    tree7();
    tree8();
    tree9();

    //valgrind did not detect any memory mismanagement.

    return 0; 
}