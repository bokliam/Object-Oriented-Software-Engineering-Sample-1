/**
 * \file FishDory.cpp
 *
 * \author Liam Bok
 */


#include "pch.h"
#include <memory>
#include <string>
#include "FishDory.h"
#include "Aquarium.h"


using namespace Gdiplus;
using namespace std;

/// Fish filename 
const wstring FishDoryImageName = L"images/dory.png";

/// Declare speed range for dory fish
double const MinSpeedX = 80;
double const MaxSpeedX = 150;
double const MinSpeedY = 0;
double const MaxSpeedY = 100;

/** Constructor
* 
* \param aquarium Aquarium this fish is a member of
*/
CFishDory::CFishDory(CAquarium* aquarium) :
	CFish(aquarium, FishDoryImageName)
{
	// Create speed for dory fish in specific range
	double mSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	double mSpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);

	// Set speed for dory fish
	SetSpeedX(mSpeedX);
	SetSpeedY(mSpeedY);
};

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishDory::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"dory");

	// Save fish speed data
	itemNode->SetAttribute(L"speedx", GetSpeedX());
	itemNode->SetAttribute(L"speedy", GetSpeedY());

	return itemNode;
};

