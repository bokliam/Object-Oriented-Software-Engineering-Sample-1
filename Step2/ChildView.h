/**
 * \file ChildView.h
 *
 * \author Liam Bok
 *
 * Class that implements the child window our program draws in.
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */

#include "Aquarium.h"

#pragma once

 /**
  * The child window our program draws in.
  */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

private:
	/// An object that describes our aquarium
	CAquarium  mAquarium;

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:

	/// True until the first time we draw
	bool mFirstDraw = true;

	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates

public:
	afx_msg void OnAddfishBetafish();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnAddfishCarpfish();
	afx_msg void OnAddfishDoryfish();
	afx_msg void OnAddDecorCastle();
	afx_msg void OnFileSaveAs();
	afx_msg void OnFileOpen();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

