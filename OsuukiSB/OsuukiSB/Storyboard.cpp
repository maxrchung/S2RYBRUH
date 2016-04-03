#include "Storyboard.hpp"
#include <iostream>
#include <fstream>
#include <stddef.h>

Storyboard* Storyboard::instance = NULL;

Storyboard* Storyboard::Instance() {
	if (!instance) {
		instance = new Storyboard;
	}
	return instance;
}

void Storyboard::Write(const std::string& destinationPath) {
	std::cout << destinationPath << std::endl;
	std::ofstream outputFile;
	outputFile.open(destinationPath);

	outputFile << "[Events]" << std::endl;
	outputFile << "//Background and Video events" << std::endl;

	for (int layer = Background; layer < LayerCount; layer++) {
		outputFile << "//Storyboard Layer " << layer << " (" << Layers[layer] << ")" << std::endl;
		for (auto sprite : sprites) {
			if (sprite->layer == layer) {
				sprite->Write(outputFile);
			}
		}
	}

	outputFile << "//Storyboard Sound Samples" << std::endl;
	outputFile.close();
}
