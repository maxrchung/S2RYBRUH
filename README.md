OsuukiSB is deprecated, please use S2RYBRUH. Sample usage:

```cpp
#include "Storyboard.hpp"
#include "Time.hpp"

// Creating Sprite
Sprite* sprite = Storyboard::CreateSprite("image.png", Vector2::Zero, Layer::Foreground, Origin::Centre);
sprite = Storyboard::CreateSprite("image.png", Vector2::Zero, Layer::Background);
sprite = Storyboard::CreateSprite("image.png", Vector2::Zero);
sprite = Storyboard::CreateSprite("image.png");

// Calling Sprite command
// Basic commands: Move, MoveX, MoveY, Fade, Rotate, Scale, ScaleVector, Color
// Position (0,0,0) is the center of the screen, with positive-x going right, positive-y going up, and positive-z going towards you
sprite->Move(0, 10000, Vector2::Zero, Vector2(100.0f, 100.0f), Easing::Linear);
sprite->Move(0, 10000, 0.0f, 0.0f, 100.0f, 100.0f, Easing::Linear);
sprite->Move(0, 10000, 0.0f, 0.0f, 100.0f, 100.0f);
// Use of Time class for string conversion
sprite->Move(Time("00:00:000").ms, Time("00:10:000").ms, 0.0f, 0.0f, 100.0f, 100.0f);
// Rotations are clock-wise and in radians
// The last parameter is precision, how many numbers to keep after the decimal
sprite->Rotate(0, 10000, 0, 3.14159f, Easing::Linear, 3);
sprite->Rotate(0, 10000, 0, 3.14159f, Easing::Linear);
sprite->Rotate(0, 10000, 0, 3.14159f);

// Writing out to file
Storyboard::Write(R"(X:\osu!\Songs\525470 Quarks - Dualive\Quarks - Dualive(niseboi).osb)");
```
