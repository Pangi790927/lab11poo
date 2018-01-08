#ifndef BIT_SET_H
#define BIT_SET_H

#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

class BitSet {
public:
	typedef unsigned short int PatchType;
	
	static const int BITS_IN_BYTE = 8;
	static const int BITS_IN_PATCH = sizeof(PatchType) * BITS_IN_BYTE;
	
	std::vector<PatchType> patchVec;

	BitSet (int size) : patchVec(size / BITS_IN_PATCH + 1, 0) {}

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
};

#endif