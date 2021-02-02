/**
 * \file Fish.cpp
 *
 * \author Liam Bok
 */


#include "pch.h"
#include "Fish.h"
#include "Aquarium.h"


 /// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedX = 50;

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 50;

 /**
  * Constructor
  * \param aquarium The aquarium we are in
  * \param filename Filename for the image we use
  */
CFish::CFish(CAquarium* aquarium, const std::wstring& filename) :
	CItem(aquarium, filename)
{
	mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
	mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedY;
};


/** This function computes the X value for when a fish should reverse
 * 
 * \returns X value for when fish should be reversed
 */
double CFish::ReverseX()
{
	return (1024 - 10 - ((GetWidth()) / 2));
}

/** This function computes the Y value for when a fish should reverse
 * 
 * \returns Y value for when fish should be reversed
 */
double CFish::ReverseY()
{
	return (800 - 10 - ((GetHeight()) / 2));
}

/**
 * Handle updates in time of our fish
 *
 * This is called before we draw and allows us to
 * move our fish. We add our speed times the amount
 * of time that has elapsed.
 * \param elapsed Time elapsed since the class call
 */
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

	if (mSpeedX > 0 && GetX() >= ReverseX())
	{
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}
	if (mSpeedX < 0 && GetX() <= (GetWidth()/2))
	{
		mSpeedX = fabs(mSpeedX);
		SetMirror(mSpeedX < 0);
	}
	if (mSpeedY > 0 && GetY() >= ReverseY())
	{
		mSpeedY = -mSpeedY;
	}
	if (mSpeedY < 0 && GetY() <= (GetHeight()/2))
	{
		mSpeedY = fabs(mSpeedY);
	}
};

