#include "stdafx.h"
#include "CppUnitTest.h"
#include "Time.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OsuukiSBTests {
	TEST_CLASS(TimeTests) {
	public:
		TEST_METHOD(NewTimeFormatEqualsFormatBasic) {
			Time time = Time(120000);
			std::string format = "02:00:000";
			// TODO: Your test code here
			Assert::AreEqual(time.format, format);
		}

		TEST_METHOD(NewTimeFormatEqualsFormatBasic2) {
			Time time = Time(123456);
			std::string format = "02:03:456";
			// TODO: Your test code here
			Assert::AreEqual(time.format, format);
		}

		TEST_METHOD(NewTimeFormatEqualsFormatBasic3) {
			Time time = Time(666);
			std::string format = "00:00:666";
			// TODO: Your test code here
			Assert::AreEqual(time.format, format);
		}

		TEST_METHOD(NewTimeFormatEqualsFormatMin) {
			Time time = Time(0);
			std::string format = "00:00:000";
			Assert::AreEqual(time.format, format);
		}

		TEST_METHOD(NewTimeFormatEqualsFormatMax) {
			Time time = Time(5999999);
			std::string format = "99:59:999";
			Assert::AreEqual(time.format, format);
		}

		TEST_METHOD(NewTimemsEqualsmsBasic) {
			Time time = Time("12:34:567");
			int ms = 754567;
			Assert::AreEqual(ms, time.ms);
		}

		TEST_METHOD(NewTimemsEqualsmsMax) {
			Time time = Time("99:59:999");
			int ms = 5999999;
			Assert::AreEqual(ms, time.ms);
		}

		TEST_METHOD(NewTimemsEqualsmsMin) {
			Time time = Time("00:00:000");
			int ms = 0;
			Assert::AreEqual(ms, time.ms);
		}

		TEST_METHOD(NewTimeParamsEqualParamsFormat) {
			std::string format = "69:69:420";
			Time time = Time(format);
			Assert::AreEqual(format, time.format);
		}

		TEST_METHOD(NewTimeParamsEqualParamsms) {
			int ms = 69420;
			Time time = Time(69420);
			Assert::AreEqual(ms, time.ms);
		}
	};
}