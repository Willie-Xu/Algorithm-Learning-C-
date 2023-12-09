
#include<cstdio>
#include<set>
using namespace std;
struct NODE {
	int id;
	int distance;
}nodes[10];

struct CMP
{
	const bool operator ()(const NODE* a, const NODE* b) const {
		if (a->distance == b->distance) return a->id < b->id;
		else return a->distance < b->distance;
	}
};

set<NODE*,CMP> st;
void print() {
	for (set<NODE*>::iterator it = st.begin(); it != st.end(); it++) {
		printf("%d ", (*it)->id);
	}
	printf("\n");
	for (set<NODE*>::iterator it = st.begin(); it != st.end(); it++) {
		printf("%d ", (*it)->distance);
	}
	printf("\n");
}
int main() {
	for (int i = 0; i < 5; i++)
	{
		nodes[i].id = i;
		nodes[i].distance = 3 * i;
		st.insert(&nodes[i]);
	}
	//注意，不支持it<st.end()的写法
	//st.erase(st.find(105), st.end());		//利用find()函数找到100，然后用erase删除它和其之后的所有 
	print();
	st.erase(&nodes[0]);
	print();
	nodes[0].distance = 6;
	st.insert(&nodes[0]);
	print();
	st.erase(st.find(&nodes[0]), st.end());
	print();
	return 0;
}
