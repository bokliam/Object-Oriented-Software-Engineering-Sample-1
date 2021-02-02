/**
 * \file CAquariumTest.cpp
 *
 * \author Liam Bok
 */

#include "pch.h"
#include <memory>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include "CppUnitTest.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "FishCarp.h"
#include "FishDory.h"
#include "DecorCastle.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

/// Random number seed
const unsigned int RandomSeed = 1238197374;

/**
* Create a path to a place to put temporary files
*/
wstring TempPath()
{
	// Create a path to temporary files
	wchar_t path_nts[MAX_PATH];
	GetTempPath(MAX_PATH, path_nts);

	// Convert null terminated string to wstring
	return wstring(path_nts);
}

/**
* Read a file into a wstring and return it.
* \param filename Name of the file to read
* \return File contents
*/
wstring ReadFile(const wstring& filename)
{
	ifstream t(filename);
	wstring str((istreambuf_iterator<char>(t)),
		istreambuf_iterator<char>());

	return str;
}

/**
* Test to ensure an aquarium .aqua file is empty
*/
void TestEmpty(wstring filename)
{
	Logger::WriteMessage(filename.c_str());

	wstring xml = ReadFile(filename);
	Logger::WriteMessage(xml.c_str());

	Assert::IsTrue(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
	Assert::IsTrue(regex_search(xml, wregex(L"<aqua/>")));

};

/** Populate an aquarium with three Beta fish
*  
* \param aquarium Aquarium pointer
*/
void PopulateThreeBetas(CAquarium* aquarium)
{
	// Used for Save testing speed
	srand(RandomSeed);

	shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(aquarium);
	fish1->SetLocation(100, 200);
	aquarium->Add(fish1);

	shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(aquarium);
	fish2->SetLocation(400, 400);
	aquarium->Add(fish2);

	shared_ptr<CFishBeta> fish3 = make_shared<CFishBeta>(aquarium);
	fish3->SetLocation(600, 100);
	aquarium->Add(fish3);
};


/** Test three betas are saved to xml file
 * 
 * \param filename XML file
 */
void TestThreeBetas(wstring filename)
{
	Logger::WriteMessage(filename.c_str());

	wstring xml = ReadFile(filename);
	Logger::WriteMessage(xml.c_str());

	// Ensure three items
	Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

	// Ensure the positions are correct
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

	// Ensure the types are correct
	Assert::IsTrue(regex_search(xml,
		wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));

	// Test that speed is saved
	Assert::IsTrue(regex_search(xml,
		wregex(L"<item x=\"220\" y=\"398\" speedx=\"44\\.695883.*\" speedy=\"0\"")));
};

/**
*  Populate an aquarium with all types but beta
*/
void PopulateAllTypes(CAquarium* aquarium)
{
	// Used for Save testing speed
	srand(RandomSeed);

	shared_ptr<CFishCarp> fish1 = make_shared<CFishCarp>(aquarium);
	fish1->SetLocation(100, 200);
	aquarium->Add(fish1);

	shared_ptr<CFishDory> fish2 = make_shared<CFishDory>(aquarium);
	fish2->SetLocation(400, 400);
	aquarium->Add(fish2);

	shared_ptr<CDecorCastle> fish3 = make_shared<CDecorCastle>(aquarium);
	fish3->SetLocation(600, 100);
	aquarium->Add(fish3);
};

/** Test all types but betas are saved to xml file
 *
 * \param filename XML file
 */
void TestAllTypes(wstring filename)
{
	Logger::WriteMessage(filename.c_str());

	wstring xml = ReadFile(filename);
	Logger::WriteMessage(xml.c_str());

	// Ensure three items
	Assert::IsTrue(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

	// Ensure the positions are correct
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
	Assert::IsTrue(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

	// Ensure the types are correct
	Assert::IsTrue(regex_search(xml,
		wregex(L"<aqua><item.* type=\"carp\"/><item.* type=\"dory\"/><item.* type=\"castle\"/></aqua>")));

	// Test that speed is saved
	Assert::IsTrue(regex_search(xml,
		wregex(L"<item x=\"100\" y=\"200\" speedx=\"44\\.695883.*\" speedy=\"0\"")));
};


/** Test the aquarium clear function
 * 
 * \param aquarium Aquarium pointer
 */
void TestClear(CAquarium* aquarium)
{
	// Clear aquarium
	aquarium->Clear();

	// Hit test to see that fish is no longer at specific location
	Assert::IsTrue(aquarium->HitTest(100, 200) == nullptr);
};

namespace Testing
{	// Aquarium test class
	TEST_CLASS(CAquariumTest)
	{
	public:
		
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		// Test aquarium constructor
		TEST_METHOD(TestCAquariumConstruct)
		{
			CAquarium aquarium;
		}

		// Aquarium hit test
		TEST_METHOD(TestCAquariumHitTest)
		{
			CAquarium aquarium;

			// Hit test empty aquarium
			Assert::IsTrue(aquarium.HitTest(100, 200) == nullptr,
				L"Testing empty aquarium");

			// Create fish and add to aquarium
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			// Assert that fish is hit
			Assert::IsTrue(aquarium.HitTest(100, 200) == fish1,
				L"Testing fish at 100, 200");

			// Add second fish to see if it is on top of the first fish
			shared_ptr<CFishBeta> fish2 = make_shared<CFishBeta>(&aquarium);
			fish2->SetLocation(100, 200);
			aquarium.Add(fish2);

			/// True if overlapping, False if not
			Assert::IsTrue(aquarium.HitTest(100, 200) == fish2);

			/// Hit test for location where there is no image
			Assert::IsTrue(aquarium.HitTest(50, 150) == nullptr);
		}

		// Test to see if save functionality works
		TEST_METHOD(TestCAquariumSave)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create an aquarium
			CAquarium aquarium;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";
			aquarium.Save(file1);

			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);

			TestThreeBetas(file2);

			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypes(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);

			TestAllTypes(file3);	
		}

		// Test CAquarium clear functionality
		TEST_METHOD(TestCAquariumClear)
		{
			// Create aquarium
			CAquarium aquarium;

			// Add fish to aquarium at specific location
			shared_ptr<CFishBeta> fish1 = make_shared<CFishBeta>(&aquarium);
			fish1->SetLocation(100, 200);
			aquarium.Add(fish1);

			// Call Test Clear function
			TestClear(&aquarium);
		}

		// Test to see that load functionality works
		TEST_METHOD(TestCAquariumLoad)
		{
			// Create a path to temporary files
			wstring path = TempPath();

			// Create two aquariums
			CAquarium aquarium, aquarium2;

			//
			// First test, saving an empty aquarium
			//
			wstring file1 = path + L"test1.aqua";

			aquarium.Save(file1);
			TestEmpty(file1);

			aquarium2.Load(file1);
			aquarium2.Save(file1);
			TestEmpty(file1);

			//
			// Now populate the aquarium
			//

			PopulateThreeBetas(&aquarium);

			wstring file2 = path + L"test2.aqua";
			aquarium.Save(file2);
			TestThreeBetas(file2);

			//
			// Test all types
			//
			CAquarium aquarium3;
			PopulateAllTypes(&aquarium3);

			wstring file3 = path + L"test3.aqua";
			aquarium3.Save(file3);
			TestAllTypes(file3);

			aquarium2.Load(file2);
			aquarium2.Save(file2);
			TestThreeBetas(file2);

			aquarium3.Load(file3);
			aquarium3.Save(file3);
			TestAllTypes(file3);
		}

	};
}