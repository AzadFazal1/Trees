
#include <algorithm>
#include <iostream>
#include "binary_tree.h"
#include "coloredout.h"
#include "random.h"

using namespace std;
using namespace util;

template <class T>
void printTreeInfo(const binary_tree<T>& tree, const string& name,
                   const string& description);

int main(int argc, char** argv)
{
    // Color the output
    bool is_colored =
        (argc > 1 && tolower(argv[1][0]) == 'c') && isatty(STDOUT_FILENO);
    colored_out coloroutput;
    if (is_colored)
    {
        coloroutput.set_expected_file("soln_treefun.out");
        int status = coloroutput.start();
        if (status < 0)
            return 0;
    }

    // Seed the random generator
    // This can be your favorite number; it's just to set up a
    // pseudorandom sequence that will be predictable
    usrand(86);

    // Make a random unsorted tree with nodes for 1 through 10
    binary_tree<int> myTree;
    for (int i = 1; i <= 10; i++)
        myTree.insert(i);

    // Print the tree
    printTreeInfo(myTree, "Tree", "random unordered tree");

    // Mirror the tree
    myTree.mirror();
    printTreeInfo(myTree, "Mirrored", "the mirror image of the above tree");

    // Make a sorted tree
    // First, create a random ordering to insert 1..10 into the tree
   
    vector<int> ordering;
    ordering.reserve(10);
    for (int num = 1; num <= 10; num++)
        ordering.push_back(num);
    usrand(15);
    random_shuffle(ordering.begin(), ordering.end(), urandn);

    // Then create a tree and insert 1..10 shuffled
    binary_tree<int> myBST;
    for (int index = 0; index < 10; index++)
        myBST.insert(ordering[index], true);

    // Print the tree
    printTreeInfo(myBST, "BST", "random ordered tree");

    // Mirror the tree
    myBST.mirror();
    printTreeInfo(myBST, "BST Mirrored", "the mirror image of the above BST");

    // Make an almost sorted tree
    usrand(128);
    for (int num = 1; num <= 10; num++)
        ordering[num - 1] = num;
    random_shuffle(ordering.begin(), ordering.end(), urandn);

    // Then create a tree and insert 1..10 shuffled
    myBST.clear();
    for (int index = 0; index < 4; index++)
        myBST.insert(ordering[index], true);
    myBST.insert(ordering[4], false);

    printTreeInfo(myBST, "Almost BST",
                  "a tree that has one element out of place");
                  
    return 0;
}

void output_header(string name, string desc)
{
    const string bar(79, '~');
    cout << bar << endl;
    colored_out::output_bold(name);
    cout << " - " << desc << endl;
    cout << bar << endl;
}

template <class T>
void printTreeInfo(const binary_tree<T>& tree, const string& name,
                   const string& description)
{
    output_header(name, description);
    cout << "height: " << tree.height() << endl;
    cout << "ordered: " << boolalpha << tree.isOrdered() << endl;
    cout << "sumDistances: " << tree.sumDistances() << endl;
    tree.print();
    cout << endl;
    cout << "printLeftRight: ";
    tree.printLeftToRight();
    tree.printPaths();
    cout << endl << endl;
}
