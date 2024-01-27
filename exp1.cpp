#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class ArrayOperations {
private:
    int array[MAX_SIZE];
    int size;

public:
    ArrayOperations() : size(0) {}

    void traverse() {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void addElement(int element) {
        if (size < MAX_SIZE) {
            array[size++] = element;
        }
    }

    void reverseArray() {
        int start = 0;
        int end = size - 1;
        while (start < end) {
            swap(array[start], array[end]);
            ++start;
            --end;
        }
    }

    void insertElement(int index, int element) {
        if (size < MAX_SIZE && index >= 0 && index <= size) {
            for (int i = size - 1; i >= index; --i) {
                array[i + 1] = array[i];
            }
            array[index] = element;
            ++size;
        }
    }

    void deleteElement(int element) {
        int i = 0;
        while (i < size && array[i] != element) {
            ++i;
        }
        if (i < size) {
            for (int j = i; j < size - 1; ++j) {
                array[j] = array[j + 1];
            }
            --size;
        }
    }
};

int main() {
    ArrayOperations arrayOps;

    arrayOps.addElement(34);
    arrayOps.addElement(20);
    arrayOps.addElement(30);

    arrayOps.traverse();

    arrayOps.insertElement(4, 15);

    arrayOps.traverse();

    arrayOps.reverseArray();

    arrayOps.traverse();

    arrayOps.deleteElement(20);

    arrayOps.traverse();

    return 0;
}
