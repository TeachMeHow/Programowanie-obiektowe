//code borrowed from http://stackoverflow.com/questions/1926605/how-to-count-the-number-of-objects-created-in-c - by stefanB
//tracks the number of objects created and alive
#pragma once
template <typename T>
struct counter
{
	counter()
	{
		entries_created++;
		entries_alive++;
	}

	virtual ~counter()
	{
		--entries_alive;
	}
	static int entries_created;
	static int entries_alive;
};
template <typename T> int counter<T>::entries_created(0);
template <typename T> int counter<T>::entries_alive(0);



