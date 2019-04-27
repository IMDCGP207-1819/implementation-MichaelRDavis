#pragma once

namespace Memory
{

}

/**
 * Base memory allocator class.
 */
class MemoryAllocator
{
public:
	/** Default constructor. */
	MemoryAllocator();

	/** Constructor. */
	MemoryAllocator(size_t inSize, void* ptr);

	/** Default destructor. */
	~MemoryAllocator();

	/**  */
	virtual void* Allocate(size_t* inSize, uint8_t alignment) = 0;

	/**  */
	virtual void Free(void * ptr) = 0;

	/**  */
	virtual void Clear() = 0;

protected:
	/** Size of the memory in bytes. */
	size_t m_size;

	/** Pointer to the first memory address. */
	void* m_firstAddress;

	/** Size of the memory used in bytes. */
	size_t m_usedSize;

	/** Number of memory allocations. */
	uint64_t m_numAllocations;
};