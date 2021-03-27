#include <iostream>

using namespace std;

class Node
{
public:
    int val{};
    Node *next{};
    Node() {}
};

class List
{
    Node *root{};

public:
    void pushRecursion(Node *root, int val);
    void popRecursion(Node *root, Node *prev);

    void push(int val)
    {
        if (root == NULL)
        {
            root = new Node();
            root->val = val;
            return;
        }
        pushRecursion(root, val);
    }

    void pop()
    {
        if (root == NULL)
        {
            try
            {
                delete root;
                throw 1;
            }
            catch (int a)
            {
                cout << "Liste melumat at." << endl;
                return;
            }
        }
        popRecursion(root, root);
    }

    void print()
    {
        printRecursion(root);
    }

    void printRecursion(Node *root) // 5,4,3,2,1
    {
        if (root == NULL)
            return;
        cout << root->val << endl;
        printRecursion(root->next);
        return;
    }
};

void List::popRecursion(Node *current, Node *prev) // 1,2,3,4,5
{
    if (current->next == NULL)
    {
        delete current;
        prev->next = NULL;
        return;
    }
    else if (current->next != prev->next)
    {
        popRecursion(current->next, prev->next);
    }
    else
    {
        popRecursion(current->next, prev);
    }
}
void List::pushRecursion(Node *root, int val)
{
    if (root == NULL)
        return;

    if (root->next == NULL)
    {
        root->next = new Node();
        root->next->val = val;
        return;
    }
    pushRecursion(root->next, val);
}

int main()
{
}