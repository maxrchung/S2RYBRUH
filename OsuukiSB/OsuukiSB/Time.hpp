#ifndef TIME_HPP
#define TIME_HPP

#include <string>

class Time {
public:
	Time(int value);
	Time(std::string format);
	int milliseconds;
	std::string format;
};

#endif//TIME_HPP