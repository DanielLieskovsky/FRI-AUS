#include "vector.h"
#include "../utils.h"
#include <cstdlib>
#include <cstring>

namespace structures
{
	Vector::Vector(size_t size) :
		memory_(std::calloc(size, 1)),
		size_(size)
	{	
	}

	Vector::Vector(Vector& other) :
		Vector(other.size_)
	{
		//TODO 01: Vector
		memcpy(memory_, other.memory_, other.size_);
		// throw std::runtime_error("Vector::Vector: Not implemented yet.");
	}

	Vector::~Vector()
	{
		//TODO 01: Vector
		free(memory_);
		memory_ = nullptr;
		size_ = 0;
	}

	size_t Vector::size()
	{
		return size_;
	}

	Structure& Vector::assign(Structure& other)
	{
		// priradujem ak vektor nie je identicky s other 
		//TODO 01: Vector , priradit  size, realokovat memory a prekopirovat prvky

		if (this != &other) {
			Vector& otherVector = dynamic_cast<Vector&>(other); 
			size_ = otherVector.size_;
			memory_ = realloc(memory_, size_);
			memcpy(memory_, otherVector.memory_, size_);
		}

		return *this;
		//throw std::runtime_error("Vector::assign: Not implemented yet.");
	}

	bool Vector::equals(Structure& other)
	{
		//rovnake objekty odkazuju na to iste pamatove miesto
		//TODO 01: Vector

		if (this == &other) {
			return true;
		}
		else {
			Vector* otherVector = dynamic_cast<Vector*>(&other); //vrati aj nullptr kvoli *
			if (otherVector != nullptr) {
				return size_ == otherVector->size_ && memcmp(memory_, otherVector->memory_, size_) == 0;
			}
			else {
				return false;
			}
		}
		throw std::runtime_error("Vector::equals: Not implemented yet.");
	}

	byte& Vector::operator[](int index)
	{
		return at(index);
	}

	byte& Vector::at(int index)
	{
		//TODO 01: Vector
		Utils::rangeCheckExcept(index, size_, "Invalid Index!");
		return *(reinterpret_cast<byte*>(memory_) + index);
		//throw std::runtime_error("Vector::at: Not implemented yet.");
	}

	void Vector::copy(Vector& src, int srcStartIndex, Vector& dest, int destStartIndex, int length)
	{
		//TODO 01: Vector
		// srcStartIndex musi patrit do <0, src.size)
		// destStartIndex musi patrit do <0, dest.size)
		// srcStartIndex + length musi byt <= src.size
		// destStartIndex + length musi byt <= dest.size

		// ak su vektory identicke a vzdialenost medzi src a destStartIndex < lenght tak memmove inak memcpy

		Utils::rangeCheckExcept(srcStartIndex, src.size_, "Invalid srcStartIndex!");
		Utils::rangeCheckExcept(destStartIndex, dest.size_, "Invalid destStartIndex!");
		Utils::rangeCheckExcept(srcStartIndex + length, src.size_ + 1, "Invalid srcStartIndex + length!");
		Utils::rangeCheckExcept(destStartIndex + length, dest.size_ + 1, "Invalid destStartIndex + length!");

		//test identity
		
		if (&src == &dest && abs(srcStartIndex - destStartIndex) < length) {
			memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		} 
		else {
			memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
		//throw std::runtime_error("Vector::copy: Not implemented yet.");
	}

	byte* Vector::getBytePointer(int index)
	{
		//TODO 01: Vector
		Utils::rangeCheckExcept(index, size_, "Invalid Index!");
		return reinterpret_cast<byte*>(memory_) + index;
		//throw std::runtime_error("Vector::getBytePointer: Not implemented yet.");
	}
}