/*heap is a complete binarty tree that comes with a heap order property.
//nodes are always added from left in complete binary tree


max heap - every child value will be smaller than itts parent's node
min heap - every child vlue will begreater than their parent's node

insertion in max heap
node -> ith index
node -> left = 2*i 
node -> right = 2*i + 1
the above implementation is done using array and that index is referring to array's index

first insert at end and then take it to its right position by comparing with its parent if its greater or anything else as per min/max heap then that then ok otherwise we have to make a swap of both of these and keep repeating same until we meet the rquired conditions

deletion
first swpa first and last node and then check whether the current array is replifying a heap ornot, if not then do make necessary changes in to make it replify heap. this deletion is basically for root node of heap

time complexity for boht insertion and deletion is O(log n);

#### HEAPIFY
this algo is basically 
the index of leaf node is from n/2 + 1 to nth index and these leaf nnodes are already heap so tehy dont needto be processd wo we node to procsess from 1 to n/2.
yime complexity for hepaify is O(N);

the current algo which we have used is for max heap we can do for min heap as well in the same way.

Heap sort - first swap first noe with last node and then derease size and then do heapify and keep repeating the same stuff.

*/

#include<iostream>
#include<algorithm>
using namespace std;

class heap {
public:
    int arr[100];
    int size = 0;

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void deleteFromHeap(){
        if(size == 0){
            cout << " nothing to delete" <<endl;
            return ;
        }
        arr[1]= arr[size];
        size--;

        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
            }
            else{
                return;
            }
        }

    }
    
    void print(){
        for(int i = 1;i<=size;i++){
            cout <<arr[i]<<" ";
        }cout<<endl;
    }
};

void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(left <= n && arr[largest] < arr[left]){
            largest = left;
        }

        if(right <= n && arr[largest] < arr[right]){
            largest = right;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
};

void heapsort(int arr[], int n){
    int size = n;
    while( size > 1){
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}
int main(){
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(20);
    h.print();
    h.deleteFromHeap();
    h.print();
    int arr[6] ={-1, 54, 53, 55, 52, 50};

    int n = 5;
    // heap creation
    for(int i = n/2; i>0;i--){
        heapify(arr, n, i);
    }

    cout <<"printing the array after heaify -----------------"<< endl;

    for(int i = 1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //heap sort
    heapsort(arr, n);

    for(int i = 1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
};


