/**
 * \file CFishBetaTest.cpp
 *
 * \author Liam Bok
 */

#include "pch.h"
#include "CppUnitTest.h"
#include "FishBeta.h"
#include "Aquarium.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	// Beta fish test class
	TEST_CLASS(CFishBetaTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		// Test beta fish constructor
		TEST_METHOD(TestCFishBetaConstruct)
		{
			CAquarium aquarium;
			CFishBeta fish(&aquarium);
		}


	};
}