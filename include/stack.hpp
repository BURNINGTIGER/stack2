#include <iostream>
template <typename T>

class stack

{

public:

	void swap(stack<T>&);

	stack();

	~stack();

	stack(const stack<T>&);

	stack<T>& operator=(const stack<T>& other);

	size_t count() const;

	void push(T const &);

	T pop();

	void printall();

	void print();

private:

	T * array_;

	size_t array_size_;

	size_t count_;

};

template <typename T>
void stack<T>::swap(stack<T>& other)
{
	std::swap(array_, other.array_);
	std::swap(array_size_, other.array_size_);
	std::swap(count_, other.count_);
}

template <typename T>
stack<T>::stack()
{
	array_size_ = 0;
	count_ = 0;
	array_ = nullptr;
}

template <typename T>
stack<T>::~stack()
{
	count_ = 0;
	array_size_ = 0;
	delete[] array_;
}

template<typename T>
stack<T>::stack(const stack<T>& other) {
	array_size_ = other.array_size_;
	count_ = other.count_;
	std::copy(other.array_, other.array_ + count_, array_);
}


template<typename T>
stack<T>& stack<T>::operator=(const stack<T>& other)
{
	if (&other != this)
	{
		stack(other).swap(*this);;
	}
	return *this;
}


template <typename T>
void stack<T>::push(T const & value)
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_];
	}
	if (array_size_ == count_)
	{
		array_size_ = array_size_ * 2;
		T * new_array = new T[array_size_]();
		std::copy(array_, array_ + count_, new_array);
		delete[] array_;
		array_ = new_array;
	}
	array_[count_++] = value;
}

template<typename T>
T stack<T>::pop()
{
	if (count_ == 0)
	{
		//throw std::logic_error("Stack is empty");
		/throw "Stack is empty";
	}
	T x = array_[count_ - 1];
	count_--;
	return x;
}

template <typename T>
size_t stack<T>::count() const
{
	return(count_);
}

template<typename T>
void stack<T>::printall()
{
	for (int i = 0; i < count_; i++)
		std::cout << array_[i];
}

template<typename T>
void stack<T>::print()
{
	std::cout << array_[count_ - 1];
}
