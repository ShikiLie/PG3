#include <iostream>

uint32_t CalculateRecursivePayment(uint32_t payment, uint32_t hour) {
	if (hour <= 0) {
		return payment;
	}

	return payment + CalculateRecursivePayment(payment * 2 - 50, hour - 1);
}

uint32_t CalculateGeneralPayment(uint32_t payment, uint32_t hour) {
	if (hour <= 0) {
		return payment;
	}

	return payment + CalculateGeneralPayment(payment, hour - 1);
}

int main(void) {
	const uint32_t kHours = 10 - 1;
	
	for (uint32_t i = 1; i < kHours; i++) {
		uint32_t recursivePayment = CalculateRecursivePayment(100, i - 1);
		uint32_t generalPayment = CalculateGeneralPayment(1072, i - 1);

		std::wcout << i << "時間" << std::endl;
		std::wcout << "一般的な賃金体制 :" << recursivePayment << std::endl;
		std::wcout << "再帰的な賃金体制 :" << generalPayment << std::endl;
	}

	return 0;
}
