#ifndef BUFFER_H
#define BUFFER_H

// Standard Library Includes
#include <stdexcept>
#include <cstring>
#include <iostream>

/*
* @brief The Buffer class is the Class used to create buffers of different types
* 
* - Uses templates to create buffers of all different types
* - Can be Static or Dynamic
* - Extremely flexible
*/
template <typename T>
class Buffer
{
public: 
	/*
	* @brief Constructor for Buffer.
	* @param size_t cap - Initial Capacity of the Buffer. Default is 512
	* @param bool isResizeable - Must be True for Dynamic array. Default is false
	*
	* The Constructor which takes in an Capacity (size_t) and Resizable (bool) to create a Dynamic array.
	*/
	Buffer(size_t cap=512, bool isResizable = false);

	/*
	* @brief Destructor for Buffer
	* 
	* The destructor which clears the buffer, removing the data from the array and setting the pointer to null.
	* Only happens if the array and data pointer is initialised.
	*/
	~Buffer();

	// Getters 
	/*
	* @brief Returns a raw pointer to the buffer array of the buffer data type
	* @returns T* data - Pointer to data array
	*/
	T* getData();

	/*
	* @brief Returns a constant pointer for read only access to the buffer
	* @returns const T* data - Constant pointer to data array
	*/
	const T* getData() const;

	/*
	* @brief Returns the capacity of the Buffer as a size_t
	* @returns size_t capacity - Capacity of the Buffer
	*/
	size_t getCapacity() const;


	/* 
	* @brief Clears the buffer setting all values to the default value of T (can be int, float, or char)
	* 
	* Fills the buffer with the default data value of the chosen buffer type
	*/
	void clear();

	/*
	* @brief Resizes the buffer is the buffer is resizeable
	* @param size_t expectedCap - The capacity rises by 50% till it exceeds the expected capacity
	* 
	* Checks if the buffer is resizeable. If so allows you to resize the buffer.
	*/
	void resize(size_t expectedCap); // Resize the buffer

private:
	T* data; // Pointer to array

	size_t capacity; // Capacity of Array
	bool isResizable; // Static or Dynamic Array (Proper dynamic functionality not added)
};

#endif // BUFFER_H