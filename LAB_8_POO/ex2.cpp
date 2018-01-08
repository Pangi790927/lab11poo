#include <iostream>
#include "BitSet.h"

class Set : public BitSet {
public:
	Set (BitSet& other) : BitSet(other) {}
	Set (BitSet&& other) : BitSet(other) {}

	friend std::ostream& operator << (std::ostream& stream, Set& arg) {
		stream << "{";
		bool first = true;
		for (int i = 0; i < arg.size; i++) {
			if (arg.contains(i)) {
				if (!first)
					stream << ",";
				first = false;
				stream << i;
			}
		}
		stream << "}";

		return stream;
	}

	friend std::ostream& operator << (std::ostream& stream, Set&& arg) {
		stream << arg;

		return stream;
	}
};

int main(int argc, char const *argv[])
{
	BitSet S({1, 2, 3, 4, 5}); /// o sa presupun ca se incadreaza la "generate prin program"

	BitSet C[] = {
		{},
		{2, 5},
		{2, 3, 4},
		{3, 4, 5},
		{1, 3, 4}
	};

	std::cout << "S: " << S << std::endl;

	if (
		[&]{
			BitSet result;
			for (auto&& set : C)
				result = result + set;
			return result.contains(S);
		}()) 
	{
		BitSet A[sizeof(C) / sizeof(C[0])];
		int imax = 0;

		while (!S.isEmpty()) {
			int maxCard = 0;
			for (int i = 0; i < sizeof(C) / sizeof(C[0]); i++) {
				A[i] = S * C[i];
			
				if (A[i].elemCount() > maxCard) {
					maxCard = A[i].elemCount();
					imax = i;
				}
			}
			std::cout << 	"index: " << imax << 
							" elemCount: " << C[imax].elemCount() << 
							" multime: " << Set(C[imax]) << std::endl;
			S = S - C[imax];
		}
	}

	return 0;
}