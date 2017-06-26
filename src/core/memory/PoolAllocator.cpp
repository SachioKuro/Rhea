#include "PoolAllocator.hpp"
#include <cassert>
#include <cstdlib>

namespace mem {
	PoolAllocator::PoolAllocator(uint32_t obj_size, uint32_t obj_count) : m_obj_size(obj_size), m_obj_count(obj_count) {
		assert(obj_size > 0 && obj_count > 0);

		m_mem = (uint8_t*)malloc(obj_size * obj_count);
		m_pointer = (uint8_t**)malloc(obj_count);

		for (uint32_t i = 0; i < obj_count; i++)
			*(m_pointer + i) = m_mem + i * obj_size;

		m_free_index = obj_count;
	}

	PoolAllocator::~PoolAllocator() {
		std::free(m_pointer);
		std::free(m_mem);
	}

	void* PoolAllocator::get() {
		if (m_free_index != 0)
			return m_pointer[m_free_index-- - 1];
		else
			return NULL;
	}

	void PoolAllocator::free(void* mem) {
		m_pointer[++m_free_index - 1] = (uint8_t*)mem;
	}
}