/**
 * \file Aquarium.h
 *
 * \author Liam Bok
 *
 * This class will represent the aquarium.
 */

#include <memory>
#include <vector>
#include "Item.h"

#pragma once

/**
 * This class implements the aquarium.
 */
class CAquarium
{
public:
	/// Aquarium constructor
	CAquarium();

	/// Aquarium destructor
	virtual ~CAquarium();

	/// Draws fish in the aquarium
	void OnDraw(Gdiplus::Graphics* graphics);

	/// Add fish to aquarium
	void Add(std::shared_ptr<CItem> item);

	/// Hit test function
	std::shared_ptr<CItem> HitTest(int x, int y);

	/// Moves fish to front if clicked on
	void MoveToFront(std::shared_ptr<CItem> item);

	/// Save aquarium instance
	void Save(const std::wstring& filename);

	/// Load aquarium instance
	void Load(const std::wstring& filename);

	/// Clear old data out of aquarium
	void Clear();

	/// Updates for animation
	void Update(double elapsed);

	/// Get the width of the aquarium
	/// \returns Aquarium width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mBackground->GetHeight(); }

private:

	/// Handles item tags of node
	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;
};

