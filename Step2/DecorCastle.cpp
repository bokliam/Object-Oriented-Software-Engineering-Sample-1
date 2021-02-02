/**
 * \file DecorCastle.cpp
 *
 * \author Liam Bok
 */


#include "pch.h"
#include <string>
#include <memory>
#include "DecorCastle.h"
#include "Aquarium.h"

using namespace Gdiplus;
using namespace std;

/// Fish image filename 
const wstring DecorCastleImageName = L"images/castle.png";

/** Constructor
*
* \param aquarium Aquarium this fish is a member of
*/
CDecorCastle::CDecorCastle(CAquarium* aquarium) :
	CItem(aquarium, DecorCastleImageName)
{
};

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 */
std::shared_ptr<xmlnode::CXmlNode>
CDecorCastle::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"castle");
	return itemNode;
};
