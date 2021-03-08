int heap[10001];
int heap_size;

void heapify(int heap[],int i,int n)
{
	int smallest = i;
	int l = 2*i +1;
	int r = 2*i + 2;
	int t;
	if(l<n && heap[l] < heap[smallest])
		smallest = l;
	if(r<n && heap[r] < heap[smallest])
		smallest = r;
	if(i!=smallest) {
		t = heap[i];
		heap[i] = heap[smallest];
		heap[smallest] = t;
		heapify(heap,smallest,n);
	}
}


void create_heap(int heap[],int n)
{
	int i;
	for(i=(n/2-1);i>=0;i--) {
		heapify(heap,i,n);
	}

}
int findKthLargest(vector<int>& nums, int k) {
	int len = nums.size();
	int i;
	heap_size = k;
	for(i=0;i<heap_size;i++)
		heap[i] = nums[i];
	create_heap(heap,heap_size);
	for(i=k;i<len;i++) {
		if(nums[i] > heap[0]) {
			heap[0] = nums[i];
			heapify(heap,0,heap_size);
		}
	}
	return(heap[0]);
}
