#include <iostream>
#include <exception>
#include <string>


class smart_array {
private:
	int A;
	int* arr;
	int curent_index;
public:
	smart_array(const smart_array&) = delete;
	smart_array& operator=(const smart_array&) = delete;
	
	smart_array(int size)
	{
		this->A = size;
		this->arr = new int[A] {};
		this->curent_index = 0;
	}

	void add_element(int element) 
	{
		if (this->curent_index > (A - 1)) 
		{
			throw std::runtime_error("Максимальное значение");
		}

		arr[this->curent_index] = element;
		this->curent_index++;
	}

	int get_element(int index) 
	{
		if ((index < 0) || (index > curent_index)) 
		{
			std::string buf = std::to_string(index);
			throw std::runtime_error("index " + buf + " is out of range");
		}

		return arr[index];
	}

	~smart_array() 
	{
		delete[] this->arr;
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");
	
	try
	{
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(10) << std::endl;
	}
	catch (const std::exception& ex) 
	{
		std::cout << ex.what() << std::endl;
	}
	return 0;
}