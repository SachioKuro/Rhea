#pragma once

#include <cstdint>

namespace mem {
	class DoubleEndedStackAllocator {
	private:
		uint32_t m_bottom_end = 0;
		uint32_t m_top_end = 0;
		uint32_t m_size;
		uint8_t* m_mem;

		uint8_t _pad[3];
	public:
		explicit DoubleEndedStackAllocator(uint32_t bytes);
		~DoubleEndedStackAllocator();

		void* allocBottom(uint32_t bytes);
		void* allocTop(uint32_t bytes);

		uint32_t getBottomMarker();
		uint32_t getTopMarker();

		void freeBottom(uint32_t pos);
		void freeBottom();
		void freeTop(uint32_t pos);
		void freeTop();
		void free();
	};
}