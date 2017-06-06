#include <iostream>
#include <memory>

struct Node {
    Node()
        : payload(-1)
        , next(nullptr)
    {
    }
    Node(int p)
        : payload(p)
        , next(nullptr)
    {
    }
    int payload;
    Node* next;
};

void Print(const Node* const head)
{
    if (!head) {
        return;
    }

    const Node* cur = head;
    do {
        std::cout << cur->payload << std::endl;
    } while (cur->next && (cur = cur->next));
}

Node* Add(Node* head, int p)
{
    if (!head) {
        return head;
    }

    Node* cur = head;
    while (cur->next != nullptr) {
        cur = cur->next;
    }

    cur->next = new Node(p);
    return head;
}

Node* Reverse(Node*& head)
{
    if (!head) {
        return head;
    }

    auto next = head->next;
    head->next = nullptr;
    auto prev = head;
    while (next) {
        auto cur = next;
        next = cur->next;
        cur->next = prev;
        prev = cur;
    }

    head = prev;
    return head;
}

int main(int argc, char** argv)
{
    auto head = new Node(123);
    Add(head, 456);
    Add(head, 789);
    Print(head);
    auto newhead = Reverse(head);
    Print(newhead);

    return 0;
}
