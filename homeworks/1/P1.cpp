#include<iostream>

using namespace std;

struct element {
    int value;
    element* next;
};

element* add(element* head, int value) {
    auto* temp = new element;
    temp->value = value;
    temp->next = head;
    return temp;
}

void printList(element* head) {
    element* temp = head;
    temp = temp->next;
    if (temp) {
        printList(temp);
        cout << temp->value << " ";
    }
}
int main() {
    int n, counter = 0, i = 2;
    cin >> n;
    element* head = nullptr;
    while (counter < n) {
        bool prime = true;
        if (i != 2) {
            element* list = head;
            while (list) {
                if (i % list->value == 0) {
                    prime = false;
                    break;
                }
                list = list->next;
            }
        }
        if (prime) {
            head = add(head, i);
            counter++;
        }
        i++;
    }
    head = add(head, -1);
    printList(head);
    return 0;
}