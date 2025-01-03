#include "buffer/Buffer.h"

template <typename T>
Buffer<T>::Buffer(size_t cap, bool isResizable)
	: capacity(cap), isResizable(isResizable) // Initialiser List
{
	data = new T[capacity]();	// Heap allocation of an array with all elements value-initialised
								// Types include: char -> '\0' and int/float -> 0

	std::cout << "Setup: " << (isResizable ? "Dynamic" : "Static") <<  " Buffer has been initialised with a capacity of " << capacity << std::endl;
}

template <typename T>
Buffer<T>::~Buffer()
{
	if (data)	// Ensuring data was initialised before attempting to delete it
	{
		delete[] data; // Deleting (deallocating) the array
		data = nullptr; // Prevent dangling pointer
		std::cout << "Closing: Buffer with capacity of " << capacity << " has been deleted" << std::endl;
	}
}

// Getters
template <typename T>
T* Buffer<T>::getData()
{
	return data;	// Return raw pointer to data
}

template <typename T>
const T* Buffer<T>::getData() const
{
	return data;	// Return constant raw pointer for read only access to data
}

template <typename T>
size_t Buffer<T>::getCapacity() const
{
	return capacity; // Return capacity
}

// Member Function
template <typename T>
void Buffer<T>::clear()
{
	if (!data)	// Ensuring data was initalised before trying to clear the data within
	{
		throw std::runtime_error("Buffer is not initialised");
	}

	for (size_t i = 0; i < capacity; i++)	// Fill the data starting from first to last index with default constructor of type (T)
	{
		data[i] = T();
	}
}

template <typename T>
void Buffer<T>::resize(size_t expectedCap)
{
	if (capacity > expectedCap)
	{
		throw std::invalid_argument("Capacity is already greater than expected capacity");	// Throw an Invalid Argument Error
	}

	if (!isResizable) // Check if the Buffer is Resizable
	{
		throw std::runtime_error("Resize not allowed for Static Buffer");	// Throw a Runtime Error
	}

	if (expectedCap <= 0)
	{
		throw std::invalid_argument("Expected Capacity must be greater than 0");	// Throw an Invalid Argument Error
	}

	size_t newCap = capacity;

	// Increase the Capacity until big enough to hold expectedCap
	while (newCap < expectedCap)
	{
		// Making sure newCap does not exceed the limit of a size_t value (Even though should be impossible within the application. It should still be accounted for.
		if (newCap > std::numeric_limits<size_t>::max() / 1.5) { // Checking if the value is large enough that increasing it by 50% would exceed the maximum size of size_t
			throw std::overflow_error("Capacity exceeds maximum allowed size");
		}
		newCap = static_cast<size_t>(newCap * 1.5); // (50% increase to make sure it is not passed massively) Static Cast to ensure proper conversions as 1.5 is a double
	}

	// Create new Array for Data
	T* newData = new T[newCap];

	// Copy existing values to the new buffer
	size_t elementsToCopy = (newCap < capacity) ? newCap : capacity; // Find the minium of the new and old caps
	std::memcpy(newData, data, (elementsToCopy * sizeof(T))); // Copy only the initialised elements of the old buffer to the new one

	// Free up old data and assign to new Data
	delete[] data;
	data = newData;
	capacity = newCap;

	std::cout << "Settings: Dynamic Buffer resized to " << capacity << std::endl;
}

// Explicit Template instantiations for the types needed in the Application
// Without these the Class cannot properly link
template class Buffer<char>;
template class Buffer<float>;
template class Buffer<int>;