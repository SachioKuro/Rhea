#pragma once

#include <cstdint>

namespace mem {
	class StackAllocator {
	private:
		uint32_t m_top = 0;
		uint32_t m_size;
		uint8_t* m_mem;

		uint8_t _pad[3];
	public:
		explicit StackAllocator(uint32_t bytes);
		~StackAllocator();

		void* alloc(uint32_t bytes);

		uint32_t getTopMarker();

		void free(uint32_t pos);
		void free();
	};
}