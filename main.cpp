#include <iostream>
#include <stdio.h>
#include <typeinfo>

template<typename Type>
Type Min(Type a, Type b) {
	return a > b ? b : a;
}

template <typename Type>
void PrintMin(Type a) {
	std::cout << typeid(a).name() << ";" << a << std::endl;
}

template<>
void PrintMin<char>(char a) {
	std::cout << "文字列以外は代入できません" << std::endl;
}

int main(void) {
	PrintMin(Min<int>(7, 12));
	PrintMin(Min<float>(3.0f, 9.0f));
	PrintMin(Min<double>(static_cast<double>(4.0f), static_cast<double>(3.0f)));
	PrintMin(Min<char>('y', 't'));

	return 0;
}