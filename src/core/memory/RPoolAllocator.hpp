#pragma once
#include <cstdint>

template <typename T>
class RPoolAllocator {
	union MemUnit {
		T unit;
		MemUnit* next;

		MemUnit() {};
		~MemUnit() {};
	};

public:
	explicit RPoolAllocator(uint32_t n);

	RPoolAllocator(const RPoolAllocator& other) = delete; // Copy Constructor
	RPoolAllocator(const RPoolAllocator&& other) = delete; // Move Constructor
	RPoolAllocator& operator=(const RPoolAllocator& other) = delete; // Copy Assignment
	RPoolAllocator& operator=(const RPoolAllocator&& other) = delete; // Move Assignment

	virtual ~RPoolAllocator();

	virtual T* request();
	virtual void free(T* pObj);
private:
	MemUnit* top;
	MemUnit* mem;
};