/**
 * \file FishDory.h
 *
 * \author Liam Bok
 *
 * This class describes the dory fish.
 */

#include <memory>
#include "Item.h"
#include "Fish.h"

#pragma once

/**
 * Implements the dory fish
 */
class CFishDory :
	public CFish
{
public:
	/// Default constructor (disabled)
	CFishDory() = delete;

	/// Copy constructor (disabled)
	CFishDory(const CFishDory&) = delete;

	/// Aquarium for fish
	CFishDory(CAquarium* aquarium);

	/// Save item to XML node
	virtual std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

};
