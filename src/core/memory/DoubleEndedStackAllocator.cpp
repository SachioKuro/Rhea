#include "DoubleEndedStackAllocator.hpp"
#include <cassert>
#include <cstdlib>

namespace mem {
	DoubleEndedStackAllocator::DoubleEndedStackAllocator(uint32_t bytes) : m_size(bytes) {
		assert(bytes > 0);
		m_mem = (uint8_t*)malloc(bytes);
	}

	DoubleEndedStackAllocator::~DoubleEndedStackAllocator() {
		std::free(m_mem);
	}

	void* DoubleEndedStackAllocator::allocBottom(uint32_t bytes) {
		assert(m_size >= bytes + m_bottom_end + m_top_end);
		uint8_t* p = m_mem + m_bottom_end;
		m_bottom_end += bytes;
		return p;
	}

	void* DoubleEndedStackAllocator::allocTop(uint32_t bytes) {
		assert(m_size >= bytes + m_bottom_end + m_top_end);
		uint8_t* p = m_mem + m_size - m_top_end - bytes;
		m_top_end += bytes;
		return p;
	}

	uint32_t DoubleEndedStackAllocator::getBottomMarker() {
		return m_bottom_end;
	}

	uint32_t DoubleEndedStackAllocator::getTopMarker() {
		return m_top_end;
	}

	void DoubleEndedStackAllocator::freeBottom(uint32_t pos) {
		assert(pos <= m_bottom_end && pos >= 0);
		m_bottom_end = pos;
	}

	void DoubleEndedStackAllocator::freeBottom() {
		m_bottom_end = 0;
	}

	void DoubleEndedStackAllocator::freeTop(uint32_t pos) {
		assert(pos <= m_top_end && pos >= 0);
		m_top_end = pos;
	}

	void DoubleEndedStackAllocator::freeTop() {
		m_top_end = 0;
	}

	void DoubleEndedStackAllocator::free() {
		m_bottom_end = m_top_end = 0;
	}
}