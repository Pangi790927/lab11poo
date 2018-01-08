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
	std::cout << "obj ... " << std::endl;
}

int Object::equals (Object& obj) {
	return this == &obj;
}

class String : public Object {
public:
	std::string str;

	String (const char* c_str) : str(c_str) {}
	String (std::string str) : str(str) {}

	String operator + (String& arg) {
		return String(str + arg.str);
	}

	void print() {
		std::cout << str << std::endl;
	}

	int equals (String& obj) {
		return str == obj.str;
	}
};

int main(int argc, char const *argv[])
{
	String a("asdf");
	String b("1234");
	
	(a + b).print();
	
	std::cout << a.equals(a) << std::endl;
	std::cout << a.equals(b) << std::endl;

	return 0;
}