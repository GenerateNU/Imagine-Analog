#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

class DistortionVolApp : public CWinApp
{
public:
	DistortionVolApp();

protected:
	virtual BOOL InitInstance();

private:
	DECLARE_MESSAGE_MAP()
};

extern DistortionVolApp theApp;