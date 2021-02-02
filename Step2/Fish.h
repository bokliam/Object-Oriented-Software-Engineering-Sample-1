/**
 * \file Fish.h
 *
 * \author Liam Bok
 *
 * This class describes fish item functionality
 */

#pragma once
#include "Item.h"
#include "XmlNode.h"

 /**
  * Base class for a fish
  * This applies to all of the fish, but not the decor
  * items in the aquarium.
  */
class CFish :
	public CItem
{
public:

	/// Default constructor (disabled)
	CFish() = delete;

	/// Copy constructor (disabled)
	CFish(const CFish&) = delete;

	/** X value for when fish should reverse
	* \returns X value */
	double ReverseX();
	 
	/** Y value for when fish should reverse
	* \returns Y value */
	double ReverseY();

	/// Setter for fish x speed
	/// \param xSpeed speed in x direction
	void SetSpeedX(double xSpeed) { mSpeedX = xSpeed; };

	/// Setter for fish y speed
	/// \param ySpeed speed in y direction
	void SetSpeedY(double ySpeed) { mSpeedY = ySpeed; };

	/// Getter for fish x speed
	/// \return fish x speed
	double GetSpeedX() { return mSpeedX; };

	/// Getter for fish y speed
	/// \return fish y speed
	double GetSpeedY() { return mSpeedY; };


protected:

	/// Fish constructor
	CFish(CAquarium* aquarium, const std::wstring& filename);

	/// Update fish
	/// \param elapsed Elapsed time
	void Update(double elapsed);

private:

	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;

};
