/**
 * \file DecorCastle.h
 *
 * \author Liam Bok
 *
 * This class implements the castle decor for the aquarium.
 */


#pragma once
#include "Item.h"


/** This class describes the castle decor for aquarium
 * 
 */
class CDecorCastle :
	public CItem
{
public:

	/// Default constructor (disabled)
	CDecorCastle() = delete;

	/// Copy constructor (disabled)
	CDecorCastle(const CDecorCastle&) = delete;

	/// Aquarium for fish
	CDecorCastle(CAquarium* aquarium);
	
	/// Save item to XML node
	std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};

