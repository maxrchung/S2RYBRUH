#include "Storyboard.hpp"
#include <fstream>
#include <iostream>
#include <stddef.h>

std::vector<std::vector<std::unique_ptr<Sprite>>> Storyboard::sprites(static_cast<int>(Layer::Count));

void Storyboard::Clear() {
	sprites.clear();
	for (int i = 0; i < static_cast<int>(Layer::Count); ++i) {
		sprites.push_back(std::vector<std::unique_ptr<Sprite>>());
	}
}

Sprite* Storyboard::CreateSprite(const std::string& filePath, Vector2 position, Layer layer, Origin origin) {
	sprites[static_cast<int>(layer)].push_back(std::make_unique<Sprite>());
	auto const sprite = sprites[static_cast<int>(layer)].back().get();
	sprite->filePath = filePath;
	sprite->position = position;
	sprite->layer = layer;
	sprite->origin = origin;
	sprite->startPosition = Vector2(position.x, -position.y) + Vector2::Midpoint;
	return sprite;
}

void Storyboard::Write(const std::string& destinationPath) {
	std::cout << "Writing to: " << destinationPath << std::endl;
	std::ofstream outputFile;
	outputFile.open(destinationPath);

	outputFile << "[Events]" << std::endl;
	outputFile << "//Background and Video events" << std::endl;

	for (int i = 0; i < static_cast<int>(Layer::Count); ++i) {
		outputFile << "//Storyboard Layer " << i << " (" << Layers()[i] << ")" << std::endl;
		for (const auto& sprite : sprites[i]) {
			// Sprite,<layer>,<origin>,"<filepath>",<x>,<y>
			outputFile << "Sprite," << Layers()[static_cast<int>(sprite->layer)] << "," << Origins()[static_cast<int>(sprite->origin)] << ",\"" << sprite->filePath << "\"," << sprite->startPosition.x << "," << sprite->startPosition.y << std::endl;
			for (const auto& command : sprite->commands) {
				outputFile << command << std::endl;
			}
		}
	}

	outputFile << "//Storyboard Sound Samples" << std::endl;
	outputFile.close();
}
