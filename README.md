OsuukiSB is deprecated, currently moving everything to the new S2RYBRUH library. Some sample usage:

```cpp
// Creating Sprite
Sprite* sprite = Storyboard::CreateSprite("image.png", Vector2(0.0f,0.0f), Layer::Background, Origin::Centre);

// Calling Sprite command
sprite->Move(0, 10000, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f), Easing::BounceInOut);

// Writing out to file
Storyboard::Write(R"(X:\osu!\Songs\525470 Quarks - Dualive\Quarks - Dualive(niseboi).osb)");
```
