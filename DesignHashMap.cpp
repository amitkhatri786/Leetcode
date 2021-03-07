#include<iostream>

using namespace std;

struct l{
	struct l *prev;
	struct l *next;
	int value;
	int key;
};
typedef struct l LL;
LL list_buffer[200005];
int list_buffer_count;

struct m{
	LL *start;
	LL *end;
};
typedef struct m MAP;
MAP map1[100005];
#define MAP_SIZE	100004

class MyHashmap {
	public:
		LL *get_list_node(int key,int value) {
			LL *temp; 
			temp = &list_buffer[list_buffer_count++];
			temp->next = NULL;
			temp->prev = NULL;
			temp->value = value;
			temp->key = key;
			return(temp);
		}
		/** Initialize your data structure here. */
		MyHashmap() {
			int i;
			for(i=0;i<MAP_SIZE;i++) {
				map1[i].start = NULL;
				map1[i].end = NULL;
			}
			list_buffer_count = 0;
		}

		/** value will always be non-negative. */
		void put(int key, int value) {
			int h;
			LL *node;
			h = key % 100003;
			if(map1[h].start == NULL) {
				node = get_list_node(key,value);
				map1[h].start = map1[h].end = node;
				
			}else{
				LL *cur;
				cur = map1[h].start;
				while(cur) {
					if(cur->key == key) {
						cur->value = value;
						return;
					}
					cur = cur->next;
				}
				node = get_list_node(key,value);
				map1[h].end->next = node;
				node->prev = map1[h].end;
				map1[h].end = node;
			}
		}

		/** Returns the value to which the specified key is map1ped, or -1 if this map1 contains no map1ping for the key */
		int get(int key) {
			int h;
			h = key % 100003;
			if(map1[h].start == NULL) 
				return -1;
			else{
				LL *cur = map1[h].start;
				while(cur) {
					if(cur->key == key)
						return cur->value;
					cur = cur->next;
				}
				return(-1);
			}
		}

		void delete_from_list(LL **start,LL **end,LL *del_node) {
			if(*start == del_node)
				*start = (*start)->next;
			if(*end == del_node)
				*end = (*end)->prev;
			if(del_node->next)
				del_node->next->prev = del_node->prev;
			if(del_node->prev)
				del_node->prev->next = del_node->next;

			del_node->prev = del_node->next = NULL;

		}
		/** Removes the map1ping of the specified value key if this map1 contains a map1ping for the key */
		void remove(int key) {
			int h;
			LL *cur,*temp;
			h = key%100003;
			if(map1[h].start == NULL)
				return;

			cur = map1[h].start;

			while(cur) {
				temp = cur->next;
				if(cur->key == key) {
					delete_from_list(&map1[h].start,&map1[h].end,cur);
					return;
				}
				cur = temp;
			}
		}
};

/**
 * Your MyHashmap object will be instantiated and called as such:
 * MyHashmap* obj = new MyHashmap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

int main()
{
	MyHashmap* obj = new MyHashmap();
	obj->put(1, 1);
	obj->put(2,2);
	cout << "get 1 "<<obj->get(1)<<endl;
	cout << "get 3 "<<obj->get(3)<<endl;
	obj->put(2, 1);
	cout << "get 2 "<<obj->get(2)<<endl;
	obj->remove(2);
	cout<<"get 2  "<<obj->get(2)<<endl;

	return 0;
}

