#include <iostream>

using namespace std;

template<typename T>

class SimpleVector {
private:

	T* data;
	int currentSize;
	int currentCapacity;


public:

	SimpleVector() : currentSize(0), currentCapacity(10) {
		data = new T[currentCapacity];
	}

	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
		data = new T[currentCapacity];
	}

	~SimpleVector() {
		delete[] data;
	}

	void push_back(const T& value) {
		if (currentSize < currentCapacity) {
			data[currentSize++] = value;
		}
		else {}
	}

	void pop_back() {
		if (currentSize > 0) {
			currentSize--;
		}
		else {}

	}

	int size() {
		return currentSize;
	}

	int capacity() {
		return currentCapacity;
	}

	string printData() {
		string s;

		for (int i = 0; i < currentSize; i++) {
			s += data[i];
		}
		return s;

	}

};



int main() {

	SimpleVector<int>vec;
	cout << "vecCapacity : " << vec.capacity() << endl;
	cout << "vecsize : " << vec.size() << endl;

	SimpleVector<char>alphabet(5);
	cout << "alphabetCapacity : " << alphabet.capacity() << endl;

	alphabet.push_back('a');
	alphabet.push_back('b');
	alphabet.push_back('d');

	cout << "alphabet : " << alphabet.printData() << endl;
	cout << "alphabetSize : " << alphabet.size() << endl;

	alphabet.pop_back();

	cout << "delete 'd' from alphabet : " << alphabet.printData() << endl;
	cout << "alphabetSize : " << alphabet.size() << endl;
	alphabet.push_back('c');

	cout << "add 'c' to alphabet : " << alphabet.printData() << endl;
	cout << "alphabetSize : " << alphabet.size() << endl;

	alphabet.push_back('d');
	alphabet.push_back('e');
	alphabet.push_back('f');
	cout << "add d,e,f to alphabet : " << alphabet.printData() << endl;
	cout << "alphabetSize : " << alphabet.size() << endl;


	return 0;
}