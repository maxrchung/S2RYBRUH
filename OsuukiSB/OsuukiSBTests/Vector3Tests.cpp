#include "stdafx.h"
#include "CppUnitTest.h"
#include "Vector3.hpp"

const float PI = 3.1415927f;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OsuukiSBTests {
	TEST_CLASS(Vector3Tests) {
	public:
		TEST_METHOD(RotateX_010_00N1) {
			Vector3 vec(0, 1, 0);
			Vector3 rot = vec.RotateX(-PI / 2);
			Assert::AreEqual(rot.z, -1.0f);
		}

		TEST_METHOD(RotateX_010_001) {
			Vector3 vec(0, 1, 0);
			Vector3 rot = vec.RotateX(PI / 2);
			Assert::AreEqual(rot.z, 1.0f);
		}

		TEST_METHOD(RotateY_100_001) {
			Vector3 vec(1, 0, 0);
			Vector3 rot = vec.RotateY(PI / 2);
			Assert::AreEqual(rot.z, -1.0f);
		}

		TEST_METHOD(RotateZ_010_N100) {
			Vector3 vec(0, 1, 0);
			Vector3 rot = vec.RotateZ(PI / 2);
			Assert::AreEqual(rot.x, -1.0f);
		}
	};
}