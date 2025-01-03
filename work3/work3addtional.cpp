#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>

class SimpleVector {
protected:
	T* data;
	int currentSize;
	int currentCapacity;

private:	

	void resize(int newCapacity) {
		newCapacity = currentCapacity + 5;
		T* newData = new T[newCapacity];
		for (int i = 0; i < currentSize; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
		currentCapacity = newCapacity;		
	}


public:

	SimpleVector() : currentSize(0), currentCapacity(10) {
		data = new T[currentCapacity];
	}

	SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity) {
		data = new T[currentCapacity];
	}

	SimpleVector(const SimpleVector& other) : currentSize(other.currentSize), currentCapacity(other.currentCapacity){
		data = new T[other.currentCapacity];
		for (int i = 0; i < currentSize; i++) {
			data[i] = other.data[i];
		}
	
	}

	~SimpleVector() {
		cout << "메모리 해제" << endl;
		delete[] data;
	}

	void push_back(const T& value) {
		if (currentSize >= currentCapacity) {
			currentSize = currentCapacity;
			resize(currentCapacity + 5);
			data[currentSize++] = value;
		}
		else {
			data[currentSize++] = value;
		}
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

	void printData() {		

		for (int i = 0; i < currentSize; i++) {
			cout<< data[i];
		}		
		cout << "\n";
	}

	void sortData() {
		sort(data, data+currentSize);
		cout << "정렬 : ";
		for (int i = 0; i < currentSize; i++) {
			cout << data[i];
		}
		cout << "\n";
	}
};



int main() {

	SimpleVector<int>vec; // 디폴트 생성
	cout << "vecCapacity : " << vec.capacity() << endl;
	cout << "vecsize : " << vec.size() << endl;

	for (int i = 0; i < vec.capacity(); i++) {
		vec.push_back(i);
	}
	cout << "vec에 배열값이 채워졌습니다." << endl;
	cout << "vecsize : " << vec.size() << endl;
	
	cout << "vec value : ";
	vec.printData();


	SimpleVector<char>alphabet(5); // 크기 설정
	cout << "alphabetCapacity : " << alphabet.capacity() << endl;

	alphabet.push_back('b');
	alphabet.push_back('a');
	alphabet.push_back('d');

	cout << "alphabet : ";
	alphabet.printData();
	cout << "alphabetSize : " << alphabet.size() << endl;

	alphabet.pop_back();

	cout << "delete 'd' from alphabet : "; 
	alphabet.printData();
	cout << "alphabetSize : " << alphabet.size() << endl;
	alphabet.push_back('f');

	cout << "add 'f' to alphabet : ";
	alphabet.printData();
	cout << "alphabetSize : " << alphabet.size() << endl;

	alphabet.push_back('d');
	alphabet.push_back('c');
	alphabet.push_back('e');
	cout << "add d,c,e to alphabet : ";
	alphabet.printData();
    cout << "alphabetSize : " << alphabet.size() << endl;
	cout << "alphabetNewCapacity : " << alphabet.capacity() << endl;

	alphabet.sortData();

	SimpleVector<char>alphabet2 = alphabet; //복사 생성
	cout << "alphabet2 : ";
	alphabet2.printData();

	return 0;
}