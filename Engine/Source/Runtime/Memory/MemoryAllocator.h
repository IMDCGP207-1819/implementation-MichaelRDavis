#pragma once

namespace Memory
{
	/** Returns an aligned memory address. */
	static inline void* AlignForward(void* address, uint8_t alignment)
	{
		return (void*)((reinterpret_cast<uintptr_t>(address) + static_cast<uintptr_t>(alignment - 1))& static_cast<uintptr_t>(~(alignment - 1)));
	}
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
	MemoryAllocator(size_t size, void* ptr);

	/** Default destructor. */
	~MemoryAllocator();

	/** Allocate memory. */
	virtual void* Allocate(size_t* size, uint8_t alignment) = 0;

	/** Free a specifically allocated memory address memory. */
	virtual void Free(void* ptr) = 0;

	/** Clear all allocated memory. */
	virtual void Clear() = 0;

protected:
	/** Pointer to the first memory address. */
	void* m_firstMemoryAddress;

	/** Size of the memory in bytes. */
	size_t m_memorySize;

	/** Size of the memory used in bytes. */
	size_t m_memoryUsed;

	/** Number of memory allocations. */
	uint64_t m_numMemoryAllocations;
};