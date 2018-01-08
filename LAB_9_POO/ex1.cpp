#include <iostream>

class Object {
public:
	void print();
	int equals (Object& obj);
};

int operator == ( Object& ob1, Object& ob2) {
	return ob1.equals(ob2);
}

void Object::print() {
	std::cout << this << std::endl;
}

int Object::equals (Object& obj) {
	return this == &obj;
}

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}