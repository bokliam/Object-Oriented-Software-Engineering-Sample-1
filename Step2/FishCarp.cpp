/**
 * \file FishCarp.cpp
 *
 * \author Liam Bok
 */


#include "pch.h"
#include <memory>
#include <string>
#include "FishCarp.h"
#include "Aquarium.h"


using namespace Gdiplus;
using namespace std;

/// Fish filename 
const wstring FishCarpImageName = L"images/carp.png";

/// Declare speed range for carp fish
double const MinSpeedX = 5;
double const MaxSpeedX = 40;
double const MinSpeedY = 10;
double const MaxSpeedY = 40;

/** Constructor
* 
* \param aquarium Aquarium this fish is a member of
*/
CFishCarp::CFishCarp(CAquarium* aquarium) :
	CFish(aquarium, FishCarpImageName)
{
	// Create speed for carp fish in specific range
	double mSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	double mSpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);

	// Set speed for carp fish
	SetSpeedX(mSpeedX);
	SetSpeedY(mSpeedY);
};

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishCarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"carp");

	// Save fish speed data
	itemNode->SetAttribute(L"speedx", GetSpeedX());
	itemNode->SetAttribute(L"speedy", GetSpeedY());

	return itemNode;
};
