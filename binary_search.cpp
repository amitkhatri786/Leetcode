#include<iostream>
#include<vector>

using namespace std;

// void binary_search_first(int arr[], int n, int k)
// {
// 	int low, high;
// 	int res = -1;
// 	int mid;
// 	low = 0;
// 	high = n - 1;
// 	while (low <= high)
// 	{
// 		mid = (low + high) / 2;
// 		if (arr[mid] > k)
// 			high = mid - 1;
// 		else if (arr[mid] < k)
// 			low = mid + 1;
// 		else
// 		{
// 			res = mid;
// 			high = mid - 1;
// 		}
// 	}
// 	cout << "First " << res << "\n";
// }

// void binary_search_last(int arr[], int n, int k)
// {
// 	int low, high;
// 	int res = -1;
// 	int mid;
// 	low = 0;
// 	high = n - 1;
// 	while (low <= high)
// 	{
// 		mid = (low + high) / 2;
// 		if (arr[mid] > k)
// 			high = mid - 1;
// 		else if (arr[mid] < k)
// 			low = mid + 1;
// 		else
// 		{
// 			res = mid;
// 			low = mid + 1;
// 		}
// 	}
// 	cout << "last " << res << "\n";
// }

// int main()
// {
// 	int i;
// 	int arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 7, 7, 9};
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	cout << "number of element " << n << "\n";
// 	binary_search_first(arr, n, 0);
// 	binary_search_last(arr, n, 0);
// 	return 0;
// }

int first(vector<int> &arr,int n,int k)
{
	int res = -1;
	int low,high;
	low = 0;
	high = n - 1;
	int mid;
	while(low<= high){
		mid = low + (high - low)/2;
		if(arr[mid]>k)
			high = mid - 1;
		else if(arr[mid]<k)
			low = mid + 1;
		else{
			res = mid;
			high = mid -1;
		}
	}
	return res;
}

int last(vector<int> &arr,int n,int k)
{
	int res = -1;
	int low,high;
	low = 0;
	high = n - 1;
	int mid;
	while(low<= high){
		mid = low + (high - low)/2;
		if(arr[mid]>k)
			high = mid - 1;
		else if(arr[mid]<k)
			low = mid + 1;
		else{
			res = mid;
			low = mid + 1;
		}
	}
	return res;
}

vector<int> searchRange(vector<int> &nums, int target)
{
	vector<int> res;
		res.push_back(first(nums,nums.size(),target));
		res.push_back(last(nums,nums.size(),target));
	return res;
}