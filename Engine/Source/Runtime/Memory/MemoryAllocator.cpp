#include "stdafx.h"
#include "MemoryAllocator.h"

MemoryAllocator::MemoryAllocator()
	: m_firstMemoryAddress(nullptr)
	, m_memorySize(0)
	, m_memoryUsed(0)
	, m_numMemoryAllocations(0)
{

}

MemoryAllocator::MemoryAllocator(size_t size, void* ptr)
	: m_firstMemoryAddress(ptr)
	, m_memorySize(size)
	, m_memoryUsed(0)
	, m_numMemoryAllocations(0)
{

}

MemoryAllocator::~MemoryAllocator()
{

}
