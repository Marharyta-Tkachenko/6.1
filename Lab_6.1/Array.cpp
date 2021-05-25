#include"Array.h"

Array::Array(const Array::size_type& n)
throw(bad_alloc, invalid_argument)
{
	First = 0;
	Count = Size = n;
	elems = new value_type[Size];
	for (UINT i = 0; i < Size; i++)
		elems[i] = 0;
}

Array::Array(const iterator first, const iterator last) throw(bad_alloc, invalid_argument)
{
	First = 0;
	if (first <= last) {
		Count = Size = (last - first) + 1;
		elems = new value_type[Size];
		for (UINT i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}
Array::Array(const size_type first, const size_type last)
throw(bad_alloc, invalid_argument)
{
	if (first <= last) {
		First = first;
		Count = Size = (last - first) + 1;
		elems = new value_type[Size];
		for (UINT i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}
Array::Array(const Array& t) throw(bad_alloc)
	: Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[Size])
{
	for (UINT i = 0; i < Size; ++i)
		elems[i] = t.elems[i];
}

Array::~Array()
{
	delete[]elems;
	elems = 0;
}

Array& Array::operator = (const Array& t)
{
	Array tmp(t);
	swap(tmp);
	return *this;
}

Array::size_type Array::size() const
{
	return Count;
}

bool Array::empty() const
{
	return Count == 0;
}

Array::size_type Array::capacity() const
{
	return Size;
}

void Array::resize(size_type newsize) throw(bad_alloc)
{
	if (newsize > capacity())
	{
		value_type* data = new value_type[newsize];
		for (size_type i = 0; i < Count; ++i)
			data[i] = elems[i];
		delete[] elems;
		elems = data;
		Size = newsize;
	}
}

Array::reference Array::operator [](size_type index) throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}

Array::const_reference Array::operator [](size_type index) const
throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}

void Array::push_back(const value_type& v)
{
	if (Count == Size)
		resize(Size * 2);
	elems[Count++] = v;
}

Array::value_type Array::pop_back() throw (out_of_range)
{
	if (empty())
		throw out_of_range("Array is empty");
	value_type x = back();
	value_type* tmp = new value_type[size() - 1];
	for (size_t i = 0; i < Count; i++)
		tmp[i] = elems[i];
	delete[] elems;
	elems = tmp;
	Size = size() - 1;
	Count--;
	return x;
}

void Array::swap(Array& other)
{
	std::swap(elems, other.elems);
	std::swap(Size, other.Size);
}

void Array::assign(const value_type& v)
{
	for (size_t i = 0; i < Count; i++)
	{
		elems[i] = v;
	}
}

ostream& operator <<(ostream& out, const Array& a)
{
	for (size_t j = 0; j < a.Count; j++)
		out << a[j] << " ";
	out << endl;
	return out;
}

istream& operator >>(istream& in, Array& a)
{
	for (int i = 0; i < a.Count; i++)
	{
		cout << "elems[" << i << "] = ";
		in >> a[i];
	}
	return in;
}

Array::value_type Array::Sum()
{
	value_type x = 0;
	for (size_t j = 0; j < Count; j++)
		x += elems[j];
	return x;
}

Array::value_type Array::Average_Abs() throw (logic_error)
{
	if (empty())
		throw logic_error("There are no elements");
	value_type x = 0;
	for (size_t j = 0; j < Count; j++)
		x += abs(elems[j]);
	return x / Count;
}

int Array::Max()
{
	int max = elems[0];
	for (size_t i = 1; i < Count; i++)
	{
		if (elems[i] > max)
		{
			max = elems[i];
		}
	}
	return max;
}

void Array::Add()
{
	int max = Max();
	int last = elems[Count - 1];
	for (size_t i = 0; i < Count; i++)
	{
		elems[i] = elems[i] + sqrt(abs(max * last));
	}
}