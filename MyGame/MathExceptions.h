#pragma once
#include <stdexcept>
class DeterminantIsZeroExcheption : public std::runtime_error
{
public:
	explicit DeterminantIsZeroExcheption(const std::string& message)
		: std::runtime_error(message.c_str())
	{
	}

	explicit DeterminantIsZeroExcheption(const char *message)
		: std::runtime_error(message)
	{
	}
};
