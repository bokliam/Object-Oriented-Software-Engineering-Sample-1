/**
 * \file FishBeta.cpp
 *
 * \author Liam Bok
 */

#include "pch.h"
#include <string>
#include <memory>
#include "FishBeta.h"
#include "Aquarium.h"

using namespace Gdiplus;
using namespace std;


/// Fish image filename 
const wstring FishBetaImageName = L"images/beta.png";

/// Declare speed range for beta fish
double const MinSpeedX = 40;
double const MaxSpeedX = 100;
double const MinSpeedY = 0;
double const MaxSpeedY = 25;

 /** Constructor
 * 
 * \param aquarium Aquarium this fish is a member of
 */
CFishBeta::CFishBeta(CAquarium* aquarium) :
	CFish(aquarium, FishBetaImageName)
{
	// Create speed for beta fish in specific range
	double mSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	double mSpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);

	// Set speed for beta fish
	SetSpeedX(mSpeedX);
	SetSpeedY(mSpeedY);
};

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"beta");

	// Save fish speed data
	itemNode->SetAttribute(L"speedx", GetSpeedX());
	itemNode->SetAttribute(L"speedy", GetSpeedY());

	return itemNode;
};




