#ifndef INT_VEC_H
#define INT_VEC_H

#include <initializer_list>

class IntVec {
public:
	const int inc;
	int *data = nullptr;

	int dim;
	int maxDim;

	IntVec (int maxDim = 10, int inc = 10) : inc(inc) {
		dim = 0;
		resizeTo(maxDim);
	}

	IntVec (const IntVec& vec) : inc(vec.inc) {
		resizeTo(vec.dim);
		dim = vec.dim;

		for (int i = 0; i < vec.dim; i++)
			data[i] = vec.data[i];
	}

	IntVec& operator = (const IntVec& vec) {
		resizeTo(vec.dim);
		dim = vec.dim;

		for (int i = 0; i < vec.dim; i++)
			data[i] = vec.data[i];

		return (*this);
	}

	IntVec (const IntVec&& vec) : inc(vec.inc) {
		(*this) = vec;
	}

	IntVec& operator = (const IntVec&& vec) {
		return (*this = vec);
	}

	~IntVec() {
		freeData();
	}

	int size() const {
		return dim;
	}

	void add (int elem) {
		dim++;
		resizeTo(dim);

		putAt(dim - 1, elem);
	}

	void add (std::initializer_list<int> list) {
		dim += list.size();
		resizeTo(dim);

		int index = dim - list.size();
		for (auto it = std::begin(list); it != std::end(list); it++, index++) {
	        putAt(index, *it);
	    }
	}

	void set (int index, int elem) {
		putAt(index, elem);
	}

	int get(int index) {
		return data[index];
	}

	void remove (int index) {
		for (int i = index + 1; i < dim; i++)
			data[i - 1] = data[i];
		
		dim--;
		resizeTo(dim);
	}

	void remove (int start, int stop) {
		for (int i = stop; i < dim; i++)
			data[i - (stop - start)] = data[i];
		
		dim -= (stop - start);
		resizeTo(dim);
	}

	int indexOf (int elem) {
		for (int i = 0; i < dim; i++)
			if (elem == data[i])
				return i;
		return -1;
	}

	void print() {
		std::cout << "[";
		for (int i = 0; i < dim; i++) {
			std::cout << data[i];

			if (i + 1 != dim)
				std::cout << ",";
		}

		std::cout << "]";
	}

	void putAt (int index, int elem) {
		data[index] = elem;
	}

	void resizeTo (int newDim) {
		int newMaxDim = ((newDim / inc) + bool(newDim % inc)) * inc;

		if (newMaxDim != maxDim) {
			int *newData = new int[newMaxDim];

			if (data)
				for (int i = 0; i < std::min(newMaxDim, std::min(dim, newDim)); i++)
					newData[i] = data[i];

			freeData();		
			data = newData;
		}
	}

	void freeData() {
		if (data != nullptr) {
			delete [] data;
			data = nullptr;
		}
	}

	int& operator [] (int index) {
		return data[index];
	}

	friend std::ostream& operator << (std::ostream& stream, const IntVec& arg) {
		stream << "[";
		
		for (int i = 0; i < arg.size(); i++) {
			stream << arg.data[i];

			if (i + 1 != arg.size())
				stream << ",";
		}

		stream << "] (" << "size = " << arg.size() << ")";
		return stream;
	}
};

#endif