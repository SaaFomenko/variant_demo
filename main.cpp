#include <iostream>
#include <vector>
#include <algorithm>
#include <variant>


std::variant<int, std::string, std::vector<int>> get_variant() {
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main()
{
	auto var = get_variant();

	bool is_int = std::holds_alternative<int>(var);
	bool is_string = std::holds_alternative<std::string>(var);
	bool is_array = std::holds_alternative<std::vector<int>>(var);

	if (is_int)
	{
		std::cout << (var * 2) << std::endl;

		return 0;
	}

	if (is_string)
	{
		std::cout << var << std::endl;

		return 0;
	}

	if (is_array)
	{
		std::for_each(
				var.begin(),
				var.end(),
				[](int& i)
				{
					std::cout << i << ' ';
				}
				);
		std::cout << std::endl;

		return 0;
	}

	return 1;
}
