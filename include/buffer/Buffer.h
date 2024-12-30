#ifndef BUFFER_H
#define BUFFER_H

class Buffer
{
public: 
	// Creating a Explicit constructor (Read https://www.ibm.com/docs/en/xl-c-and-cpp-aix/16.1?topic=only-explicit-conversion-constructors-c & https://medium.com/@python-javascript-php-html-css/understanding-the-explicit-keyword-in-c-326c057c0e1b)
	explicit Buffer(size_t cap); 
	~Buffer();

	// Getters 
	char* getData(); // Get Raw point to data
	const char* getData() const; // Get a constant raw pointer (Read only access [Useful for Output Buffer])
	size_t getCapacity() const; // Get Buffer capacity


	void clear(); // Clear the buffer

private:
	char* data;
	size_t capacity;
};

#endif // BUFFER_H