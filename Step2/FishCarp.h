/**
 * \file FishCarp.h
 *
 * \author Liam Bok
 *
 * This class describes the carp fish.
 */

#include <memory>
#include "Item.h"
#include "Fish.h"

#pragma once

/**
 * Implements the carp fish
 */
class CFishCarp :
	public CFish
{	
public:
	/// Default constructor (disabled)
	CFishCarp() = delete;

	/// Copy constructor (disabled)
	CFishCarp(const CFishCarp&) = delete;

	/// Aquarium for fish
	CFishCarp(CAquarium * aquarium);

	/// Save item to XML node
	virtual std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;


};

