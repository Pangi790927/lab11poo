#include <iostream>
#include <vector>

class Object {
public:
	virtual void print();
	virtual int equals (Object& obj);
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

	int equals (Object& obj) {
		return str == static_cast<String&>(obj).str;
	}
};

class Vector {
public:
	std::vector<Object*> container;

	Vector() {}
	Vector (int dim) : container(dim) {}

	void add (Object* arg) {
		container.push_back(arg);
	}

	void print() {
		for (int i = 0; i < container.size(); i++) {
			container[i]->print();
		}
	}

	int contains (Object& arg) {
		for (int i = 0; i < container.size(); i++) {
			if (container[i]->equals(arg)) {
				return true;
			}
		}
		return false;
	}
};

int main(int argc, char const *argv[])
{
	String str1("Ana are mere");
	String str2("Ana are pere");
	String str3("Ana are pere");

	Vector vec;
	vec.add(&str1);
	vec.add(&str2);

	std::cout << vec.contains(str3) << std::endl;

	vec.print();

	return 0;
}