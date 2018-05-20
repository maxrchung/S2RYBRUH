#include "Storyboard.hpp"
#include <fstream>
#include <iostream>
#include <stddef.h>

 std::vector<std::vector<Sprite>> Storyboard::sprites;

void Storyboard::Clear() {
	sprites.clear();
	for (int i = 0; i < static_cast<int>(Layer::Count); ++i) {
		sprites.push_back(std::vector<Sprite>());
	}
}

Sprite& Storyboard::CreateSprite(const std::string& filePath, Vector2 position, Layer layer, Origin origin) {
	auto sprite = Sprite(filePath, position, layer, origin);
	sprites[static_cast<int>(layer)].push_back(sprite);
	return sprites[static_cast<int>(layer)].back();
}

void Storyboard::Write(const std::string& destinationPath) {
	std::cout << "Writing to: " << destinationPath << std::endl;
	std::ofstream outputFile;
	outputFile.open(destinationPath);

	outputFile << "[Events]" << std::endl;
	outputFile << "//Background and Video events" << std::endl;

	for (int i = 0; i < static_cast<int>(Layer::Count); ++i) {
		outputFile << "//Storyboard Layer " << i << " (" << Layers[i] << ")" << std::endl;
		for (auto sprite : sprites[i]) {
			// Sprite,<layer>,<origin>,"<filepath>",<x>,<y>
			outputFile << "Sprite," << Layers[static_cast<int>(sprite.layer)] << "," << Origins[static_cast<int>(sprite.origin)] << ",\"" << sprite.filePath << "\"," << sprite.startPosition.x << "," << sprite.startPosition.y << std::endl;
			for (auto command : sprite.commands) {
				outputFile << command << std::endl;
			}
		}
	}

	outputFile << "//Storyboard Sound Samples" << std::endl;
	outputFile.close();
}
