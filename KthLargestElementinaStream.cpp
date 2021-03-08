#include<iostream>
#include<vector>

using namespace std;

int heap[10000];
int heap_size;
int K;

void heapify(int arr[],int i,int n)
{
	int smallest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	int t;
	if(l<n && arr[l]< arr[smallest])
		smallest = l;
	if(r<n && arr[r] < arr[smallest])
		smallest = r;
	if(i!=smallest) {
		t = arr[i];
		arr[i] = arr[smallest];
		arr[smallest] = t;
		heapify(arr,smallest,n);
	}
}

void create_heap(int arr[],int n)
{
	int i;
	for(i=(n/2-1);i>=0;i--)
		heapify(arr,i,n);
}


void KthLargest(int k, vector<int>& nums) {
	int len = nums.size();
	int i;
	for(i=0;i<k && i<len;i++)
		heap[i] = nums[i];
	create_heap(heap,i);
	heap_size = i;
	for(int j= i;j<len;j++) {
		if(heap_size < k) {
			heap[heap_size] = nums[j];
			heap_size++;
			create_heap(heap,heap_size);
		} else{
			if(nums[i] > heap[0]) {
				heap[0] = nums[j];
				heapify(heap,0,heap_size);
			}
		}
	}
	//heap_size = i;
	K = k;
}

int add(int val) {
	if(heap_size < K) {
		heap[heap_size] = val;
		heap_size++;
		create_heap(heap,heap_size);
		return(heap[0]);
	}else {
		if(val > heap[0]) {
			heap[0] = val;
			heapify(heap,0,heap_size);
		}
	}
	return heap[0];
}

int main()
{

	vector<int> num = {-10,1,3,1,4,10,3,9,4,5,1};
	cout<<add(3) <<endl;
	cout<<add(2) <<endl;
	cout<<add(3) <<endl;
	cout<<add(1) <<endl;
	cout<<add(2) <<endl;
	cout<<add(4) <<endl;
	cout<<add(5) <<endl;
	cout<<add(5) <<endl;
	return(0);
}


