#include "StackAllocator.hpp"
#include <cassert>
#include <cstdlib>

namespace mem {
	StackAllocator::StackAllocator(uint32_t bytes) : m_size(bytes) {
		assert(bytes > 0);
		m_mem = (uint8_t*)malloc(bytes);
		m_top = 0;
	}

	StackAllocator::~StackAllocator() {
		std::free(m_mem);
	}

	void* StackAllocator::alloc(uint32_t bytes) {
		assert(m_size >= bytes + m_top);
		uint8_t* p = m_mem + m_top;
		m_top += bytes;
		return p;
	}

	uint32_t StackAllocator::getTopMarker() {
		return m_top;
	}

	void StackAllocator::free(uint32_t pos) {
		assert(pos <= m_top && pos >= 0);
		m_top = pos;
	}

	void StackAllocator::free() {
		m_top = 0;
	}
}