#include <iostream>
#include "Serializer.hpp"

int main() {
	Data originalData;
	originalData.id = 42;
	originalData.name = "42 Student Project";
	originalData.value = 3.14159;

	std::cout << "Original Data address: " << &originalData << std::endl;
	std::cout << "Data ID:    " << originalData.id << std::endl;
	std::cout << "Data Name:  " << originalData.name << std::endl;
	std::cout << "Data Value: " << originalData.value << std::endl;

	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "\nSerialized raw value: 0x" << std::hex << raw << std::dec << std::endl;

	Data* restoredPtr = Serializer::deserialize(raw);
	std::cout << "\nRestored Data address: " << restoredPtr << std::endl;
	std::cout << "Restored ID:    " << restoredPtr->id << std::endl;
	std::cout << "Restored Name:  " << restoredPtr->name << std::endl;
	std::cout << "Restored Value: " << restoredPtr->value << std::endl;

	if (restoredPtr == &originalData) {
		std::cout << "\nSUCCESS: Pointers match 100%!" << std::endl;
	} else {
		std::cout << "\nERROR: Pointer mismatch!" << std::endl;
	}

	return 0;
}
