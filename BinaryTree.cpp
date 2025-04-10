#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N = 100;

struct Node {
public:
	int data;
	Node *left, *right;
	Node(int value)
	{
		this->data = value;
		this->left = this->right = nullptr;
	}
};

void addNode(Node *root, int val) {
	if (root->data > val) { 
		if (!root->left) { 
			root->left = new Node(val);
		}
		else {
			addNode(root->left, val); 
		}
	}
	else { //Åñëè êëþ÷ áîëüøå ìåäèàíû
		if (!root->right) {
			root->right = new Node(val);
		}
		else {
			addNode(root->right, val);
		}
	}
}

void Travel(Node *node) {
	if (node == NULL)
		return;
	cout << node->data << " \n";
	Travel(node->left);
	Travel(node->right);
}

int main()
{
	srand(time(0));
	Node *first = new Node(50);
	int *a;
	a = new int[N];
	int s = 0; int e = 100;

	for (int i = 0; i<N; i++) {
		a[i] = rand() % (e - s + 1) + s;
	}

	for (int i = 0; i<N; i++) {
		addNode(first, a[i]);
	}

	Travel(first);
	return 0;
}

