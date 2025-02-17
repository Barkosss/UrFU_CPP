#include<iostream>
#include<fstream>

/*
Проверьте, что заданное на входе бинарное дерево является сбалансированным,
т.е. для любого узла этого дерева выполняется условие,
что его высоты левого и правого поддерева отличаются не более,
чем на единицу.
*/

using std::abs;
using std::cout;
using std::endl;
using std::ifstream;

struct Page {
    int index;
    Page* pageLeft;
    Page* pageRight;

    Page(int index): index(index), pageLeft(nullptr), pageRight(nullptr) {};
};

class Tree {
private:
    Page* root;

    long long height(Page* page) {

        if (page == nullptr) {
            return 0;
        }

        return std::max(height(page->pageLeft), height(page->pageRight)) + 1;
    }

    bool isBalanceRecurse(Page* page) {

        if (!page) {
            return true;
        }

        long long leftHeight = height(page->pageLeft);
        long long rightHeight = height(page->pageRight);

        if (std::abs(leftHeight - rightHeight) > 1) {
            return false;
        }

        return isBalanceRecurse(page->pageLeft) * isBalanceRecurse(page->pageRight);
    }

public:
    Tree(): root(nullptr) {};

    bool isBalance() {
        if (!root) {
            return true;
        }

        return isBalanceRecurse(root);
    }

    void push(int index) {
        Page* ptr = new Page(index);

        if (!root) {
            root = ptr;
            return;
        }

        Page* temp_ptr = root;
        while(true) {

            if (index <= temp_ptr->index && !temp_ptr->pageLeft) {
                temp_ptr->pageLeft = ptr;
                break;
            } else if (temp_ptr->index < index && !temp_ptr->pageRight) {
                temp_ptr->pageRight = ptr;
                break;
            } else if(index <= temp_ptr->index) {
                temp_ptr = temp_ptr->pageLeft;
            } else {
                temp_ptr = temp_ptr->pageRight;
            }
        }
    }
};

int main() {
    ifstream inFile("input.txt");

    Tree tree = Tree();
    int index;
    while(!inFile.eof()) {
        inFile >> index;
        tree.push(index);
    }

    cout << "Answer: " << ((tree.isBalance()) ? ("True") : ("False")) << endl;
    cout << "Program is done!" << endl;
    return 0;
}