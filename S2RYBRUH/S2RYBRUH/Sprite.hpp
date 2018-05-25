#pragma once

#include "Color.hpp"
#include "Easing.hpp"
#include "Layer.hpp"
#include "Origin.hpp"
#include "Vector2.hpp"
#include <fstream>
#include <string>
#include <vector>

class Sprite {
public:
	Sprite() {};
	void Move(int startTime, int endTime, float startX, float startY, float endX, float endY, Easing easing = Easing::Linear);
	void Move(int startTime, int endTime, Vector2 startPos, Vector2 endPos, Easing easing = Easing::Linear);
	void MoveX(int startTime, int endTime, float startX, float endX, Easing easing = Easing::Linear);
	void MoveY(int startTime, int endTime, float startY, float endY, Easing easing = Easing::Linear);
	void Fade(int startTime, int endTime, float startOpacity, float endOpacity, Easing easing = Easing::Linear);
	void Rotate(int startTime, int endTime, float startRotate, float endRotate, Easing easing = Easing::Linear, int precision = 3);
	void Scale(int startTime, int endTime, float startScale, float endScale, Easing easing = Easing::Linear, int precision = 3);
	void ScaleVector(int startTime, int endTime, float startX, float startY, float endX, float endY, Easing easing = Easing::Linear, int precision = 3);
	void ScaleVector(int startTime, int endTime, Vector2 startScale, Vector2 endScale, Easing easing = Easing::Linear, int precision = 3);
	void Color(int startTime, int endTime, int startR, int startG, int startB, int endR, int endG, int endB, Easing easing = Easing::Linear, int precision = 3);
	void Color(int startTime, int endTime, ::Color startColor, ::Color endColor, Easing easing = Easing::Linear, int precision = 3);
	void Loop(int startTime, int loopCount, const std::vector<std::string>& loopCommands);

	std::vector<std::string> commands;
	float fade = 1.0f;
	Vector2 position;
	// This is needed for part of the Sprite header writing
	// Only this and Move need to have the weird coordinate mismatch
	Vector2 startPosition;
	float rotation = 0.0f;
	float scale = 1.0f;
	::Color color = Color::Color(255);
	Vector2 scaleVector = Vector2(1.0f, 1.0f);
	// Indicates when the sprite will no longer be on screen
	int endTime;
	Layer layer;
	Origin origin;
	std::string filePath;
};