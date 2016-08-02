#include "stdafx.h"
#include "CppUnitTest.h"
#include "Matrix.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OsuukiSBTests
{
	TEST_CLASS(MatrixTests)
	{
	public:
		
		TEST_METHOD(Brackets_Access)
		{
			// TODO: Your test code here
			Matrix mat(4, 4);
			mat.table = {
				{ 0, 1, 2, 3 },
				{ 4, 5, 6, 7 },
				{ 8, 9, 10, 11 },
				{ 12, 13, 14, 15 }
			};

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					float value = i * 4 + j;
					Assert::AreEqual(value, mat[i][j]);
				}
			}
		}

		TEST_METHOD(Brackets_CompareAgainstTableAccess)
		{
			// TODO: Your test code here
			Matrix mat(4, 4);
			mat.table = {
				{ 0, 1, 2, 3 },
				{ 4, 5, 6, 7 },
				{ 8, 9, 10, 11 },
				{ 12, 13, 14, 15 }
			};

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					Assert::AreEqual(mat.table[i][j], mat[i][j]);
				}
			}
		}

		TEST_METHOD(Multiplication_4x44x4)
		{
			// TODO: Your test code here
			Matrix mat(4, 4);
			mat.table = {
				{ 0, 1, 2, 3 },
				{ 4, 5, 6, 7 },
				{ 8, 9, 10, 11 },
				{ 12, 13, 14, 15 }
			};

			Matrix result(4, 4);
			result.table = {
				{ 56, 62, 68, 74 },
				{ 152, 174, 196, 218 },
				{ 248, 286, 324, 362 },
				{ 344, 398, 452, 506 },
			};

			Matrix mult = mat * mat;

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					Assert::AreEqual(mult[i][j], result[i][j]);
				}
			}
		}

		TEST_METHOD(Multiplication_3x44x3)
		{
			// TODO: Your test code here
			Matrix left(3, 4);
			left.table = {
				{ 0, 1, 2, 3 },
				{ 4, 5, 6, 7 },
				{ 8, 9, 10, 11 }
			};

			Matrix right(4, 3);
			right.table = {
				{ 0, 1, 2 },
				{ 3, 4, 5 }, 
				{ 6, 7, 8 },
				{ 9, 10, 11 }
			};

			Matrix result(3, 3);
			result.table = {
				{ 42, 48, 54 },
				{ 114, 136, 158 },
				{ 186, 224, 262 }
			};

			Matrix mult = left * right;

			Assert::IsTrue(mult == result);
		}

		TEST_METHOD(Equality) {
			Matrix mat = { { 1, 2, 3 },
						   { 4, 5, 6 } };

			Matrix comp(2, 3);
			comp.table = {
				{ 1, 2, 3 },
				{ 4, 5, 6 }
			};

			Assert::AreEqual(mat.rows, 2);
			Assert::AreEqual(mat.columns, 3);
			Assert::IsTrue(mat == comp);
		}

		TEST_METHOD(Constructor_Table) {
			Matrix mat = { { 1, 2, 3 },
						   { 4, 5, 6 } };

			Matrix comp(2, 3);
			comp.table = { 
				{ 1, 2, 3 },
				{ 4, 5, 6 }
			};

			Assert::AreEqual(mat.rows, 2);
			Assert::AreEqual(mat.columns, 3);
			Assert::IsTrue(mat == comp);
		}
	};
}