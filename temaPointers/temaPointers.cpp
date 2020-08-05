#include <iostream>

struct myList {
	int* data;
	size_t size=10;
	size_t nextSize = 0;
	myList(){
		data = new int[size];
	}
	~myList() {
		delete[] data;
	}
	void add(int x) {
		nextSize++;
		if (nextSize > size) {
			doubleInSize();
		}

		data[nextSize - 1] = x;
	
	}
	void pop() {
		if (nextSize == 0) {
			std::cout << "Empty list";
			return;
		}
		else {
			int a = data[nextSize - 1];
			data[nextSize - 1] = 0;
			--nextSize;
		}
	}
	void doubleInSize() {
		int* copyOfData = new int[size];
		for (int i = 0; i < size; ++i)
			copyOfData[i] = data[i];
		
		data = new int[2 * nextSize];
		size = (nextSize * 2);
		for (int i = 0; i < nextSize; ++i)
			data[i] = copyOfData[i];
	}
	
};
int main()
{
	myList l;
	l.add(1);
	l.add(2);
	l.add(3);
	l.add(4);
	l.add(5);
	l.add(5);
	l.add(5);
	l.add(5);
	l.add(5);
	l.add(5);
	l.add(5);
	l.add(5);
	l.add(5);
	for (int i = 0; i < l.size && l.data[i] != 0; ++i)
		std::cout <<i <<"  "<< l.data[i] << std::endl;
}