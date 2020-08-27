template <class T>
void LinkedStack<T>::Push(const T& e) {
	top = new ChainNode<T>(e, top);
}

template <class T>
void LinkedStack<T>::Pop() {
	// Delete top node from the stack
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	ChainNode<T> *delNode = top;
	top = top->link;
	delete delNode;
}

template <class T>
void LinkedQueue<T>::Push(const T& e)
{
	if(IsEmpty()) front = rear = new ChainNode(e, 0);
	else rear = rear->link = new ChainNode(e, 0);
}

template <class T>
void LinkedQueue<T>::Pop()
{
	// Delete first element in queue.
	if (IsEmpty()) throw "Queue is empty. Cannot delete.";
	ChainNode<T> *delNode = front;
	front = front->link;
	delete delNode;
}


template <class T>
class TreeNode {
friend class Tree<T>;
private:
		T data;
		TreeNode<T> *leftChild;
		TreeNode<T> *rightChild;
};

template <class T>
class Tree {
public:
	//Tree operations
private:
	TreeNode<T> *root;
};



template <class T>
void Tree<T>::Inorder()
{
	// Driver calls workhorse for traversla of entire tree.
	// The driver is declared as a public member function of Tree.
	Inorder(root);
}

template <class T>
void Tree<T>::Inorder(TreeNode<T> *currentNode) {
	// workhorse traverses the subtree rooted at currentNode.
	// The workhorse is declared as a private member function of Tree
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode):
		Inorder(currentNode->rightChild);
	}
}


template <class T>
void Tree<T>::Preorder()
{
	// Driver.
	Preorder(root);
}

template <class T>
void Tree<T>::Preorder(TreeNode<T> *currentNode)
{
	// Workhorse
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}


template <class T>
void Tree<T>::Postorder();
{
	Postorder(root);
}

template <class T>
void Tree<T>::Postorder(TreeNode<T> *currentNode)
{
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}





template <class T>
void Tree<T>::NonrecInorder()
{
	//Nonrecursive inorder traversal using a stack.
	Stack<TreeNode<T>*> s; // declare and initialize stack
	TreeNode<T> *currentNode = root;

	while(1) {
		while(currentNode) {
			//move down leftChild fiels
			s.Push(currentNode); // add to stack
			currentNode = currentNode->leftChild;
		}
		if (s.IsEmpty()) return;
		currentNode = s.Top();
		s.Pop();
		Visit(currentNode);
		currentNode = currentNode->rightChild;
	}
}


class InorderIterator {
public:
	InorderIterator() { currentNode = root; }
	T* Next();
private:
	Stack<TreeNode<T> *> s;
	TreeNode<T> *currentNode;
}

T* InorderIterator::Next()
{
	while(currentNode) {
		s.Push(currentNode);
		currentNode = currentNode->leftChild;
	}
	if (s.IsEmpty()) return 0;

	currentNode = s.Top();
	s.Pop();
	T& temp = currentNode->data;
	currentNode = currentNode->rightChild;
	return &temp;
}



template <class T>
void Tree<T>::LevelOrder()
{
	// Traverse the binary tree in level order
	Queue<TreeNode <T>*> q;
	TreeNode<T> *currentNode = root;
	while(currentNode) {
		Visit(currentNode);
		if (currentNode->LeftChild) q.Push(currentNode->leftChild);
		if (currentNode->rightChild) q.Push(currentNode->rightChild);
		if (q.IsEmpty()) return;
		currentNode = q.Front();
		q.Pop();
	}
}