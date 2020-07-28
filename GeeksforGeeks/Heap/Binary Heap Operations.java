/*
A binary heap is a Binary Tree with the following properties:
1) It’s a complete tree (All levels are completely filled except possibly the last level and the last level has all keys as left as possible). This property of Binary Heap makes them suitable to be stored in an array.

2) A Binary Heap is either Min Heap or Max Heap. In a Min Binary Heap, the key at the root must be minimum among all keys present in Binary Heap. The same property must be recursively true for all nodes in Binary Tree. Max Binary Heap is similar to MinHeap.

You are given an empty Binary Min Heap and some queries and your task is to implement the three methods insertKey,  deleteKey,  and extractMin on the Binary Min Heap and call them as per the query given below:
1) 1  x  (a query of this type means to insert an element in the min-heap with value x )
2) 2  x  (a query of this type means to remove an element at position x from the min-heap)
3) 3  (a query like this removes the min element from the min-heap and prints it ).

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then T test cases follow. The first line of each test case contains an integer Q denoting the number of queries. The second line of each test case contains Q queries separated by space.

Output:
The output for each test case will be space-separated integers having -1  if the heap is empty else the min element of the heap.

Your Task:
You are required to complete the 3 methods insertKey() which take one argument the value to be inserted, deleteKey() which takes one argument the position from where the element is to be deleted and extractMin() which returns the minimum element in the heap.

Expected Time Complexity: O(Q*Log(size of Heap) ).
Expected Auxiliary Space: O(1).

Constraints:
1 <= T <= 100
1 <= Q <= 104
1 <= x <= 104

Example:
Input:
2
7
1 4 1 2 3 1 6 2 0 3 3
5
1 8 1 9 2 1 3 3

Output:
2 6 - 1
8 -1
 

Explanation:
Testcase 1:
In the first test case for query 
1 4      the heap will have  {4}  
1 2      the heap will be {2 4}
3         removes min element from heap ie 2 and prints it now heap is {4} 
1 6      inserts 6 to heap now heap is {4 6}
2 0      delete element at position 0 of the heap, now heap is {6}
3         remove min element from heap ie 6 and prints it  now the heap is empty {}
3         since the heap is empty thus no min element exist so -1 is printed.

############################################################################Solution#############################################################################################
*/

class MinHeap {
    int[] harr;
    int capacity,heap_size;
    MinHeap(int cap) {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    // You need to write code for below three functions
    int extractMin() {
        if(heap_size <= 0)
            return -1;
        
        if(heap_size == 1){
            heap_size--;
            return harr[0];
        }
        heap_size--;
        swap(harr,0,heap_size);
        MinHeapify(0);
        
        return harr[heap_size];
    }

    void insertKey(int k) {
        if(heap_size == capacity)
            return;
            
        harr[heap_size] = k;
        heap_size++;
        
        for(int i=heap_size-1;i!=0 && harr[i]<harr[parent(i)];){
            swap(harr,i,parent(i));
            i = parent(i);
        }
    }

    void deleteKey(int i) {
        if(i>=heap_size)
            return;
            
        decreaseKey(i,Integer.MIN_VALUE);
        extractMin();
    }

    // Decrease key operation, helps in deleting the element
    void decreaseKey(int i, int new_val) {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i]) {
            swap(harr,i,parent(i));
            i = parent(i);
        }
    }
    
    static void swap(int harr[],int i,int j){
        int temp = harr[i];
        harr[i] = harr[j];
        harr[j] = temp;
    }

    /* You may call below MinHeapify function in
      above codes. Please do not delete this code
      if you are not writing your own MinHeapify */
    void MinHeapify(int i) {
        
        int l = left(i);
        int r = right(i);
        int smallest = i;
        
        if(l<heap_size && harr[l]<harr[smallest])
            smallest = l;
        if(r<heap_size && harr[r]<harr[smallest])
            smallest = r;
            
        if(smallest != i){
            swap(harr,i,smallest);
            MinHeapify(smallest);
        }
    }
}
