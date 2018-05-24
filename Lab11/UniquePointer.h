#pragma once

#include <iostream>


template <typename T> class UniquePointer
{
public:
	/*friend std::ostream& operator <<(std::ostream &ouput, const UniquePointer<T> &pointer)
	{
		return ouput<<"[pointing to "<<pointer.UP_pointer<<"]";
	}*/

	UniquePointer(T *pointer)
	:UP_pointer(pointer)
	{

	};

	UniquePointer(const UniquePointer<T> &pointer)
	{	
		//delete UP_pointer;
		/*UP_pointer = pointer.UP_pointer;
		const_cast <UniquePointer&>(pointer).UP_pointer = NULL;*/
		
		
	};
	UniquePointer(UniquePointer<T> &pointer);

	T& operator*() const;
	/*{
		return *UP_pointer;
	}*/

	UniquePointer<T>& operator = (const UniquePointer<T>& pointer);
	/*{
		if(const_cast <UniquePointer&>(pointer).UP_pointer != UP_pointer)
		{
			delete UP_pointer;
			UP_pointer = pointer.UP_pointer;
			const_cast <UniquePointer&>(pointer).UP_pointer = NULL;
			//pointer.UP_pointer = NULL;
		}
		return *this;
	}*/

	operator T* ();
	/*{
		return UP_pointer;
	}*/

	T* Get() const;
	/*{
		return UP_pointer;
	}*/

	~UniquePointer();
	/*{
		if(UP_pointer != NULL) delete UP_pointer;
		UP_pointer = NULL;

	}*/

	


private:

	T* UP_pointer;


};


template <typename T> std::ostream & operator <<(std::ostream &output, const UniquePointer<T> &pointer)
{
	return output <<"[pointing to "<<pointer.Get()<<"]";
}