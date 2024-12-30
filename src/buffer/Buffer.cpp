#include "buffer/Buffer.h"
#include <iostream>

Buffer::Buffer(size_t cap)
	: capacity(cap)
{
	data = new char[capacity];
	for (size_t i = 0; i < capacity; i++) // Initialise the buffer with null characters
	{
		data[i] = '\0';
	}

	std::cout << "Setup: Buffer has been initialised with a capacity of " << capacity << std::endl;
}

Buffer::~Buffer()
{
	if (data) // Making sure Data was properly initialised before attempting to delete
	{
		delete[] data;
		data = nullptr; // Prevent dangling pointer
		std::cout << "Closing: Buffer with capacity of " << capacity << " has been deleted" << std::endl;
	}
}

// Getters
char* Buffer::getData()
{
	return data; 
}

const char* Buffer::getData() const
{
	return data;
}

size_t Buffer::getCapacity() const
{
	return capacity;
}

// Member Function
void Buffer::clear()
{
	if (data)
	{
		for (size_t i = 0; i < capacity; i++) // Reset the Buffer
		{
			data[i] = '\0';
		}
	}
}