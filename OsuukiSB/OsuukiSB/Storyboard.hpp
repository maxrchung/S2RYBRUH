#ifndef STORYBOARD_HPP
#define STORYBOARD_HPP

#include "Sprite.hpp"
#include <vector>
#include <string>

class Storyboard {
public:
	static Storyboard* Instance();
	void Write(const std::string& destinationPath);
	std::vector<Sprite*> sprites;
private:
	Storyboard() {};
	Storyboard(const Storyboard&) {};
	Storyboard& operator=(const Storyboard&) {};
	static Storyboard* instance;
};

#endif//STORYBOARDP_HPP