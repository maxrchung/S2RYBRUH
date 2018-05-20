#ifndef LAYER_HPP
#define LAYER_HPP

#include <string>

enum class Layer {
	Background,
	Fail,
	Pass,
	Foreground,
	Count
};

extern std::string Layers[];

#endif//LAYER_HPP