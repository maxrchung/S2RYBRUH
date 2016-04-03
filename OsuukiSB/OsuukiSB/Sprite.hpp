#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <vector>
#include <string>
#include "Layer.hpp"
#include "Origin.hpp"
#include "Vector2.hpp"
#include "Easing.hpp"
#include <fstream>
#include "Color.hpp"

class Sprite {
public:
	Sprite(const std::string& filePath, Vector2 position, Layer layer = Layer::Foreground, Origin origin = Origin::Centre);
	void Move(int startTime, int endTime, int startX, int startY, int endX, int endY, Easing easing = Easing::Linear);
	void Move(int startTime, int endTime, Vector2 startPos, Vector2 endPos, Easing easing = Easing::Linear);
	void Fade(int startTime, int endTime, float startOpacity, float endOpacity, Easing easing = Easing::Linear);
	void Rotate(int startTime, int endTime, float startRotate, float endRotate, Easing easing = Easing::Linear);
	void Scale(int startTime, int endTime, float startScale, float endScale, Easing easing = Easing::Linear);
	void Color(int startTime, int endTime, int startR, int startG, int startB, int endR, int endG, int endB, Easing easing = Easing::Linear);
	void Color(int startTime, int endTime, ::Color startColor, ::Color endColor, Easing easing = Easing::Linear);

	void Write(std::ofstream& outputFile);
	std::vector<std::string> commands;

	float fade;
	Vector2 position;
	float rotation;
	float scale;
	::Color color;
	// Indicates when the sprite will no longer be on screen
	int endTime;
private:
	Layer layer;
	Origin origin;
	std::string filePath;
};

#endif//SPRITE_HPP
