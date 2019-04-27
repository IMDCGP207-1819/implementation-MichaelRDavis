#include "stdafx.h"
#include "MemoryAllocator.h"

MemoryAllocator::MemoryAllocator()
	: m_size(0)
	, m_firstAddress(nullptr)
	, m_usedSize(0)
	, m_numAllocations(0)
{

}

MemoryAllocator::MemoryAllocator(size_t inSize, void* ptr)
	: m_size(inSize)
	, m_firstAddress(ptr)
	, m_usedSize(0)
	, m_numAllocations(0)
{

}

MemoryAllocator::~MemoryAllocator()
{

}
