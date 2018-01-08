#ifndef BIT_SET_H
#define BIT_SET_H

#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <initializer_list>
#include <algorithm>		/// for min/max on initializer_list

/// !!! MUST BE COMPILED WITH C++11 or MORE

class BitSet {
public:
	typedef unsigned short int PatchType;
	
	static const int BITS_IN_BYTE = 8;
	static const int BITS_IN_PATCH = sizeof(PatchType) * BITS_IN_BYTE;
	
	std::vector<PatchType> patchVec;
	int size;

	BitSet (int size = 256) : patchVec(size / BITS_IN_PATCH + 1, 0), size(size) {}

	BitSet (BitSet& other) {
		patchVec = other.patchVec;
		size = other.size;
	}

	BitSet (BitSet&& other) {
		patchVec = other.patchVec;
		size = other.size;
	}

	BitSet (std::initializer_list<int> list) {
		size = std::max(0, std::max(list)) + 1;
		patchVec = std::vector<PatchType>(size / BITS_IN_PATCH + 1, 0);
		
		for (auto&& elem : list) {
			set(elem);
		}
	}

	int patchPos (int pos) {
		return (pos / BITS_IN_PATCH);
	}

	int posInPatch (int pos) {
		return (pos % BITS_IN_PATCH);
	}

	void set (int pos) {
		if (patchPos(pos) < patchVec.size() && patchPos(pos) >= 0)
			patchVec[patchPos(pos)] |= (1 << posInPatch(pos));
	}

	bool contains (int pos) {
		if (patchPos(pos) < patchVec.size() && patchPos(pos) >= 0)
			return patchVec[patchPos(pos)] & (1 << posInPatch(pos));
		return false;
	}

	bool contains (BitSet& other) {
		return (other - *this).isEmpty();
	}

	int elemCount() {
		int count = 0;
		for (int i = 0; i < size; i++)
			if (contains(i))
				count++;
		return count;
	}

	bool isEmpty() {
		for (int i = 0; i < size; i++)
			if (contains(i))
				return false;
		return true;
	}

	void clear (int pos) {
		if (patchPos(pos) < patchVec.size() && patchPos(pos) >= 0)
			patchVec[patchPos(pos)] &= ~(1 << (posInPatch(pos)));		
	}

	static std::string patchToString (PatchType patch) {
		std::stringstream ss;

		for (int i = 0; i < BITS_IN_PATCH; i++)
			ss << (bool)((1 << i) & patch);

		return ss.str();
	}

	std::string toString() {
		std::stringstream ss;

		ss << std::setw(8) << std::setfill('0') << std::hex << 0 << std::dec << ": ";
		for (int i = 0; i < patchVec.size(); i++) {
			ss << patchToString (patchVec[i]);

			if ((i + 1) % (8 / (BITS_IN_PATCH / BITS_IN_BYTE)) == 0 && (i + 1) != patchVec.size())
				ss << std::endl << std::setw(8) << std::setfill('0')
						<< std::hex << (i + 1) * BITS_IN_PATCH << std::dec << ": ";
			else 
				ss << " ";
		}

		return ss.str();
	}

	friend std::ostream& operator << (std::ostream& stream, BitSet& arg) {
		for (int i = 0; i < arg.size; i++)
			stream << arg.contains(i);

		return stream;
	}

	friend std::ostream& operator << (std::ostream& stream, BitSet&& arg) {
		for (int i = 0; i < arg.size; i++)
			stream << arg.contains(i);

		return stream;
	}

	bool operator + (int elem) {
		if (elem >= size)
			return false;

		set(elem);

		return true;
	}

	friend bool operator + (BitSet& arg, int elem) {
		if (elem >= arg.size)
			return false;

		arg.set(elem);

		return true;
	}

	BitSet operator + (BitSet& arg) {
		BitSet newSet(std::max(arg.size, size));

		for (int i = 0; i < std::max(arg.size, size); i++) {
			if (i < size && contains(i)) 
				newSet.set(i);

			if (i < arg.size && arg.contains(i)) 
				newSet.set(i);
		}

		return newSet;
	}

	BitSet operator + (BitSet&& arg) {
		return *this + arg;
	}

	BitSet operator - (BitSet& arg) {
		BitSet newSet(size);

		for (int i = 0; i < size; i++) {
			if (i < size && contains(i))
				newSet.set(i);

			if (i < size && i < arg.size && arg.contains(i)) 
				newSet.clear(i);
		}

		return newSet;
	}

	BitSet operator - (BitSet&& arg) {
		return *this - arg;
	}

	BitSet operator * (BitSet& arg) {
		return (arg + *this) - (arg - *this) - (*this - arg);
	}

	BitSet operator * (BitSet&& arg) {
		return *this * arg; 
	}

	BitSet operator == (BitSet& arg) {
		return (*this - arg).isEmpty() && (arg - *this).isEmpty(); 
	}

	BitSet operator == (BitSet&& arg) {
		return (*this == arg);
	}	

	BitSet& operator = (BitSet& arg) = default;

	BitSet& operator = (BitSet&& arg) {
		return (*this = arg);
	}	
};



#endif