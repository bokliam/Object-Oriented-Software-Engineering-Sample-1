/**
 * \file FishBeta.h
 *
 * \author Liam Bok
 *
 * This class describes the beta fish.
 */

#include <memory>
#include "Item.h"
#include "Fish.h"

#pragma once

/**
 * Implements a Beta fish
 */
class CFishBeta :
	public CFish
{
public:
	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta&) = delete;

	/// Aquarium for fish
	CFishBeta(CAquarium* aquarium);

	/// Save item to XML node
	virtual std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;


};