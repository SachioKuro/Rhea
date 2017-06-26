#pragma once

#include <cstdint>

namespace mem {
	class PoolAllocator {
	private:
		uint32_t m_obj_size;
		uint32_t m_obj_count;
		uint32_t m_free_index;
		uint8_t** m_pointer;
		uint8_t* m_mem;
		uint8_t _pad[2];
	public:
		explicit PoolAllocator(uint32_t obj_size, uint32_t obj_count);
		~PoolAllocator();
		void* get();
		void free(void* mem);
	};
}