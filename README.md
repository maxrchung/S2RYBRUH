OsuukiSB is deprecated. Use S2RYBRUH going forwards. 

Sample library usage:
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
// Position (0, 0, 0) is the center of the screen
// +x goes right
// +y goes up
// +z goes towards you
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

// Basic Vector support
Vector2 rotate2 = Vector2(1, 0).Rotate(3.14159f / 2.0f);
// How 3D rotation direction works: 
// 1). Point your index finger at the positive rotation axis. 
// 2). Stick out your thumb out in an L shape. The tip of your thumb is where your point is.
// 3). Rotate your hand clockwise around index finger.
// 4). The tip of your thumb is the rotated position.
Vector3 rotate3 = Vector2(1, 0, 0).RotateY(3.14159f / 2.0f);

// Writing out to file
Storyboard::Write(R"(X:\osu!\Songs\525470 Quarks - Dualive\Quarks - Dualive(niseboi).osb)");

// Basic support for FFT/spectrums is provided by generating music data to a file and then loading from it
// Generating should be done from a separate project so as to reuse the data
#include "MusicAnalysis.hpp"

MusicAnalysisConfig config;
// Music analysis must be performed on single channel WAV
config.musicPath = R"(X:\Music\kradness & Camellia\SDVX Dualive No FX\Quarks_Dualive_SDVX_NOFX - Left Channel.wav)";
// Where to save data
config.dataPath = R"(C:\Users\Wax Chug da Gwad\Desktop\Dualive\Dualive\Debug\MusicAnalysisData.txt)";
// How many frequency divisions
config.divisions = 24;
// Lowest frequency to measure
config.freqBandStart = 50;
// Highest frequency to measure
config.freqBandEnd = 16000;
// How often to record data
config.snapshotRate = 100;
MusicAnalysis anal(config);

// Loading data
MusicAnalysisData data = MusicAnalysis::LoadData(R"(C:\Users\Wax Chug da Gwad\Desktop\Dualive\Dualive\Debug\MusicAnalysisData.txt)");

// Get the scaling for the 1st frequency division at 10 seconds and normalize it between 0 and 100
int measureIndex = data.GetMeasureIndex(Time("00:10:000"));
float barMaxLength =  100.0f;
float barScale = data.scaleData[0][measureIndex] * barMaxLength;
```
