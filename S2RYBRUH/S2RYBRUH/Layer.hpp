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

static std::string* Layers(){
	static std::string layers[static_cast<int>(Layer::Count)] = {
		"Background",
		"Fail",
		"Pass",
		"Foreground"
	};
	return layers;
}

#endif//LAYER_HPP