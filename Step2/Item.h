/**
 * \file Item.h
 *
 * \author Liam Bok
 *
 * This class will describe any item added to the aquarium.
 */


#pragma once

#include <memory>
#include <string>
#include "XmlNode.h"

 /**
  * The aquarium class is used by the CItem class
  */
class CAquarium;

/**
 * This class implements all items added to the aquarium
 */
class CItem
{
public:

	/// Destructor
	virtual ~CItem();

	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;

	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mX; };

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; };

	/** The width of the item
	* \returns width value in pixels */
	double GetWidth() const { return mItemImage->GetWidth(); };

	/** The height of the item
	* \returns height value in pixels */
	double GetHeight() const { return mItemImage->GetHeight(); };

	/// CAquarium getter
	/// \returns Aquarium pointer
	CAquarium* GetAquarium() const { return mAquarium; };

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; };

	/// Draw this item
	/// \param graphics Graphics device to draw on
	void Draw(Gdiplus::Graphics* graphics);

	/// Tell what type an item is
	virtual std::shared_ptr<xmlnode::CXmlNode> 
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Load attributes for item node
	void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Test item to see if it has been clicked on
	bool HitTest(int x, int y);

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/// Set the mirror status
	/// \param m New mirror flag
	void SetMirror(bool m) { mMirror = m; }

protected:
	/// Item added to aquarium
	CItem(CAquarium* aquarium, const std::wstring& filename);

private:

	/// Member variables of item location in the aquarium
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

	/// The aquarium this item is contained in
	CAquarium* mAquarium;

	/// The image of this fish
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;

	bool mMirror = false;   ///< True mirrors the item image
};

