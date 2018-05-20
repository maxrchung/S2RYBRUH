#pragma once

#include "Sprite.hpp"
#include <memory>
#include <vector>
#include <string>

class Storyboard {
public:
	static void Clear();
	static Sprite* CreateSprite(const std::string& filePath, Vector2 position = Vector2::Zero, Layer layer = Layer::Foreground, Origin origin = Origin::Centre);
	static void Write(const std::string& destinationPath = "");
	// Represents each layer of sprites
	static std::vector<std::vector<std::unique_ptr<Sprite>>> sprites;
private:
	Storyboard() {};
	Storyboard(const Storyboard&) {};
	Storyboard& operator=(const Storyboard&) {};
};