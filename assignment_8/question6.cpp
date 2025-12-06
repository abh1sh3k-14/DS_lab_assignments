#include <iostream>
using namespace std;

#define MAX 100  

class PriorityQueue {
private:
    int heap[MAX];
    int size;  
    void heapifyUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2;
            if(heap[parent] < heap[index]){   
                swap(heap[parent], heap[index]);
                index = parent;
            } else break;
        }
    }

    void heapifyDown(int index){
        while(true){
            int left = 2*index + 1;
            int right = 2*index + 2;
            int largest = index;

            if(left < size && heap[left] > heap[largest])
                largest = left;

            if(right < size && heap[right] > heap[largest])
                largest = right;

            if(largest != index){
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else break;
        }
    }

public:
    PriorityQueue(){
        size = 0;
    }

    void push(int val){
        if(size == MAX){
            cout<<"Priority Queue is full\n";
            return;
        }
        heap[size] = val;
        heapifyUp(size);
        size++;
    }

    int top(){
        if(size == 0){
            cout<<"Priority Queue is empty\n";
            return -1;
        }
        return heap[0];
    }

    void pop(){
        if(size == 0){
            cout<<"Priority Queue is empty\n";
            return;
        }
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    bool empty(){
        return size == 0;
    }

    void display(){
        cout<<"Priority Queue (Heap): ";
        for(int i = 0; i < size; i++)
            cout<<heap[i]<<" ";
        cout<<endl;
    }
};

int main(){
    PriorityQueue pq;

    pq.push(30);
    pq.push(10);
    pq.push(50);
    pq.push(40);
    pq.push(20);

    pq.display();

    cout<<"Max element: "<<pq.top()<<endl;

    pq.pop();
    cout<<"After removing max: ";
    pq.display();

    return 0;
}
