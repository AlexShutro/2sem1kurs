//Куча может быть реализована с использованием связанного списка в C++ путем определения структуры узла, которая содержит значение и указатель на следующий узел.
//Мы также можем определить класс кучи, который содержит указатель на головной узел и предоставляет методы для вставки и удаления узлов при сохранении свойства кучи.


#include <iostream>

using namespace std;

// Определите структуру узла
struct Node {
    int value;
    Node* next;
};

// Определите класс кучи
class Heap {
public:
    Heap() {
        head = nullptr;
    }

    // Вставляем новое значение в кучу
    void insert(int value) {
        Node* newNode = new Node{ value, nullptr };
        if (!head) {
            head = newNode;
            return;
        }
        if (value > head->value) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* curr = head;
        while (curr->next && curr->next->value > value) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    // Удалить и вернуть максимальное значение в куче
    int removeMax() {
        if (!head) {
            cout << "Heap is empty." << endl;
            return -1;
        }
        Node* temp = head;
        head = head->next;
        int maxVal = temp->value;
        delete temp;
        return maxVal;
    }

private:
    Node* head;
};

int main() {
    Heap heap;
    heap.insert(5);
    heap.insert(3);
    heap.insert(8);
    heap.insert(2);
    heap.insert(7);
    cout << heap.removeMax() << endl; 
    cout << heap.removeMax() << endl; 
    cout << heap.removeMax() << endl; 
    cout << heap.removeMax() << endl; 
    cout << heap.removeMax() << endl; 
    cout << heap.removeMax() << endl; 
    return 0;
}
