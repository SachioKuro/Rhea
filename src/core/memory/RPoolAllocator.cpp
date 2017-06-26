#pragma once

#include "RPoolAllocator.hpp"
#include <cassert>
#include <cstdlib>
#include <memory>

template <typename T>
RPoolAllocator<T>::RPoolAllocator(uint32_t n) {
	assert(n > 0);
	mem = (MemUnit*)malloc(n * sizeof(MemUnit));
	top = mem;

	for (uint32_t i = 0; i < n - 1; ++i)
		mem[i]->next = std::addressof(mem[i + 1]);

	mem[n - 1]->next = nullptr;
}

template <typename T>
RPoolAllocator<T>::~RPoolAllocator() {
	std::free(mem);
}

template <typename T>
T* RPoolAllocator<T>::request() {
	MemUnit* tmp = top;
	T* req = new (top) T;
	top 
}
